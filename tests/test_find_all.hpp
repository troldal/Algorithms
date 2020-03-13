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

    // ===== Load test case definitions
    auto cases = create_find_all_cases();

    // ===== Iterate through the test cases
    for (const auto& testcase : cases) {

        // ===== Create container and populate it with data from the current case definition.
        TestType container;
        fill_char(container, testcase.array);
        REQUIRE(container.size() == testcase.array.size());

        // ===== Run tests for the current case definition
        SECTION(testcase.case_title) {

            // ===== Run the find_all algorithm and check that the number of found elements are correct.
            std::vector<decltype(container.begin())> results;
            trl::find_all(container.begin(), container.end(), std::back_inserter(results), testcase.search_item);
            REQUIRE(results.size() == testcase.item_locations.size());

            // ===== Check each found element that it has the right value and the right positions (only possible for
            // ===== random access iterators). Also chech that there are no duplicates amongst the found elements.
            for (size_t it = 0; it < results.size(); ++it) {
                if constexpr (trl::IsRandomAccessIterator<typename TestType::iterator>::value) {
                    REQUIRE(std::distance(container.begin(), results[it]) == testcase.item_locations[it]);
                }
                REQUIRE(*results[it] == testcase.search_item);
                REQUIRE(std::count(results.begin(), results.end(), results[it]) == 1);
            }
        }
    }
}
