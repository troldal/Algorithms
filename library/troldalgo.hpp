/*
 *
████████╗██████╗  ██████╗ ██╗     ██████╗  █████╗ ██╗      ██████╗  ██████╗
╚══██╔══╝██╔══██╗██╔═══██╗██║     ██╔══██╗██╔══██╗██║     ██╔════╝ ██╔═══██╗
   ██║   ██████╔╝██║   ██║██║     ██║  ██║███████║██║     ██║  ███╗██║   ██║
   ██║   ██╔══██╗██║   ██║██║     ██║  ██║██╔══██║██║     ██║   ██║██║   ██║
   ██║   ██║  ██║╚██████╔╝███████╗██████╔╝██║  ██║███████╗╚██████╔╝╚██████╔╝
   ╚═╝   ╚═╝  ╚═╝ ╚═════╝ ╚══════╝╚═════╝ ╚═╝  ╚═╝╚══════╝ ╚═════╝  ╚═════╝

MIT License

Copyright (c) 2019 Kenneth Troldal Balslev

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
 */

#ifndef TROLDALGO
#define TROLDALGO

#include <iostream>
#include <vector>
#include <list>
#include <thread>
#include <future>
#include <iterator>
#include <functional>
#include <queue>
#include <algorithm>

namespace trl
{

    // ===== TEMPLATE ALIAS DEFINITIONS

    /**
     * @brief An alias template used to determine the iterator_category of an iterator.
     */
    template<typename Iter>
    using IteratorCategory =
    typename std::iterator_traits<Iter>::iterator_category;

    /**
     * @brief An alias template to determine if an iterator is a random_access_iterator
     */
    template<typename Iter>
    using IsRandomAccessIterator =
    std::is_same<IteratorCategory<Iter>, std::random_access_iterator_tag>;

    // ===== GENERIC FIND/SEARCH ALGORITHMS

    /**
     * @brief Finds all elements of a given value in a container, in the range [first, last).
     * @details This algorithm is a wrapper around the std::find algorithm. It simply calls std::find on the provided
     * container, until all elements have been found, or until the last element has been reached.
     * #### Example
     * The following example will find all occurrences of the letter 'A' in a given string. It will find four items at
     * position 0, 7, 8 and 15. Iterators to those elements will be copied to the results vector.
     *   @code{.cpp}
     *      auto str = std::string("ABCDDCBAABCDDCBAX");
     *      std::vector<decltype(str.begin())> results;
            trl::find_all(str.begin(),str.end(), std::back_inserter(results), 'A');
     *   @endcode
     * @tparam InputIt The type of the input iterator parameters. InputIt will be auto-deducted by the compiler.
     * @tparam OutputIt The type of the output iterator of the output container. OutputIt will be auto-deducted by the compiler.
     * @tparam T The type of the value to find. T will be auto-deducted by the compiler.
     * @param first The first element in the range to examine.
     * @param last One element beyond the last element in the range to examine.
     * @param d_first An output iterator pointing to the first element to fill in the output container.
     * @param value The value to find.
     * @return An output iterator pointing to one element beyond the last element of the output container.
     * @throws Undefined find_all itself does not throw. However, std::find is not marked noexcept, so it might throw,
     * but documentation does not reveal any details.
     */
    template<typename InputIt, typename OutputIt, typename T>
    OutputIt find_all(InputIt first,
                      InputIt last,
                      OutputIt d_first,
                      const T& value) {
        while (first != last) {
            first = std::find(first, last, value);
            if (first != last)
                *(d_first++) = first++;
        }

        return d_first;
    }

