#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <catch.hpp>
#include <troldalgo.hpp>
#include <string>
#include <vector>
#include <array>
#include <set>
#include <unordered_set>
#include <type_traits>

//#if defined(__GNUC__) && !defined(__clang__)
#if defined(_MSC_VER)
    #include <execution>
#endif

template<typename T>
struct CaseDef
{
    std::string      case_title;
    std::vector<T>   array;
    T                search_item;
    std::vector<int> item_locations;
};

template<typename T>
void fill_char(T& target, const std::vector<char>& source) {

    if constexpr (std::is_same<T, std::multiset<char>>::value){
        for (auto c : source) target.insert(c);
    }
    else if constexpr (std::is_same<T, std::unordered_multiset<char>>::value){
        for (auto c : source) target.insert(c);
    }
    else {
        std::copy(source.begin(), source.end(), std::back_inserter(target));
    }
}

auto create_find_all_cases() {

    CaseDef<char> CaseDef1;
    CaseDef1.case_title = "Find all 'A's in the container";
    CaseDef1.array = {'A','B','C','D','D','C','B','A','A','B','C','D','D','C','B','A','X'};
    CaseDef1.search_item = 'A';
    CaseDef1.item_locations = {0, 7, 8, 15};

    CaseDef<char> CaseDef2;
    CaseDef2.case_title = "Find all 'B's in the container";
    CaseDef2.array = {'A','B','C','D','D','C','B','A','A','B','C','D','D','C','B','A','X'};
    CaseDef2.search_item = 'B';
    CaseDef2.item_locations = {1, 6, 9, 14};

    CaseDef<char> CaseDef3;
    CaseDef3.case_title = "Find all 'C's in the container";
    CaseDef3.array = {'A','B','C','D','D','C','B','A','A','B','C','D','D','C','B','A','X'};
    CaseDef3.search_item = 'C';
    CaseDef3.item_locations = {2, 5, 10, 13};

    CaseDef<char> CaseDef4;
    CaseDef4.case_title = "Find all 'D's in the container";
    CaseDef4.array = {'A','B','C','D','D','C','B','A','A','B','C','D','D','C','B','A','X'};
    CaseDef4.search_item = 'D';
    CaseDef4.item_locations = {3, 4, 11, 12};

    CaseDef<char> CaseDef5;
    CaseDef5.case_title = "Find all 'X's in the container";
    CaseDef5.array = {'A','B','C','D','D','C','B','A','A','B','C','D','D','C','B','A','X'};
    CaseDef5.search_item = 'X';
    CaseDef5.item_locations = {16};

    CaseDef<char> CaseDef6;
    CaseDef6.case_title = "Find all 'Z's in the container";
    CaseDef6.array = {'A','B','C','D','D','C','B','A','A','B','C','D','D','C','B','A','X'};
    CaseDef6.search_item = 'Z';
    CaseDef6.item_locations = {};

    CaseDef<char> CaseDef7;
    CaseDef7.case_title = "Find all 'Z's in an empty container";
    CaseDef7.array = {};
    CaseDef7.search_item = 'Z';
    CaseDef7.item_locations = {};

    std::vector<CaseDef<char>> cases;
    cases.emplace_back(CaseDef1);
    cases.emplace_back(CaseDef2);
    cases.emplace_back(CaseDef3);
    cases.emplace_back(CaseDef4);
    cases.emplace_back(CaseDef5);
    cases.emplace_back(CaseDef6);
    cases.emplace_back(CaseDef7);

    return cases;
}

/*
 * Test: trl::find_all
 *
 * Description: Test the behaviour of the trl::find_all algorithm. The purpose of the find_all algorithm is to
 * find all elements in a collection that has a certain value. Tests using both std::string, std::vector, std::deque,
 * std::array, std::multiset, std::unordered_multiset are included.
 * are included.
 */
TEMPLATE_TEST_CASE("Find all elements matching a criterion in a collection of characters using find_all", "[find_all]",
                   (std::string),
                   (std::vector<char>),
                   (std::deque<char>),
                   (std::multiset<char>),
                   (std::unordered_multiset<char>)) {


    auto cases = create_find_all_cases();

    for (auto testcase : cases) {

        TestType container;
        fill_char(container, testcase.array);
        REQUIRE(container.size() == testcase.array.size());

        SECTION(testcase.case_title) {
            std::vector<decltype(container.begin())> results;
            trl::find_all(container.begin(), container.end(), std::back_inserter(results), testcase.search_item);
            REQUIRE(results.size() == testcase.item_locations.size());

            for (int it = 0; it < results.size(); ++it) {
                if constexpr (trl::IsRandomAccessIterator<typename TestType::iterator>::value) {
                    REQUIRE(std::distance(container.begin(), results[it]) == testcase.item_locations[it]);
                }
                REQUIRE(*results[it] == testcase.search_item);
                REQUIRE(std::count(results.begin(), results.end(), results[it]) == 1);
            }
        }

//#if defined(__GNUC__) && !defined(__clang__)
#if defined(_MSC_VER)
        SECTION(testcase.case_title + " (Parallel)") {
            std::vector<decltype(container.begin())> results;
            trl::find_all(std::execution::par, container.begin(), container.end(), std::back_inserter(results), testcase.search_item);
            REQUIRE(results.size() == testcase.item_locations.size());

            for (int it = 0; it < results.size(); ++it) {
                if constexpr (trl::IsRandomAccessIterator<typename TestType::iterator>::value) {
                    REQUIRE(std::distance(container.begin(), results[it]) == testcase.item_locations[it]);
                }
                REQUIRE(*results[it] == testcase.search_item);
                REQUIRE(std::count(results.begin(), results.end(), results[it]) == 1);
            }
        }
#endif

    }
}

