#include <catch.hpp>
#include <troldalgo.hpp>
#include <string>
#include <vector>
#include <array>
#include <set>
#include <unordered_set>
#include <type_traits>

#include "test_case_helpers.hpp"

/*
 * Test: trl::find_all_not_of
 *
 * Description: Test the behaviour of the trl::find_all_not_of algorithm. The purpose of the find_all_not_of algorithm is to
 * find all elements in a collection that matches a certain criterion. Tests using both std::string, std::vector, std::deque,
 * std::array, std::multiset, std::unordered_multiset are included.
 * are included.
 */
TEMPLATE_TEST_CASE("Find all elements NOT matching a criterion in a collection of characters using find_all_not_of",
                   "[find_all_not_of]",
                   (std::string),
                   (std::vector<char>),
                   (std::deque<char>),
                   (std::multiset<char>),
                   (std::unordered_multiset<char>)) {

    // ===== Load test case definitions
    auto cases = create_find_all_not_of_cases();

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
            trl::find_all_not_of(container.begin(), container.end(), testcase.search_item.begin(),
                                 testcase.search_item.end(), std::back_inserter(results));
            REQUIRE(results.size() == testcase.item_locations.size());

            // ===== Check each found element that it has the right value and the right positions (only possible for
            // ===== random access iterators). Also check that there are no duplicates amongst the found elements.
            for (size_t it = 0; it < results.size(); ++it) {
                if constexpr (trl::IsRandomAccessIterator<typename TestType::iterator>::value) {
                    REQUIRE(std::distance(container.begin(), results[it]) == testcase.item_locations[it]);
                }
                REQUIRE(std::find(testcase.search_item.begin(), testcase.search_item.end(), *results[it])
                                == testcase.search_item.end());
                REQUIRE(std::count(results.begin(), results.end(), results[it]) == 1);
            }
        }

//            // ===== Run tests for the current case definition
//        SECTION(testcase.case_title +" (Predicate)") {
//
//            // ===== Run the find_all_if algorithm and check that the number of found elements are correct.
//            std::vector<decltype(container.begin())> results;
//            trl::find_all_of(
//                    container.begin(),
//                    container.end(),
//                    testcase.search_item.begin(),
//                    testcase.search_item.end(),
//                    std::back_inserter(results),
//                    [](const char& a, const char& b) { return a == b; });
//            REQUIRE(results.size() == testcase.item_locations.size());
//
//            // ===== Check each found element that it has the right value and the right positions (only possible for
//            // ===== random access iterators). Also check that there are no duplicates amongst the found elements.
//            for (size_t it = 0; it < results.size(); ++it) {
//                if constexpr (trl::IsRandomAccessIterator<typename TestType::iterator>::value) {
//                    REQUIRE(std::distance(container.begin(), results[it]) == testcase.item_locations[it]);
//                }
//                REQUIRE(std::find(testcase.search_item.begin(),testcase.search_item.end(), *results[it]) != testcase.search_item.end());
//                REQUIRE(std::count(results.begin(), results.end(), results[it]) == 1);
//            }
//        }
    }
}