    /**
     * @brief Finds all elements that satisfies a certain criteria (using a predicate) in the range [first, last) of a container.
     * @details This algorithm is a wrapper around the std::find_if algorithm. It simply calls std::find_if on the provided
     * container, until all elements have been found, or until the last element has been reached.
     * #### Example
     * The following example will find all occurrences of the letter 'A' in a given string. It will find four items at
     * position 0, 7, 8 and 15. Iterators to those elements will be copied to the results vector.
     *   @code{.cpp}
     *      auto str = std::string("ABCDDCBAABCDDCBAX");
     *      std::vector<decltype(str.begin())> results;
            trl::find_all_if(str.begin(),str.end(), std::back_inserter(results), [](char c) {return c == 'A';});
     *   @endcode
     * @tparam InputIt The type of the input iterator parameters. InputIt will be auto-deducted by the compiler.
     * @tparam OutputIt The type of the output iterator of the output container. OutputIt will be auto-deducted by the compiler.
     * @tparam UnaryPredicate The type of the predicate function. UnaryPredicate will be auto-deducted by the compiler.
     * @param first The first element in the range to examine.
     * @param last One element beyond the last element in the range to examine.
     * @param d_first An output iterator pointing to the first element to fill in the output container.
     * @param p A unary predicate which returns ​true for the required element.
     * @return An output iterator pointing to one element beyond the last element of the output container.
     * @throws Undefined find_all_if itself does not throw. However, std::find_if is not marked noexcept, so it might throw,
     * but documentation does not reveal any details.
     */
    template<typename InputIt, typename OutputIt, typename UnaryPredicate>
    OutputIt find_all_if(InputIt first,
                         InputIt last,
                         OutputIt d_first,
                         UnaryPredicate p) {
        while (first != last) {
            first = std::find_if(first, last, p);
            if (first != last)
                *(d_first++) = first++;
        }

        return d_first;
    }

    /**
     * @brief Finds all elements that does NOT satisfy a certain criteria (using a predicate) in the range [first, last) of a container.
     * @details This algorithm is a wrapper around the std::find_if_not algorithm. It simply calls std::find_if_not on the provided
     * container, until all elements have been found, or until the last element has been reached.
     * #### Example
     * The following example will find all occurrences of letters not equaling 'A' in a given string. It will find 13 items at
     * position 1, 2, 3, 4, 5, 6, 9, 10, 11, 12, 13, 14 and 16. Iterators to those elements will be copied to the results vector.
     *   @code{.cpp}
     *      auto str = std::string("ABCDDCBAABCDDCBAX");
     *      std::vector<decltype(str.begin())> results;
     *      trl::find_all_if_not(str.begin(),str.end(), std::back_inserter(results), [](char c) {return c == 'A';});
     *   @endcode
     * @tparam InputIt The type of the input iterator parameters. InputIt will be auto-deducted by the compiler.
     * @tparam OutputIt The type of the output iterator of the output container. OutputIt will be auto-deducted by the compiler.
     * @tparam UnaryPredicate The type of the predicate function. UnaryPredicate will be auto-deducted by the compiler.
     * @param first The first element in the range to examine.
     * @param last One element beyond the last element in the range to examine.
     * @param d_first An output iterator pointing to the first element to fill in the output container.
     * @param p A unary predicate which returns ​true for the required element.
     * @return An output iterator pointing to one element beyond the last element of the output container.
     * @throws Undefined find_all_if_not itself does not throw. However, std::find_if_not is not marked noexcept, so it might throw,
     * but documentation does not reveal any details.
     */
    template<typename InputIt, typename OutputIt, typename UnaryPredicate>
    OutputIt find_all_if_not(InputIt first,
                             InputIt last,
                             OutputIt d_first,
                             UnaryPredicate p) {
        while (first != last) {
            first = std::find_if_not(first, last, p);
            if (first != last)
                *(d_first++) = first++;
        }

        return d_first;
    }

    /**
     * @brief Finds the first elements that does NOT satisfy any of the given search elements, in the range [first, last) of a container.
     * @details This algorithm is a wrapper around the std::find_if and std::find algorithm.
     * #### Example
     * The following example will find the first occurrence of a letter not equaling 'A' or 'B' in a given string. It will find
     * it as index 2. An Iterator to the element will be returned.
     *   @code{.cpp}
     *      auto str = std::string("ABCDDCBAABCDDCBAX");
     *      auto src = std::string("AB");
     *      trl::find_first_not_of(str.begin(),str.end(), src.begin(), src.end());
     *   @endcode
     * @tparam ForwardIt1 The type of the input iterator parameters. ForwardIt1 will be auto-deducted by the compiler.
     * @tparam ForwardIt2 The type of the search iterator parameters. ForwardIt2 will be auto-deducted by the compiler.
     * @param first The first element in the range to examine.
     * @param last One element beyond the last element in the range to examine.
     * @param s_first The first element in the range of elements to search for.
     * @param s_last One element beyond the last element in the range to search for.
     * @return An iterator pointing to the element found; if none has been found, \c last will be returned.
     * @throws Undefined std::find_if and std::find does not throw. However, they is not marked noexcept, so they might throw,
     * but documentation does not reveal any details.
     */
    template<typename ForwardIt1, typename ForwardIt2>
    ForwardIt1 find_first_not_of(ForwardIt1 first,
                                 ForwardIt1 last,
                                 ForwardIt2 s_first,
                                 ForwardIt2 s_last) {

        return std::find_if(first, last, [&](const decltype(*first)& val) {
            return (std::find(s_first, s_last, val) == s_last);
        });
    }