/*
 * Test: trl::find_all_if
 *
 * Description: Test the behaviour of the trl::find_all_if algorithm. The purpose of the find_all_if algorithm is to
 * find all elements in a collection that matches a certain criterion. Tests using both std::string, std::vector, std::deque,
 * std::array, std::multiset, std::unordered_multiset are included.
 * are included.
 */
TEMPLATE_TEST_CASE("Find all elements matching a criterion in a collection of characters using find_all_if", "[find_all_if]",
                   (std::string),
                   (std::vector<char>),
                   (std::deque<char>),
                   (std::multiset<char>),
                   (std::unordered_multiset<char>)) {


    auto cases = create_find_all_cases();

    for (auto testcase : cases) {

        TestType container;
        fill_char(container, testcase.array);

        REQUIRE(container.size() == testcase.array.size());

        SECTION(testcase.case_title) {
            std::vector<decltype(container.begin())> results;
            trl::find_all_if(container.begin(), container.end(), std::back_inserter(results), [&](char c) {
                return c == testcase.search_item;
            });

            REQUIRE(results.size() == testcase.item_locations.size());

            for (int it = 0; it < results.size(); ++it) {

                if constexpr (trl::IsRandomAccessIterator<typename TestType::iterator>::value) {
                    REQUIRE(std::distance(container.begin(), results[it]) == testcase.item_locations[it]);
                }

                REQUIRE(*results[it] == testcase.search_item);
                REQUIRE(std::count(results.begin(), results.end(), results[it]) == 1);
            }
        }

//#if defined(__GNUC__) && !defined(__clang__)
#if defined(_MSC_VER)
        SECTION(testcase.case_title + " (Parallel)") {
            std::vector<decltype(container.begin())> results;
            trl::find_all_if(std::execution::par, container.begin(), container.end(), std::back_inserter(results), [&](char c) {
                return c == testcase.search_item;
            });

            REQUIRE(results.size() == testcase.item_locations.size());

            for (int it = 0; it < results.size(); ++it) {

                if constexpr (trl::IsRandomAccessIterator<typename TestType::iterator>::value) {
                    REQUIRE(std::distance(container.begin(), results[it]) == testcase.item_locations[it]);
                }

                REQUIRE(*results[it] == testcase.search_item);
                REQUIRE(std::count(results.begin(), results.end(), results[it]) == 1);
            }
        }
#endif

    }
}

/*
 * Test: trl::find_all_if_not
 *
 * Description: Test the behaviour of the trl::find_all_if_not algorithm. The purpose of the find_all_if_not algorithm is to
 * find all elements in a collection that does not match a certain criterion. Tests using both std::string, std::vector, std::deque,
 * std::array, std::multiset, std::unordered_multiset are included.
 * are included.
 */
TEMPLATE_TEST_CASE("Find all elements not matching a criterion in a collection of characters using find_all_if_not", "[find_all_if_not]",
                   (std::string),
                   (std::vector<char>),
                   (std::deque<char>),
                   (std::multiset<char>),
                   (std::unordered_multiset<char>)) {


    auto cases = create_find_all_cases();
    for (auto testcase : cases) {

        TestType container;
        fill_char(container, testcase.array);
        REQUIRE(container.size() == testcase.array.size());

        SECTION(testcase.case_title) {
            std::vector<decltype(container.begin())> results;
            trl::find_all_if_not(container.begin(), container.end(), std::back_inserter(results), [&](char c) {
                return c != testcase.search_item;
            });

            REQUIRE(results.size() == testcase.item_locations.size());

            for (int it = 0; it < results.size(); ++it) {

                if constexpr (trl::IsRandomAccessIterator<typename TestType::iterator>::value) {
                    REQUIRE(std::distance(container.begin(), results[it]) == testcase.item_locations[it]);
                }

                REQUIRE(*results[it] == testcase.search_item);
                REQUIRE(std::count(results.begin(), results.end(), results[it]) == 1);
            }
        }

//#if defined(__GNUC__) && !defined(__clang__)
#if defined(_MSC_VER)
        SECTION(testcase.case_title + " (Parallel)") {
            std::vector<decltype(container.begin())> results;
            trl::find_all_if_not(std::execution::par, container.begin(), container.end(), std::back_inserter(results), [&](char c) {
                return c != testcase.search_item;
            });

            REQUIRE(results.size() == testcase.item_locations.size());

            for (int it = 0; it < results.size(); ++it) {

                if constexpr (trl::IsRandomAccessIterator<typename TestType::iterator>::value) {
                    REQUIRE(std::distance(container.begin(), results[it]) == testcase.item_locations[it]);
                }

                REQUIRE(*results[it] == testcase.search_item);
                REQUIRE(std::count(results.begin(), results.end(), results[it]) == 1);
            }
        }

#endif

    }
}