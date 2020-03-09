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
 * Test: trl::find_first_not_of
 *
 * Description: Test the behaviour of the trl::find_first_not_of algorithm. The purpose of the find_first_not_of algorithm is to
 * find the first element in a collection that does NOT match a certain criterion. Tests using both std::string, std::vector, std::deque,
 * std::array, std::multiset, std::unordered_multiset are included.
 * are included.
 */
TEMPLATE_TEST_CASE("Find first element NOT matching a criterion in a collection of characters using find_first_not_of", "[find_first_not_of]",
                   (std::string),
                   (std::vector<char>),
                   (std::deque<char>),
                   (std::multiset<char>),
                   (std::unordered_multiset<char>)) {


    auto cases = create_find_first_cases();
    for (auto testcase : cases) {

        // ===== Create container and fill it with characters in the CaseDef.
        TestType container;
        fill_char(container, testcase.array);
        REQUIRE(container.size() == testcase.array.size());


        SECTION(testcase.case_title) {
            auto result = trl::find_first_not_of(container.begin(), container.end(), testcase.search_item.begin(), testcase.search_item.end());

            if (testcase.item_locations.size() == 0)
                REQUIRE(result == container.end());
            else {
                REQUIRE(result != container.end());
                if constexpr (trl::IsRandomAccessIterator<typename TestType::iterator>::value) {
                    REQUIRE(std::distance(container.begin(), result) == testcase.item_locations[0]);
                }
                REQUIRE(std::find(testcase.search_item.begin(), testcase.search_item.end(), *result) == testcase.search_item.end());
            }
        }

#ifdef PARALLEL_ENABLED
        SECTION(testcase.case_title + " (Parallel)") {
            auto result = trl::find_first_not_of(std::execution::seq, container.begin(), container.end(), testcase.search_item.begin(), testcase.search_item.end());

            if (testcase.item_locations.size() == 0)
                REQUIRE(result == container.end());
            else {
                REQUIRE(result != container.end());
                if constexpr (trl::IsRandomAccessIterator<typename TestType::iterator>::value) {
                    REQUIRE(std::distance(container.begin(), result) == testcase.item_locations[0]);
                }
                REQUIRE(std::find(testcase.search_item.begin(), testcase.search_item.end(), *result) == testcase.search_item.end());
            }
        }
#endif
    }
}