    // TODO: Implement trl::find_first_not_of with predicates.

//    /**
//     * @brief
//     * @tparam InputIt
//     * @tparam ForwardIt
//     * @tparam BinaryPredicate
//     * @param first
//     * @param last
//     * @param s_first
//     * @param s_last
//     * @param p
//     * @return
//     */
//    template<typename InputIt, typename ForwardIt, typename BinaryPredicate>
//    constexpr InputIt find_first_not_of(InputIt first,
//                                        InputIt last,
//                                        ForwardIt s_first,
//                                        ForwardIt s_last,
//                                        BinaryPredicate p) {
//        return std::find_if(first, last, [&](const decltype(*first)& val) {
//            return (std::find_if(s_first, s_last, !p) == s_last);
//        });
//    }


    /**
     * @brief Finds all elements of a given range of value in a container, in the range [first, last).
     * @details This algorithm is a wrapper around the std::find_first_of algorithm. It simply calls std::find_first_of
     * on the provided container, until all elements have been found, or until the last element has been reached.
     * #### Example
     * The following example will find all occurrences of the letters {'A', 'B'} in a given string. It will find eight items at
     * position 0, 1, 6, 7, 8, 9, 14 and 15. Iterators to those elements will be copied to the results vector.
     *   @code{.cpp}
     *      auto str = std::string("ABCDDCBAABCDDCBAX");
     *      auto src = std::string("AB");
     *      std::vector<decltype(str.begin())> results;
            trl::find_all_of(str.begin(),str.end(), src.begin(), src.end(), std::back_inserter(results));
     *   @endcode
     * @tparam ForwardIt1 The type of the input iterator parameters. ForwardIt1 will be auto-deducted by the compiler.
     * @tparam ForwardIt2 The type of the search iterator parameters. ForwardIt2 will be auto-deducted by the compiler.
     * @tparam OutputIt The type of the output iterator of the output container. OutputIt will be auto-deducted by the compiler.
     * @param first The first element in the range to examine.
     * @param last One element beyond the last element in the range to examine.
     * @param s_first The first element in the search range.
     * @param s_last The last element in the search range.
     * @param d_first An output iterator pointing to the first element to fill in the output container.
     * @return An output iterator pointing to one element beyond the last element of the output container.
     * @throws Undefined find_all itself does not throw. However, std::find is not marked noexcept, so it might throw,
     * but documentation does not reveal any details.
     */
    template<typename ForwardIt1, typename ForwardIt2, typename OutputIt>
    OutputIt find_all_of(ForwardIt1 first,
                         ForwardIt1 last,
                         ForwardIt2 s_first,
                         ForwardIt2 s_last,
                         OutputIt d_first) {
        while (first != last) {
            first = std::find_first_of(first, last, s_first, s_last);
            if (first != last) {
                *(d_first++) = first;
                first++;
            }
        }

        return d_first;
    }

