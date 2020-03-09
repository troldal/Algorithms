#include <catch.hpp>
#include <troldalgo.hpp>
#include <string>
#include <vector>
#include <array>
#include <set>
#include <unordered_set>
#include <type_traits>

#ifdef PARALLEL_ENABLED
#include <execution>

#endif

#include "test_case_helpers.hpp"

/*
 * Test: trl::find_all_of
 *
 * Description: Test the behaviour of the trl::find_all_of algorithm. The purpose of the find_all_of algorithm is to
 * find all elements in a collection that matches a certain criterion. Tests using both std::string, std::vector, std::deque
 * are included.
 */
TEMPLATE_TEST_CASE("Search for all sequences of elements in a collection of characters using search_all",
                   "[search_all]",
                   (std::string),
                   (std::vector<char>),
                   (std::deque<char>)) {

    // ===== Load test case definitions
    auto cases = create_search_all_cases();

    // ===== Iterate through the test cases
    for (auto testcase : cases) {

        // ===== Create container and populate it with data from the current case definition.
        TestType container;
        fill_char(container, testcase.array);
        REQUIRE(container.size() == testcase.array.size());

        // ===== Run tests for the current case definition
        SECTION(testcase.case_title) {

            // ===== Run the find_all_if algorithm and check that the number of found elements are correct.
            std::vector<decltype(container.begin())> results;
            trl::search_all(container.begin(), container.end(), testcase.search_item.begin(),
                            testcase.search_item.end(), std::back_inserter(results));
            REQUIRE(results.size() == testcase.item_locations.size());

            // ===== Check each found element that it has the right value and the right positions (only possible for
            // ===== random access iterators). Also check that there are no duplicates amongst the found elements.
            for (size_t it = 0; it < results.size(); ++it) {
                if constexpr (trl::IsRandomAccessIterator<typename TestType::iterator>::value) {
                    REQUIRE(std::distance(container.begin(), results[it]) == testcase.item_locations[it]);
                }
                REQUIRE(std::find(testcase.search_item.begin(), testcase.search_item.end(), *results[it])
                                != testcase.search_item.end());
                REQUIRE(std::count(results.begin(), results.end(), results[it]) == 1);
            }
        }

            // ===== Run tests for the current case definition
        SECTION(testcase.case_title + " (Predicate)") {

            // ===== Run the find_all_if algorithm and check that the number of found elements are correct.
            std::vector<decltype(container.begin())> results;
            trl::search_all(
                    container.begin(),
                    container.end(),
                    testcase.search_item.begin(),
                    testcase.search_item.end(),
                    std::back_inserter(results),
                    [](const char& a,
                       const char& b) {
                        return a == b;
                    });
            REQUIRE(results.size() == testcase.item_locations.size());

            // ===== Check each found element that it has the right value and the right positions (only possible for
            // ===== random access iterators). Also check that there are no duplicates amongst the found elements.
            for (size_t it = 0; it < results.size(); ++it) {
                if constexpr (trl::IsRandomAccessIterator<typename TestType::iterator>::value) {
                    REQUIRE(std::distance(container.begin(), results[it]) == testcase.item_locations[it]);
                }
                REQUIRE(std::find(testcase.search_item.begin(), testcase.search_item.end(), *results[it])
                                != testcase.search_item.end());
                REQUIRE(std::count(results.begin(), results.end(), results[it]) == 1);
            }
        }

#ifdef PARALLEL_ENABLED
        // ===== Run tests for the current case definition in parallel mode
    SECTION(testcase.case_title + " (Parallel)") {

        // ===== Run the find_all_if algorithm and check that the number of found elements are correct.
        std::vector<decltype(container.begin())> results;
        trl::search_all(std::execution::seq, container.begin(), container.end(), testcase.search_item.begin(), testcase.search_item.end(), std::back_inserter(results));
        REQUIRE(results.size() == testcase.item_locations.size());

        // ===== Check each found element that it has the right value and the right positions (only possible for
        // ===== random access iterators). Also chech that there are no duplicates amongst the found elements.
        for (int it = 0; it < results.size(); ++it) {
            if constexpr (trl::IsRandomAccessIterator<typename TestType::iterator>::value) {
                REQUIRE(std::distance(container.begin(), results[it]) == testcase.item_locations[it]);
            }
            REQUIRE(std::find(testcase.search_item.begin(),testcase.search_item.end(), *results[it]) != testcase.search_item.end());
            REQUIRE(std::count(results.begin(), results.end(), results[it]) == 1);
        }
    }

        // ===== Run tests for the current case definition in parallel mode
    SECTION(testcase.case_title + " (Predicate + Parallel)") {

        // ===== Run the find_all_if algorithm and check that the number of found elements are correct.
        std::vector<decltype(container.begin())> results;
        trl::search_all(std::execution::seq,
                         container.begin(),
                         container.end(),
                         testcase.search_item.begin(),
                         testcase.search_item.end(),
                         std::back_inserter(results),
                         [&](const char& a, const char& b) { return a == b; });
        REQUIRE(results.size() == testcase.item_locations.size());

        // ===== Check each found element that it has the right value and the right positions (only possible for
        // ===== random access iterators). Also chech that there are no duplicates amongst the found elements.
        for (int it = 0; it < results.size(); ++it) {
            if constexpr (trl::IsRandomAccessIterator<typename TestType::iterator>::value) {
                REQUIRE(std::distance(container.begin(), results[it]) == testcase.item_locations[it]);
            }
            REQUIRE(std::find(testcase.search_item.begin(),testcase.search_item.end(), *results[it]) != testcase.search_item.end());
            REQUIRE(std::count(results.begin(), results.end(), results[it]) == 1);
        }
    }

#endif
    }
}