    /**
     * @brief Finds all elements of a given range of value in a container, in the range [first, last), using a predicate.
     * @details This algorithm is a wrapper around the std::find_first_of algorithm. It simply calls std::find_first_of
     * on the provided container, until all elements have been found, or until the last element has been reached.
     * #### Example
     * The following example will find all occurrences of the letters {'A', 'B'} in a given string. It will find eight items at
     * position 0, 1, 6, 7, 8, 9, 14 and 15. Iterators to those elements will be copied to the results vector.
     *   @code{.cpp}
     *      auto str = std::string("ABCDDCBAABCDDCBAX");
     *      auto src = std::string("AB");
     *      std::vector<decltype(str.begin())> results;
            trl::find_all_of(str.begin(),str.end(), src.begin(), src.end(), std::back_inserter(results), [](const char& a, const char& b) { return a == b; });
     *   @endcode
     * @tparam ForwardIt1 The type of the input iterator parameters. ForwardIt1 will be auto-deducted by the compiler.
     * @tparam ForwardIt2 The type of the search iterator parameters. ForwardIt2 will be auto-deducted by the compiler.
     * @tparam OutputIt The type of the output iterator of the output container. OutputIt will be auto-deducted by the compiler.
     * @tparam BinaryPredicate A binary predicate which returns ​true if the elements should be treated as equal.
     * @param first The first element in the range to examine.
     * @param last One element beyond the last element in the range to examine.
     * @param s_first The first element in the search range.
     * @param s_last The last element in the search range.
     * @param d_first An output iterator pointing to the first element to fill in the output container.
     * @param p A binary predicate which returns ​true if the elements should be treated as equal.
     * @return An output iterator pointing to one element beyond the last element of the output container.
     * @throws Undefined find_all itself does not throw. However, std::find is not marked noexcept, so it might throw,
     * but documentation does not reveal any details.
     */
    template<typename ForwardIt1, typename ForwardIt2, typename OutputIt, typename BinaryPredicate>
    OutputIt find_all_of(ForwardIt1 first,
                         ForwardIt1 last,
                         ForwardIt2 s_first,
                         ForwardIt2 s_last,
                         OutputIt d_first,
                         BinaryPredicate p) {
        while (first != last) {
            first = std::find_first_of(first, last, s_first, s_last, p);
            if (first != last) {
                *(d_first++) = first;
                first++;
            }
        }

        return d_first;
    }

    /**
     * @brief Finds all elements NOT in a given range of values in a container, in the range [first, last).
     * @details This algorithm is a wrapper around the trl::find_first_not_of algorithm. It simply calls trl::find_first_not_of
     * on the provided container, until all elements have been found, or until the last element has been reached.
     * #### Example
     * The following example will find all occurrences NOT equal to the letters {'A', 'B'} in a given string. It will find
     * nine items at position 2,3,4,5,10,11,12,13 and 16. Iterators to those elements will be copied to the results vector.
     *   @code{.cpp}
     *      auto str = std::string("ABCDDCBAABCDDCBAX");
     *      auto src = std::string("AB");
     *      std::vector<decltype(str.begin())> results;
            trl::find_all_of(std::execution::par, str.begin(),str.end(), src.begin(), src.end(), std::back_inserter(results));
     *   @endcode
     * @tparam ForwardIt1 The type of the input iterator parameters. ForwardIt1 will be auto-deducted by the compiler.
     * @tparam ForwardIt2 The type of the search iterator parameters. ForwardIt2 will be auto-deducted by the compiler.
     * @tparam OutputIt The type of the output iterator of the output container. OutputIt will be auto-deducted by the compiler.
     * @param first The first element in the range to examine.
     * @param last One element beyond the last element in the range to examine.
     * @param s_first The first element in the search range.
     * @param s_last The last element in the search range.
     * @param d_first An output iterator pointing to the first element to fill in the output container.
     * @return An output iterator pointing to one element beyond the last element of the output container.
     * @throws Undefined find_all itself does not throw. However, std::find is not marked noexcept, so it might throw,
     * but documentation does not reveal any details.
     */
    template<typename ForwardIt1, typename ForwardIt2, typename OutputIt>
    OutputIt find_all_not_of(ForwardIt1 first,
                             ForwardIt1 last,
                             ForwardIt2 s_first,
                             ForwardIt2 s_last,
                             OutputIt d_first) {
        while (first != last) {
            first = find_first_not_of(first, last, s_first, s_last);
            if (first != last) {
                *(d_first++) = first;
                first++;
            }
        }

        return d_first;
    }

    // TODO: Implement trl::find_all_not_of with predicates

    /**
     * @brief Search for all non-overlapping occurrences of a sequence of values in a container, in the range [first, last).
     * @details This algorithm is a wrapper around the std::search algorithm. It simply calls std::search
     * on the provided container, until all occurrences have been found, or until the last element has been reached.
     * #### Example
     * The following example will find all occurrences of the sequence "HELLO" in a given string. It will find
     * two items at position 2 and 9. Iterators to those elements will be copied to the results vector.
     *   @code{.cpp}
     *      auto str = std::string("ABHELLOAAHELLOBAX");
     *      auto src = std::string("HELLO");
     *      std::vector<decltype(str.begin())> results;
            trl::find_all_of(str.begin(),str.end(), src.begin(), src.end(), std::back_inserter(results));
     *   @endcode
     * @tparam ForwardIt1 The type of the input iterator parameters. ForwardIt1 will be auto-deducted by the compiler.
     * @tparam ForwardIt2 The type of the search iterator parameters. ForwardIt2 will be auto-deducted by the compiler.
     * @tparam OutputIt The type of the output iterator of the output container. OutputIt will be auto-deducted by the compiler.
     * @param first The first element in the range to examine.
     * @param last One element beyond the last element in the range to examine.
     * @param s_first The first element in the search range.
     * @param s_last The last element in the search range.
     * @param d_first An output iterator pointing to the first element to fill in the output container.
     * @return An output iterator pointing to one element beyond the last element of the output container.
     * @throws Undefined find_all itself does not throw. However, std::find is not marked noexcept, so it might throw,
     * but documentation does not reveal any details.
     */
    template<typename ForwardIt1, typename ForwardIt2, typename OutputIt>
    OutputIt search_all(ForwardIt1 first,
                        ForwardIt1 last,
                        ForwardIt2 s_first,
                        ForwardIt2 s_last,
                        OutputIt d_first) {
        while (first != last) {
            first = std::search(first, last, s_first, s_last);
            if (first != last) {
                *(d_first++) = first;
                std::advance(first, std::distance(s_first, s_last));
            }
        }

        return d_first;
    }

    /**
     * @brief Search for all non-overlapping occurrences of a sequence of values in a container, in the range [first, last), using a predicate.
     * @details This algorithm is a wrapper around the std::search algorithm. It simply calls std::search
     * on the provided container, until all occurrences have been found, or until the last element has been reached.
     * #### Example
     * The following example will find all occurrences of the sequence "HELLO" in a given string. It will find
     * two items at position 2 and 9. Iterators to those elements will be copied to the results vector.
     *   @code{.cpp}
     *      auto str = std::string("ABHELLOAAHELLOBAX");
     *      auto src = std::string("HELLO");
     *      std::vector<decltype(str.begin())> results;
            trl::find_all_of(str.begin(),str.end(), src.begin(), src.end(), std::back_inserter(results), [&](const char& a, const char& b) { return a == b; });
     *   @endcode
     * @tparam ForwardIt1 The type of the input iterator parameters. ForwardIt1 will be auto-deducted by the compiler.
     * @tparam ForwardIt2 The type of the search iterator parameters. ForwardIt2 will be auto-deducted by the compiler.
     * @tparam OutputIt The type of the output iterator of the output container. OutputIt will be auto-deducted by the compiler.
     * @tparam BinaryPredicate A binary predicate which returns ​true if the elements should be treated as equal.
     * @param first The first element in the range to examine.
     * @param last One element beyond the last element in the range to examine.
     * @param s_first The first element in the search range.
     * @param s_last The last element in the search range.
     * @param d_first An output iterator pointing to the first element to fill in the output container.
     * @param p A binary predicate which returns ​true if the elements should be treated as equal.
     * @return An output iterator pointing to one element beyond the last element of the output container.
     * @throws Undefined find_all itself does not throw. However, std::find is not marked noexcept, so it might throw,
     * but documentation does not reveal any details.
     */
    template<typename ForwardIt1, typename ForwardIt2, typename OutputIt, typename BinaryPredicate>
    OutputIt search_all(ForwardIt1 first,
                        ForwardIt1 last,
                        ForwardIt2 s_first,
                        ForwardIt2 s_last,
                        OutputIt d_first,
                        BinaryPredicate p) {
        while (first != last) {
            first = std::search(first, last, s_first, s_last, p);
            if (first != last) {
                *(d_first++) = first;
                std::advance(first, std::distance(s_first, s_last));
            }
        }

        return d_first;
    }

    // TODO: Implement trl::search_all with option for using different searchers (see: https://en.cppreference.com/w/cpp/algorithm/search)

    // ===== SPLITTING ALGORITHM

    /**
     * @brief
     * @tparam ElemType
     */
    template<typename ElemType>
    class ByElement
    {
    public:

        /**
         * @brief
         * @param element
         */
        explicit ByElement(const ElemType& element) : m_element(element) {}

        /**
         * @brief
         * @tparam RandomAccessIter
         * @param begin
         * @param end
         * @return
         */
        template<typename RandomAccessIter>
        auto Find(RandomAccessIter begin,
                  RandomAccessIter end) {

            std::vector<RandomAccessIter> locations;
            find_all(begin, end, std::back_inserter(locations), m_element);
            return locations;
        }

        constexpr size_t Length() const {
            return 1;
        }

    private:
        const ElemType& m_element;
    };

    /**
     * @brief
     * @tparam SequenceType
     */
    template<typename SequenceType>
    class BySequence
    {
    public:

        /**
         * @brief
         * @param sequence
         */
        explicit BySequence(const SequenceType& sequence) : m_sequence(sequence) {
            static_assert(IsRandomAccessIterator<typename SequenceType::iterator>::value,
                          "Delimiter is not a sequence container!");
        }

        /**
         * @brief
         * @tparam RandomAccessIter
         * @param begin
         * @param end
         * @return
         */
        template<typename RandomAccessIter>
        auto Find(RandomAccessIter begin,
                  RandomAccessIter end) {

            std::vector<RandomAccessIter> locations;
            search_all(begin, end, m_sequence.begin(), m_sequence.end(), std::back_inserter(locations));
            return locations;
        }

        constexpr size_t Length() const {
            return m_sequence.size();
        }

    private:
        const SequenceType& m_sequence;
    };

    /**
     * @brief
     * @tparam SequenceType
     */
    template<typename SequenceType>
    class ByAnyElement
    {
    public:
        explicit ByAnyElement(const SequenceType& sequence) : m_sequence(sequence) {
            static_assert(IsRandomAccessIterator<typename SequenceType::iterator>::value,
                          "Delimiter is not a sequence container!");
        }

        template<typename RandomAccessIter>
        auto Find(RandomAccessIter begin,
                  RandomAccessIter end) {

            std::vector<RandomAccessIter> locations;
            find_all_of(begin, end, m_sequence.begin(), m_sequence.end(), std::back_inserter(locations));
            return locations;
        }

        constexpr size_t Length() const {
            return 1;
        }

    private:
        const SequenceType& m_sequence;
    };

    /**
     * @brief
     */
    class ByLength
    {
    public:

        /**
         * @brief
         * @param length
         */
        explicit ByLength(std::ptrdiff_t length) : m_length(length) {}

        /**
         * @brief
         * @tparam RandomAccessIter
         * @param begin
         * @param end
         * @return
         */
        template<typename RandomAccessIter>
        auto Find(RandomAccessIter begin,
                  RandomAccessIter end) {

            std::vector<RandomAccessIter> locations;
            while (std::distance(begin, end) > m_length) {
                std::advance(begin, m_length);
                locations.emplace_back(begin);
            }

            return locations;
        }

        constexpr size_t Length() const {
            return 0;
        }

    private:
        const std::ptrdiff_t m_length;
    };

    /**
     * @brief Split a container into sub-containers, using a given delimiter
     * @tparam Container The container type to be split. This will be auto-deduced by the compiler.
     * @tparam OutputIt The type of output iterator used for output of sub-containers. This will be auto-deduced by the compiler.
     * @tparam DelimiterType The type of delimiter. This will be auto-deduced by the compiler.
     * @param container The container to split.
     * @param destination An output iterator to the destination container.
     * @param delimiter The delimiter object to use.
     */
    template<typename Container, typename OutputIt, typename DelimiterType>
    void split(Container container,
               OutputIt destination,
               DelimiterType delimiter) {

        static_assert(IsRandomAccessIterator<typename Container::iterator>::value,
                      "Input container is not sequential!");

        auto locations = delimiter.Find(container.begin(), container.end());
        *std::back_inserter(locations) = container.end();

        auto first = container.begin();

        for (auto last : locations) {
            Container result; // TODO: This is ineffecient, but when creating Container in-place, the code won't compile.
            std::copy(first, last, std::back_inserter(result));
            *(destination++) = result;
            first = last + delimiter.Length();
        }
    }
}  // namespace trl


#endif //TROLDALGO
