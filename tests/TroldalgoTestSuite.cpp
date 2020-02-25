#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <catch.hpp>
#include <troldalgo.hpp>
#include <string>
#include <vector>
#include <array>
#include <set>
#include <unordered_set>

/*
 * Test: trl::find_all
 *
 * Description: Test the behaviour of the trl::find_all algorithm. The purpose of the find_all algorithm is to
 * find all elements in a collection that has a certain value. Tests using both std::string, std::vector, std::deque,
 * std::array, std::multiset, std::unordered_multiset are included.
 * are included.
 */
SCENARIO("Find all elements in a collection using find_all.", "[find_all]") {

    GIVEN("A std::string with characters'ABCDDCBAABCDDCBAX'" ) {

        auto str = std::string("ABCDDCBAABCDDCBAX");
        REQUIRE(str.size() == 17);

        WHEN("Finding all 'A's in the string") {
            std::vector<decltype(str.begin())> results;
            trl::find_all(str.begin(), str.end(), std::back_inserter(results), 'A');

            THEN("Four items are found at position 0, 7, 8 and 15") {
                REQUIRE(results.size() == 4);
                REQUIRE(std::distance(str.begin(), results[0]) == 0);
                REQUIRE(std::distance(str.begin(), results[1]) == 7);
                REQUIRE(std::distance(str.begin(), results[2]) == 8);
                REQUIRE(std::distance(str.begin(), results[3]) == 15);
                REQUIRE(*results[0] == 'A');
                REQUIRE(*results[1] == 'A');
                REQUIRE(*results[2] == 'A');
                REQUIRE(*results[3] == 'A');
            }
        }

        WHEN("Finding all 'B's in the string") {
            std::vector<decltype(str.begin())> results;
            trl::find_all(str.begin(), str.end(), std::back_inserter(results), 'B');

            THEN("Four items are found at position 1, 6, 9 and 14") {
                REQUIRE(results.size() == 4);
                REQUIRE(std::distance(str.begin(), results[0]) == 1);
                REQUIRE(std::distance(str.begin(), results[1]) == 6);
                REQUIRE(std::distance(str.begin(), results[2]) == 9);
                REQUIRE(std::distance(str.begin(), results[3]) == 14);
                REQUIRE(*results[0] == 'B');
                REQUIRE(*results[1] == 'B');
                REQUIRE(*results[2] == 'B');
                REQUIRE(*results[3] == 'B');
            }
        }

        WHEN("Finding all 'C's in the string") {
            std::vector<decltype(str.begin())> results;
            trl::find_all(str.begin(), str.end(), std::back_inserter(results), 'C');

            THEN("Four items are found at position 2, 5, 10 and 13") {
                REQUIRE(results.size() == 4);
                REQUIRE(std::distance(str.begin(), results[0]) == 2);
                REQUIRE(std::distance(str.begin(), results[1]) == 5);
                REQUIRE(std::distance(str.begin(), results[2]) == 10);
                REQUIRE(std::distance(str.begin(), results[3]) == 13);
                REQUIRE(*results[0] == 'C');
                REQUIRE(*results[1] == 'C');
                REQUIRE(*results[2] == 'C');
                REQUIRE(*results[3] == 'C');
            }
        }

        WHEN("Finding all 'D's in the string") {
            std::vector<decltype(str.begin())> results;
            trl::find_all(str.begin(), str.end(), std::back_inserter(results), 'D');

            THEN("Four items are found at position 3, 4, 11 and 12") {
                REQUIRE(results.size() == 4);
                REQUIRE(std::distance(str.begin(), results[0]) == 3);
                REQUIRE(std::distance(str.begin(), results[1]) == 4);
                REQUIRE(std::distance(str.begin(), results[2]) == 11);
                REQUIRE(std::distance(str.begin(), results[3]) == 12);
                REQUIRE(*results[0] == 'D');
                REQUIRE(*results[1] == 'D');
                REQUIRE(*results[2] == 'D');
                REQUIRE(*results[3] == 'D');
            }
        }

        WHEN("Finding all 'X's in the string") {
            std::vector<decltype(str.begin())> results;
            trl::find_all(str.begin(), str.end(), std::back_inserter(results), 'X');

            THEN("One items are found at position 16") {
                REQUIRE(results.size() == 1);
                REQUIRE(std::distance(str.begin(), results[0]) == 16);
                REQUIRE(*results[0] == 'X');
            }
        }

        WHEN("Finding all 'Z's in the string") {
            std::vector<decltype(str.begin())> results;
            trl::find_all(str.begin(), str.end(), std::back_inserter(results), 'Z');

            THEN("Zero items are found") {
                REQUIRE(results.size() == 0);
            }
        }
    }
    GIVEN("A std::vector with integers '12344321123443219" ) {

        auto vec = std::vector<int> {1,2,3,4,4,3,2,1,1,2,3,4,4,3,2,1,9};
        REQUIRE(vec.size() == 17);

        WHEN("Finding all 1's in the vector") {
            std::vector<decltype(vec.begin())> results;
            trl::find_all(vec.begin(), vec.end(), std::back_inserter(results), 1);

            THEN("Four items are found at position 0, 7, 8 and 15") {
                REQUIRE(results.size() == 4);
                REQUIRE(std::distance(vec.begin(), results[0]) == 0);
                REQUIRE(std::distance(vec.begin(), results[1]) == 7);
                REQUIRE(std::distance(vec.begin(), results[2]) == 8);
                REQUIRE(std::distance(vec.begin(), results[3]) == 15);
                REQUIRE(*results[0] == 1);
                REQUIRE(*results[1] == 1);
                REQUIRE(*results[2] == 1);
                REQUIRE(*results[3] == 1);
            }
        }

        WHEN("Finding all 2's in the string") {
            std::vector<decltype(vec.begin())> results;
            trl::find_all(vec.begin(), vec.end(), std::back_inserter(results), 2);

            THEN("Four items are found at position 1, 6, 9 and 14") {
                REQUIRE(results.size() == 4);
                REQUIRE(std::distance(vec.begin(), results[0]) == 1);
                REQUIRE(std::distance(vec.begin(), results[1]) == 6);
                REQUIRE(std::distance(vec.begin(), results[2]) == 9);
                REQUIRE(std::distance(vec.begin(), results[3]) == 14);
                REQUIRE(*results[0] == 2);
                REQUIRE(*results[1] == 2);
                REQUIRE(*results[2] == 2);
                REQUIRE(*results[3] == 2);
            }
        }

        WHEN("Finding all 3's in the string") {
            std::vector<decltype(vec.begin())> results;
            trl::find_all(vec.begin(), vec.end(), std::back_inserter(results), 3);

            THEN("Four items are found at position 2, 5, 10 and 13") {
                REQUIRE(results.size() == 4);
                REQUIRE(std::distance(vec.begin(), results[0]) == 2);
                REQUIRE(std::distance(vec.begin(), results[1]) == 5);
                REQUIRE(std::distance(vec.begin(), results[2]) == 10);
                REQUIRE(std::distance(vec.begin(), results[3]) == 13);
                REQUIRE(*results[0] == 3);
                REQUIRE(*results[1] == 3);
                REQUIRE(*results[2] == 3);
                REQUIRE(*results[3] == 3);
            }
        }

        WHEN("Finding all 4's in the string") {
            std::vector<decltype(vec.begin())> results;
            trl::find_all(vec.begin(), vec.end(), std::back_inserter(results), 4);

            THEN("Four items are found at position 3, 4, 11 and 12") {
                REQUIRE(results.size() == 4);
                REQUIRE(std::distance(vec.begin(), results[0]) == 3);
                REQUIRE(std::distance(vec.begin(), results[1]) == 4);
                REQUIRE(std::distance(vec.begin(), results[2]) == 11);
                REQUIRE(std::distance(vec.begin(), results[3]) == 12);
                REQUIRE(*results[0] == 4);
                REQUIRE(*results[1] == 4);
                REQUIRE(*results[2] == 4);
                REQUIRE(*results[3] == 4);
            }
        }

        WHEN("Finding all 9's in the string") {
            std::vector<decltype(vec.begin())> results;
            trl::find_all(vec.begin(), vec.end(), std::back_inserter(results), 9);

            THEN("One items are found at position 16") {
                REQUIRE(results.size() == 1);
                REQUIRE(std::distance(vec.begin(), results[0]) == 16);
                REQUIRE(*results[0] == 9);
            }
        }

        WHEN("Finding all 0's in the string") {
            std::vector<decltype(vec.begin())> results;
            trl::find_all(vec.begin(), vec.end(), std::back_inserter(results), 0);

            THEN("Zero items are found") {
                REQUIRE(results.size() == 0);
            }
        }
    }
    GIVEN("A std::deque with integers '12344321123443219" ) {

        auto dqe = std::deque<int> {1, 2, 3, 4, 4, 3, 2, 1, 1, 2, 3, 4, 4, 3, 2, 1, 9};
        REQUIRE(dqe.size() == 17);

        WHEN("Finding all 1's in the vector") {
            std::vector<decltype(dqe.begin())> results;
            trl::find_all(dqe.begin(), dqe.end(), std::back_inserter(results), 1);

            THEN("Four items are found at position 0, 7, 8 and 15") {
                REQUIRE(results.size() == 4);
                REQUIRE(std::distance(dqe.begin(), results[0]) == 0);
                REQUIRE(std::distance(dqe.begin(), results[1]) == 7);
                REQUIRE(std::distance(dqe.begin(), results[2]) == 8);
                REQUIRE(std::distance(dqe.begin(), results[3]) == 15);
                REQUIRE(*results[0] == 1);
                REQUIRE(*results[1] == 1);
                REQUIRE(*results[2] == 1);
                REQUIRE(*results[3] == 1);
            }
        }

        WHEN("Finding all 2's in the string") {
            std::vector<decltype(dqe.begin())> results;
            trl::find_all(dqe.begin(), dqe.end(), std::back_inserter(results), 2);

            THEN("Four items are found at position 1, 6, 9 and 14") {
                REQUIRE(results.size() == 4);
                REQUIRE(std::distance(dqe.begin(), results[0]) == 1);
                REQUIRE(std::distance(dqe.begin(), results[1]) == 6);
                REQUIRE(std::distance(dqe.begin(), results[2]) == 9);
                REQUIRE(std::distance(dqe.begin(), results[3]) == 14);
                REQUIRE(*results[0] == 2);
                REQUIRE(*results[1] == 2);
                REQUIRE(*results[2] == 2);
                REQUIRE(*results[3] == 2);
            }
        }

        WHEN("Finding all 3's in the string") {
            std::vector<decltype(dqe.begin())> results;
            trl::find_all(dqe.begin(), dqe.end(), std::back_inserter(results), 3);

            THEN("Four items are found at position 2, 5, 10 and 13") {
                REQUIRE(results.size() == 4);
                REQUIRE(std::distance(dqe.begin(), results[0]) == 2);
                REQUIRE(std::distance(dqe.begin(), results[1]) == 5);
                REQUIRE(std::distance(dqe.begin(), results[2]) == 10);
                REQUIRE(std::distance(dqe.begin(), results[3]) == 13);
                REQUIRE(*results[0] == 3);
                REQUIRE(*results[1] == 3);
                REQUIRE(*results[2] == 3);
                REQUIRE(*results[3] == 3);
            }
        }

        WHEN("Finding all 4's in the string") {
            std::vector<decltype(dqe.begin())> results;
            trl::find_all(dqe.begin(), dqe.end(), std::back_inserter(results), 4);

            THEN("Four items are found at position 3, 4, 11 and 12") {
                REQUIRE(results.size() == 4);
                REQUIRE(std::distance(dqe.begin(), results[0]) == 3);
                REQUIRE(std::distance(dqe.begin(), results[1]) == 4);
                REQUIRE(std::distance(dqe.begin(), results[2]) == 11);
                REQUIRE(std::distance(dqe.begin(), results[3]) == 12);
                REQUIRE(*results[0] == 4);
                REQUIRE(*results[1] == 4);
                REQUIRE(*results[2] == 4);
                REQUIRE(*results[3] == 4);
            }
        }

        WHEN("Finding all 9's in the string") {
            std::vector<decltype(dqe.begin())> results;
            trl::find_all(dqe.begin(), dqe.end(), std::back_inserter(results), 9);

            THEN("One items are found at position 16") {
                REQUIRE(results.size() == 1);
                REQUIRE(std::distance(dqe.begin(), results[0]) == 16);
                REQUIRE(*results[0] == 9);
            }
        }

        WHEN("Finding all 0's in the string") {
            std::vector<decltype(dqe.begin())> results;
            trl::find_all(dqe.begin(), dqe.end(), std::back_inserter(results), 0);

            THEN("Zero items are found") {
                REQUIRE(results.size() == 0);
            }
        }
    }
    GIVEN("A std::array with integers '12344321123443219" ) {

        auto arr = std::array<int, 17> {1, 2, 3, 4, 4, 3, 2, 1, 1, 2, 3, 4, 4, 3, 2, 1, 9};
        REQUIRE(arr.size() == 17);

        WHEN("Finding all 1's in the vector") {
            std::vector<decltype(arr.begin())> results;
            trl::find_all(arr.begin(), arr.end(), std::back_inserter(results), 1);

            THEN("Four items are found at position 0, 7, 8 and 15") {
                REQUIRE(results.size() == 4);
                REQUIRE(std::distance(arr.begin(), results[0]) == 0);
                REQUIRE(std::distance(arr.begin(), results[1]) == 7);
                REQUIRE(std::distance(arr.begin(), results[2]) == 8);
                REQUIRE(std::distance(arr.begin(), results[3]) == 15);
                REQUIRE(*results[0] == 1);
                REQUIRE(*results[1] == 1);
                REQUIRE(*results[2] == 1);
                REQUIRE(*results[3] == 1);
            }
        }

        WHEN("Finding all 2's in the string") {
            std::vector<decltype(arr.begin())> results;
            trl::find_all(arr.begin(), arr.end(), std::back_inserter(results), 2);

            THEN("Four items are found at position 1, 6, 9 and 14") {
                REQUIRE(results.size() == 4);
                REQUIRE(std::distance(arr.begin(), results[0]) == 1);
                REQUIRE(std::distance(arr.begin(), results[1]) == 6);
                REQUIRE(std::distance(arr.begin(), results[2]) == 9);
                REQUIRE(std::distance(arr.begin(), results[3]) == 14);
                REQUIRE(*results[0] == 2);
                REQUIRE(*results[1] == 2);
                REQUIRE(*results[2] == 2);
                REQUIRE(*results[3] == 2);
            }
        }

        WHEN("Finding all 3's in the string") {
            std::vector<decltype(arr.begin())> results;
            trl::find_all(arr.begin(), arr.end(), std::back_inserter(results), 3);

            THEN("Four items are found at position 2, 5, 10 and 13") {
                REQUIRE(results.size() == 4);
                REQUIRE(std::distance(arr.begin(), results[0]) == 2);
                REQUIRE(std::distance(arr.begin(), results[1]) == 5);
                REQUIRE(std::distance(arr.begin(), results[2]) == 10);
                REQUIRE(std::distance(arr.begin(), results[3]) == 13);
                REQUIRE(*results[0] == 3);
                REQUIRE(*results[1] == 3);
                REQUIRE(*results[2] == 3);
                REQUIRE(*results[3] == 3);
            }
        }

        WHEN("Finding all 4's in the string") {
            std::vector<decltype(arr.begin())> results;
            trl::find_all(arr.begin(), arr.end(), std::back_inserter(results), 4);

            THEN("Four items are found at position 3, 4, 11 and 12") {
                REQUIRE(results.size() == 4);
                REQUIRE(std::distance(arr.begin(), results[0]) == 3);
                REQUIRE(std::distance(arr.begin(), results[1]) == 4);
                REQUIRE(std::distance(arr.begin(), results[2]) == 11);
                REQUIRE(std::distance(arr.begin(), results[3]) == 12);
                REQUIRE(*results[0] == 4);
                REQUIRE(*results[1] == 4);
                REQUIRE(*results[2] == 4);
                REQUIRE(*results[3] == 4);
            }
        }

        WHEN("Finding all 9's in the string") {
            std::vector<decltype(arr.begin())> results;
            trl::find_all(arr.begin(), arr.end(), std::back_inserter(results), 9);

            THEN("One items are found at position 16") {
                REQUIRE(results.size() == 1);
                REQUIRE(std::distance(arr.begin(), results[0]) == 16);
                REQUIRE(*results[0] == 9);
            }
        }

        WHEN("Finding all 0's in the string") {
            std::vector<decltype(arr.begin())> results;
            trl::find_all(arr.begin(), arr.end(), std::back_inserter(results), 0);

            THEN("Zero items are found") {
                REQUIRE(results.size() == 0);
            }
        }
    }
    GIVEN("A std::multiset with integers '12344321123443219" ) {

        auto set = std::multiset<int> {1, 2, 3, 4, 4, 3, 2, 1, 1, 2, 3, 4, 4, 3, 2, 1, 9};
        REQUIRE(set.size() == 17);

        WHEN("Finding all 1's in the vector") {
            std::vector<decltype(set.begin())> results;
            trl::find_all(set.begin(), set.end(), std::back_inserter(results), 1);

            THEN("Four items are found at position 0, 7, 8 and 15") {
                REQUIRE(results.size() == 4);
                REQUIRE(*results[0] == 1);
                REQUIRE(*results[1] == 1);
                REQUIRE(*results[2] == 1);
                REQUIRE(*results[3] == 1);

                REQUIRE(results[0] != results[1]);
                REQUIRE(results[0] != results[2]);
                REQUIRE(results[0] != results[3]);
                REQUIRE(results[1] != results[2]);
                REQUIRE(results[1] != results[3]);
                REQUIRE(results[2] != results[3]);
            }
        }

        WHEN("Finding all 2's in the string") {
            std::vector<decltype(set.begin())> results;
            trl::find_all(set.begin(), set.end(), std::back_inserter(results), 2);

            THEN("Four items are found at position 1, 6, 9 and 14") {
                REQUIRE(results.size() == 4);
                REQUIRE(*results[0] == 2);
                REQUIRE(*results[1] == 2);
                REQUIRE(*results[2] == 2);
                REQUIRE(*results[3] == 2);

                REQUIRE(results[0] != results[1]);
                REQUIRE(results[0] != results[2]);
                REQUIRE(results[0] != results[3]);
                REQUIRE(results[1] != results[2]);
                REQUIRE(results[1] != results[3]);
                REQUIRE(results[2] != results[3]);
            }
        }

        WHEN("Finding all 3's in the string") {
            std::vector<decltype(set.begin())> results;
            trl::find_all(set.begin(), set.end(), std::back_inserter(results), 3);

            THEN("Four items are found at position 2, 5, 10 and 13") {
                REQUIRE(results.size() == 4);
                REQUIRE(*results[0] == 3);
                REQUIRE(*results[1] == 3);
                REQUIRE(*results[2] == 3);
                REQUIRE(*results[3] == 3);

                REQUIRE(results[0] != results[1]);
                REQUIRE(results[0] != results[2]);
                REQUIRE(results[0] != results[3]);
                REQUIRE(results[1] != results[2]);
                REQUIRE(results[1] != results[3]);
                REQUIRE(results[2] != results[3]);
            }
        }

        WHEN("Finding all 4's in the string") {
            std::vector<decltype(set.begin())> results;
            trl::find_all(set.begin(), set.end(), std::back_inserter(results), 4);

            THEN("Four items are found at position 3, 4, 11 and 12") {
                REQUIRE(results.size() == 4);
                REQUIRE(*results[0] == 4);
                REQUIRE(*results[1] == 4);
                REQUIRE(*results[2] == 4);
                REQUIRE(*results[3] == 4);

                REQUIRE(results[0] != results[1]);
                REQUIRE(results[0] != results[2]);
                REQUIRE(results[0] != results[3]);
                REQUIRE(results[1] != results[2]);
                REQUIRE(results[1] != results[3]);
                REQUIRE(results[2] != results[3]);
            }
        }

        WHEN("Finding all 9's in the string") {
            std::vector<decltype(set.begin())> results;
            trl::find_all(set.begin(), set.end(), std::back_inserter(results), 9);

            THEN("One items are found at position 16") {
                REQUIRE(results.size() == 1);
                REQUIRE(*results[0] == 9);
            }
        }

        WHEN("Finding all 0's in the string") {
            std::vector<decltype(set.begin())> results;
            trl::find_all(set.begin(), set.end(), std::back_inserter(results), 0);

            THEN("Zero items are found") {
                REQUIRE(results.size() == 0);
            }
        }
    }
    GIVEN("A std::unordered_multiset with integers '12344321123443219" ) {

        auto set = std::unordered_multiset<int> {1, 2, 3, 4, 4, 3, 2, 1, 1, 2, 3, 4, 4, 3, 2, 1, 9};
        REQUIRE(set.size() == 17);

        WHEN("Finding all 1's in the vector") {
            std::vector<decltype(set.begin())> results;
            trl::find_all(set.begin(), set.end(), std::back_inserter(results), 1);

            THEN("Four items are found at position 0, 7, 8 and 15") {
                REQUIRE(results.size() == 4);
                REQUIRE(*results[0] == 1);
                REQUIRE(*results[1] == 1);
                REQUIRE(*results[2] == 1);
                REQUIRE(*results[3] == 1);

                REQUIRE(results[0] != results[1]);
                REQUIRE(results[0] != results[2]);
                REQUIRE(results[0] != results[3]);
                REQUIRE(results[1] != results[2]);
                REQUIRE(results[1] != results[3]);
                REQUIRE(results[2] != results[3]);
            }
        }

        WHEN("Finding all 2's in the string") {
            std::vector<decltype(set.begin())> results;
            trl::find_all(set.begin(), set.end(), std::back_inserter(results), 2);

            THEN("Four items are found at position 1, 6, 9 and 14") {
                REQUIRE(results.size() == 4);
                REQUIRE(*results[0] == 2);
                REQUIRE(*results[1] == 2);
                REQUIRE(*results[2] == 2);
                REQUIRE(*results[3] == 2);

                REQUIRE(results[0] != results[1]);
                REQUIRE(results[0] != results[2]);
                REQUIRE(results[0] != results[3]);
                REQUIRE(results[1] != results[2]);
                REQUIRE(results[1] != results[3]);
                REQUIRE(results[2] != results[3]);
            }
        }

        WHEN("Finding all 3's in the string") {
            std::vector<decltype(set.begin())> results;
            trl::find_all(set.begin(), set.end(), std::back_inserter(results), 3);

            THEN("Four items are found at position 2, 5, 10 and 13") {
                REQUIRE(results.size() == 4);
                REQUIRE(*results[0] == 3);
                REQUIRE(*results[1] == 3);
                REQUIRE(*results[2] == 3);
                REQUIRE(*results[3] == 3);

                REQUIRE(results[0] != results[1]);
                REQUIRE(results[0] != results[2]);
                REQUIRE(results[0] != results[3]);
                REQUIRE(results[1] != results[2]);
                REQUIRE(results[1] != results[3]);
                REQUIRE(results[2] != results[3]);
            }
        }

        WHEN("Finding all 4's in the string") {
            std::vector<decltype(set.begin())> results;
            trl::find_all(set.begin(), set.end(), std::back_inserter(results), 4);

            THEN("Four items are found at position 3, 4, 11 and 12") {
                REQUIRE(results.size() == 4);
                REQUIRE(*results[0] == 4);
                REQUIRE(*results[1] == 4);
                REQUIRE(*results[2] == 4);
                REQUIRE(*results[3] == 4);

                REQUIRE(results[0] != results[1]);
                REQUIRE(results[0] != results[2]);
                REQUIRE(results[0] != results[3]);
                REQUIRE(results[1] != results[2]);
                REQUIRE(results[1] != results[3]);
                REQUIRE(results[2] != results[3]);
            }
        }

        WHEN("Finding all 9's in the string") {
            std::vector<decltype(set.begin())> results;
            trl::find_all(set.begin(), set.end(), std::back_inserter(results), 9);

            THEN("One items are found at position 16") {
                REQUIRE(results.size() == 1);
                REQUIRE(*results[0] == 9);
            }
        }

        WHEN("Finding all 0's in the string") {
            std::vector<decltype(set.begin())> results;
            trl::find_all(set.begin(), set.end(), std::back_inserter(results), 0);

            THEN("Zero items are found") {
                REQUIRE(results.size() == 0);
            }
        }
    }
    GIVEN("An empty std::string" ) {

        auto str = std::string();
        REQUIRE(str.size() == 0);

        WHEN("Finding all 'Z's in the string") {
            std::vector<decltype(str.begin())> results;
            trl::find_all(str.begin(), str.end(), std::back_inserter(results), 'Z');

            THEN("Zero items are found") {
                REQUIRE(results.size() == 0);
            }
        }
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
SCENARIO("Find all elements matching a certain criteria in a collection using find_all_if.", "[find_all_if]") {

    GIVEN("A std::string with characters'ABCDDCBAABCDDCBAX'" ) {

        auto str = std::string("ABCDDCBAABCDDCBAX");
        REQUIRE(str.size() == 17);

        WHEN("Finding all 'A's in the string") {
            std::vector<decltype(str.begin())> results;
            trl::find_all_if(str.begin(), str.end(), std::back_inserter(results), [](char c) {return c == 'A';});

            THEN("Four items are found at position 0, 7, 8 and 15") {
                REQUIRE(results.size() == 4);
                REQUIRE(std::distance(str.begin(), results[0]) == 0);
                REQUIRE(std::distance(str.begin(), results[1]) == 7);
                REQUIRE(std::distance(str.begin(), results[2]) == 8);
                REQUIRE(std::distance(str.begin(), results[3]) == 15);
                REQUIRE(*results[0] == 'A');
                REQUIRE(*results[1] == 'A');
                REQUIRE(*results[2] == 'A');
                REQUIRE(*results[3] == 'A');
            }
        }

        WHEN("Finding all 'B's in the string") {
            std::vector<decltype(str.begin())> results;
            trl::find_all_if(str.begin(), str.end(), std::back_inserter(results), [](char c) {return c == 'B';});

            THEN("Four items are found at position 1, 6, 9 and 14") {
                REQUIRE(results.size() == 4);
                REQUIRE(std::distance(str.begin(), results[0]) == 1);
                REQUIRE(std::distance(str.begin(), results[1]) == 6);
                REQUIRE(std::distance(str.begin(), results[2]) == 9);
                REQUIRE(std::distance(str.begin(), results[3]) == 14);
                REQUIRE(*results[0] == 'B');
                REQUIRE(*results[1] == 'B');
                REQUIRE(*results[2] == 'B');
                REQUIRE(*results[3] == 'B');
            }
        }

        WHEN("Finding all 'C's in the string") {
            std::vector<decltype(str.begin())> results;
            trl::find_all_if(str.begin(), str.end(), std::back_inserter(results), [](char c) {return c == 'C';});

            THEN("Four items are found at position 2, 5, 10 and 13") {
                REQUIRE(results.size() == 4);
                REQUIRE(std::distance(str.begin(), results[0]) == 2);
                REQUIRE(std::distance(str.begin(), results[1]) == 5);
                REQUIRE(std::distance(str.begin(), results[2]) == 10);
                REQUIRE(std::distance(str.begin(), results[3]) == 13);
                REQUIRE(*results[0] == 'C');
                REQUIRE(*results[1] == 'C');
                REQUIRE(*results[2] == 'C');
                REQUIRE(*results[3] == 'C');
            }
        }

        WHEN("Finding all 'D's in the string") {
            std::vector<decltype(str.begin())> results;
            trl::find_all_if(str.begin(), str.end(), std::back_inserter(results), [](char c) {return c == 'D';});

            THEN("Four items are found at position 3, 4, 11 and 12") {
                REQUIRE(results.size() == 4);
                REQUIRE(std::distance(str.begin(), results[0]) == 3);
                REQUIRE(std::distance(str.begin(), results[1]) == 4);
                REQUIRE(std::distance(str.begin(), results[2]) == 11);
                REQUIRE(std::distance(str.begin(), results[3]) == 12);
                REQUIRE(*results[0] == 'D');
                REQUIRE(*results[1] == 'D');
                REQUIRE(*results[2] == 'D');
                REQUIRE(*results[3] == 'D');
            }
        }

        WHEN("Finding all 'X's in the string") {
            std::vector<decltype(str.begin())> results;
            trl::find_all_if(str.begin(), str.end(), std::back_inserter(results), [](char c) {return c == 'X';});

            THEN("One items are found at position 16") {
                REQUIRE(results.size() == 1);
                REQUIRE(std::distance(str.begin(), results[0]) == 16);
                REQUIRE(*results[0] == 'X');
            }
        }

        WHEN("Finding all 'Z's in the string") {
            std::vector<decltype(str.begin())> results;
            trl::find_all_if(str.begin(), str.end(), std::back_inserter(results), [](char c) {return c == 'Z';});

            THEN("Zero items are found") {
                REQUIRE(results.size() == 0);
            }
        }
    }
    GIVEN("A std::vector with integers '12344321123443219" ) {

        auto vec = std::vector<int> {1,2,3,4,4,3,2,1,1,2,3,4,4,3,2,1,9};
        REQUIRE(vec.size() == 17);

        WHEN("Finding all 1's in the vector") {
            std::vector<decltype(vec.begin())> results;
            trl::find_all_if(vec.begin(), vec.end(), std::back_inserter(results), [](int i) {return i == 1;});

            THEN("Four items are found at position 0, 7, 8 and 15") {
                REQUIRE(results.size() == 4);
                REQUIRE(std::distance(vec.begin(), results[0]) == 0);
                REQUIRE(std::distance(vec.begin(), results[1]) == 7);
                REQUIRE(std::distance(vec.begin(), results[2]) == 8);
                REQUIRE(std::distance(vec.begin(), results[3]) == 15);
                REQUIRE(*results[0] == 1);
                REQUIRE(*results[1] == 1);
                REQUIRE(*results[2] == 1);
                REQUIRE(*results[3] == 1);
            }
        }

        WHEN("Finding all 2's in the string") {
            std::vector<decltype(vec.begin())> results;
            trl::find_all_if(vec.begin(), vec.end(), std::back_inserter(results), [](int i) {return i == 2;});

            THEN("Four items are found at position 1, 6, 9 and 14") {
                REQUIRE(results.size() == 4);
                REQUIRE(std::distance(vec.begin(), results[0]) == 1);
                REQUIRE(std::distance(vec.begin(), results[1]) == 6);
                REQUIRE(std::distance(vec.begin(), results[2]) == 9);
                REQUIRE(std::distance(vec.begin(), results[3]) == 14);
                REQUIRE(*results[0] == 2);
                REQUIRE(*results[1] == 2);
                REQUIRE(*results[2] == 2);
                REQUIRE(*results[3] == 2);
            }
        }

        WHEN("Finding all 3's in the string") {
            std::vector<decltype(vec.begin())> results;
            trl::find_all_if(vec.begin(), vec.end(), std::back_inserter(results), [](int i) {return i == 3;});

            THEN("Four items are found at position 2, 5, 10 and 13") {
                REQUIRE(results.size() == 4);
                REQUIRE(std::distance(vec.begin(), results[0]) == 2);
                REQUIRE(std::distance(vec.begin(), results[1]) == 5);
                REQUIRE(std::distance(vec.begin(), results[2]) == 10);
                REQUIRE(std::distance(vec.begin(), results[3]) == 13);
                REQUIRE(*results[0] == 3);
                REQUIRE(*results[1] == 3);
                REQUIRE(*results[2] == 3);
                REQUIRE(*results[3] == 3);
            }
        }

        WHEN("Finding all 4's in the string") {
            std::vector<decltype(vec.begin())> results;
            trl::find_all_if(vec.begin(), vec.end(), std::back_inserter(results), [](int i) {return i == 4;});

            THEN("Four items are found at position 3, 4, 11 and 12") {
                REQUIRE(results.size() == 4);
                REQUIRE(std::distance(vec.begin(), results[0]) == 3);
                REQUIRE(std::distance(vec.begin(), results[1]) == 4);
                REQUIRE(std::distance(vec.begin(), results[2]) == 11);
                REQUIRE(std::distance(vec.begin(), results[3]) == 12);
                REQUIRE(*results[0] == 4);
                REQUIRE(*results[1] == 4);
                REQUIRE(*results[2] == 4);
                REQUIRE(*results[3] == 4);
            }
        }

        WHEN("Finding all 9's in the string") {
            std::vector<decltype(vec.begin())> results;
            trl::find_all_if(vec.begin(), vec.end(), std::back_inserter(results), [](int i) {return i == 9;});

            THEN("One items are found at position 16") {
                REQUIRE(results.size() == 1);
                REQUIRE(std::distance(vec.begin(), results[0]) == 16);
                REQUIRE(*results[0] == 9);
            }
        }

        WHEN("Finding all 0's in the string") {
            std::vector<decltype(vec.begin())> results;
            trl::find_all_if(vec.begin(), vec.end(), std::back_inserter(results), [](int i) {return i == 0;});

            THEN("Zero items are found") {
                REQUIRE(results.size() == 0);
            }
        }
    }
    GIVEN("A std::deque with integers '12344321123443219" ) {

        auto dqe = std::deque<int> {1, 2, 3, 4, 4, 3, 2, 1, 1, 2, 3, 4, 4, 3, 2, 1, 9};
        REQUIRE(dqe.size() == 17);

        WHEN("Finding all 1's in the vector") {
            std::vector<decltype(dqe.begin())> results;
            trl::find_all_if(dqe.begin(), dqe.end(), std::back_inserter(results), [](int i) {return i == 1;});

            THEN("Four items are found at position 0, 7, 8 and 15") {
                REQUIRE(results.size() == 4);
                REQUIRE(std::distance(dqe.begin(), results[0]) == 0);
                REQUIRE(std::distance(dqe.begin(), results[1]) == 7);
                REQUIRE(std::distance(dqe.begin(), results[2]) == 8);
                REQUIRE(std::distance(dqe.begin(), results[3]) == 15);
                REQUIRE(*results[0] == 1);
                REQUIRE(*results[1] == 1);
                REQUIRE(*results[2] == 1);
                REQUIRE(*results[3] == 1);
            }
        }

        WHEN("Finding all 2's in the string") {
            std::vector<decltype(dqe.begin())> results;
            trl::find_all_if(dqe.begin(), dqe.end(), std::back_inserter(results), [](int i) {return i == 2;});

            THEN("Four items are found at position 1, 6, 9 and 14") {
                REQUIRE(results.size() == 4);
                REQUIRE(std::distance(dqe.begin(), results[0]) == 1);
                REQUIRE(std::distance(dqe.begin(), results[1]) == 6);
                REQUIRE(std::distance(dqe.begin(), results[2]) == 9);
                REQUIRE(std::distance(dqe.begin(), results[3]) == 14);
                REQUIRE(*results[0] == 2);
                REQUIRE(*results[1] == 2);
                REQUIRE(*results[2] == 2);
                REQUIRE(*results[3] == 2);
            }
        }

        WHEN("Finding all 3's in the string") {
            std::vector<decltype(dqe.begin())> results;
            trl::find_all_if(dqe.begin(), dqe.end(), std::back_inserter(results), [](int i) {return i == 3;});

            THEN("Four items are found at position 2, 5, 10 and 13") {
                REQUIRE(results.size() == 4);
                REQUIRE(std::distance(dqe.begin(), results[0]) == 2);
                REQUIRE(std::distance(dqe.begin(), results[1]) == 5);
                REQUIRE(std::distance(dqe.begin(), results[2]) == 10);
                REQUIRE(std::distance(dqe.begin(), results[3]) == 13);
                REQUIRE(*results[0] == 3);
                REQUIRE(*results[1] == 3);
                REQUIRE(*results[2] == 3);
                REQUIRE(*results[3] == 3);
            }
        }

        WHEN("Finding all 4's in the string") {
            std::vector<decltype(dqe.begin())> results;
            trl::find_all_if(dqe.begin(), dqe.end(), std::back_inserter(results), [](int i) {return i == 4;});

            THEN("Four items are found at position 3, 4, 11 and 12") {
                REQUIRE(results.size() == 4);
                REQUIRE(std::distance(dqe.begin(), results[0]) == 3);
                REQUIRE(std::distance(dqe.begin(), results[1]) == 4);
                REQUIRE(std::distance(dqe.begin(), results[2]) == 11);
                REQUIRE(std::distance(dqe.begin(), results[3]) == 12);
                REQUIRE(*results[0] == 4);
                REQUIRE(*results[1] == 4);
                REQUIRE(*results[2] == 4);
                REQUIRE(*results[3] == 4);
            }
        }

        WHEN("Finding all 9's in the string") {
            std::vector<decltype(dqe.begin())> results;
            trl::find_all_if(dqe.begin(), dqe.end(), std::back_inserter(results), [](int i) {return i == 9;});

            THEN("One items are found at position 16") {
                REQUIRE(results.size() == 1);
                REQUIRE(std::distance(dqe.begin(), results[0]) == 16);
                REQUIRE(*results[0] == 9);
            }
        }

        WHEN("Finding all 0's in the string") {
            std::vector<decltype(dqe.begin())> results;
            trl::find_all_if(dqe.begin(), dqe.end(), std::back_inserter(results), [](int i) {return i == 0;});

            THEN("Zero items are found") {
                REQUIRE(results.size() == 0);
            }
        }
    }
    GIVEN("A std::array with integers '12344321123443219" ) {

        auto arr = std::array<int, 17> {1, 2, 3, 4, 4, 3, 2, 1, 1, 2, 3, 4, 4, 3, 2, 1, 9};
        REQUIRE(arr.size() == 17);

        WHEN("Finding all 1's in the vector") {
            std::vector<decltype(arr.begin())> results;
            trl::find_all_if(arr.begin(), arr.end(), std::back_inserter(results), [](int i) {return i == 1;});

            THEN("Four items are found at position 0, 7, 8 and 15") {
                REQUIRE(results.size() == 4);
                REQUIRE(std::distance(arr.begin(), results[0]) == 0);
                REQUIRE(std::distance(arr.begin(), results[1]) == 7);
                REQUIRE(std::distance(arr.begin(), results[2]) == 8);
                REQUIRE(std::distance(arr.begin(), results[3]) == 15);
                REQUIRE(*results[0] == 1);
                REQUIRE(*results[1] == 1);
                REQUIRE(*results[2] == 1);
                REQUIRE(*results[3] == 1);
            }
        }

        WHEN("Finding all 2's in the string") {
            std::vector<decltype(arr.begin())> results;
            trl::find_all_if(arr.begin(), arr.end(), std::back_inserter(results), [](int i) {return i == 2;});

            THEN("Four items are found at position 1, 6, 9 and 14") {
                REQUIRE(results.size() == 4);
                REQUIRE(std::distance(arr.begin(), results[0]) == 1);
                REQUIRE(std::distance(arr.begin(), results[1]) == 6);
                REQUIRE(std::distance(arr.begin(), results[2]) == 9);
                REQUIRE(std::distance(arr.begin(), results[3]) == 14);
                REQUIRE(*results[0] == 2);
                REQUIRE(*results[1] == 2);
                REQUIRE(*results[2] == 2);
                REQUIRE(*results[3] == 2);
            }
        }

        WHEN("Finding all 3's in the string") {
            std::vector<decltype(arr.begin())> results;
            trl::find_all_if(arr.begin(), arr.end(), std::back_inserter(results), [](int i) {return i == 3;});

            THEN("Four items are found at position 2, 5, 10 and 13") {
                REQUIRE(results.size() == 4);
                REQUIRE(std::distance(arr.begin(), results[0]) == 2);
                REQUIRE(std::distance(arr.begin(), results[1]) == 5);
                REQUIRE(std::distance(arr.begin(), results[2]) == 10);
                REQUIRE(std::distance(arr.begin(), results[3]) == 13);
                REQUIRE(*results[0] == 3);
                REQUIRE(*results[1] == 3);
                REQUIRE(*results[2] == 3);
                REQUIRE(*results[3] == 3);
            }
        }

        WHEN("Finding all 4's in the string") {
            std::vector<decltype(arr.begin())> results;
            trl::find_all_if(arr.begin(), arr.end(), std::back_inserter(results), [](int i) {return i == 4;});

            THEN("Four items are found at position 3, 4, 11 and 12") {
                REQUIRE(results.size() == 4);
                REQUIRE(std::distance(arr.begin(), results[0]) == 3);
                REQUIRE(std::distance(arr.begin(), results[1]) == 4);
                REQUIRE(std::distance(arr.begin(), results[2]) == 11);
                REQUIRE(std::distance(arr.begin(), results[3]) == 12);
                REQUIRE(*results[0] == 4);
                REQUIRE(*results[1] == 4);
                REQUIRE(*results[2] == 4);
                REQUIRE(*results[3] == 4);
            }
        }

        WHEN("Finding all 9's in the string") {
            std::vector<decltype(arr.begin())> results;
            trl::find_all_if(arr.begin(), arr.end(), std::back_inserter(results), [](int i) {return i == 9;});

            THEN("One items are found at position 16") {
                REQUIRE(results.size() == 1);
                REQUIRE(std::distance(arr.begin(), results[0]) == 16);
                REQUIRE(*results[0] == 9);
            }
        }

        WHEN("Finding all 0's in the string") {
            std::vector<decltype(arr.begin())> results;
            trl::find_all_if(arr.begin(), arr.end(), std::back_inserter(results), [](int i) {return i == 0;});

            THEN("Zero items are found") {
                REQUIRE(results.size() == 0);
            }
        }
    }
    GIVEN("A std::multiset with integers '12344321123443219" ) {

        auto set = std::multiset<int> {1, 2, 3, 4, 4, 3, 2, 1, 1, 2, 3, 4, 4, 3, 2, 1, 9};
        REQUIRE(set.size() == 17);

        WHEN("Finding all 1's in the vector") {
            std::vector<decltype(set.begin())> results;
            trl::find_all_if(set.begin(), set.end(), std::back_inserter(results), [](int i) {return i == 1;});

            THEN("Four items are found at position 0, 7, 8 and 15") {
                REQUIRE(results.size() == 4);
                REQUIRE(*results[0] == 1);
                REQUIRE(*results[1] == 1);
                REQUIRE(*results[2] == 1);
                REQUIRE(*results[3] == 1);

                REQUIRE(results[0] != results[1]);
                REQUIRE(results[0] != results[2]);
                REQUIRE(results[0] != results[3]);
                REQUIRE(results[1] != results[2]);
                REQUIRE(results[1] != results[3]);
                REQUIRE(results[2] != results[3]);
            }
        }

        WHEN("Finding all 2's in the string") {
            std::vector<decltype(set.begin())> results;
            trl::find_all_if(set.begin(), set.end(), std::back_inserter(results), [](int i) {return i == 2;});

            THEN("Four items are found at position 1, 6, 9 and 14") {
                REQUIRE(results.size() == 4);
                REQUIRE(*results[0] == 2);
                REQUIRE(*results[1] == 2);
                REQUIRE(*results[2] == 2);
                REQUIRE(*results[3] == 2);

                REQUIRE(results[0] != results[1]);
                REQUIRE(results[0] != results[2]);
                REQUIRE(results[0] != results[3]);
                REQUIRE(results[1] != results[2]);
                REQUIRE(results[1] != results[3]);
                REQUIRE(results[2] != results[3]);
            }
        }

        WHEN("Finding all 3's in the string") {
            std::vector<decltype(set.begin())> results;
            trl::find_all_if(set.begin(), set.end(), std::back_inserter(results), [](int i) {return i == 3;});

            THEN("Four items are found at position 2, 5, 10 and 13") {
                REQUIRE(results.size() == 4);
                REQUIRE(*results[0] == 3);
                REQUIRE(*results[1] == 3);
                REQUIRE(*results[2] == 3);
                REQUIRE(*results[3] == 3);

                REQUIRE(results[0] != results[1]);
                REQUIRE(results[0] != results[2]);
                REQUIRE(results[0] != results[3]);
                REQUIRE(results[1] != results[2]);
                REQUIRE(results[1] != results[3]);
                REQUIRE(results[2] != results[3]);
            }
        }

        WHEN("Finding all 4's in the string") {
            std::vector<decltype(set.begin())> results;
            trl::find_all_if(set.begin(), set.end(), std::back_inserter(results), [](int i) {return i == 4;});

            THEN("Four items are found at position 3, 4, 11 and 12") {
                REQUIRE(results.size() == 4);
                REQUIRE(*results[0] == 4);
                REQUIRE(*results[1] == 4);
                REQUIRE(*results[2] == 4);
                REQUIRE(*results[3] == 4);

                REQUIRE(results[0] != results[1]);
                REQUIRE(results[0] != results[2]);
                REQUIRE(results[0] != results[3]);
                REQUIRE(results[1] != results[2]);
                REQUIRE(results[1] != results[3]);
                REQUIRE(results[2] != results[3]);
            }
        }

        WHEN("Finding all 9's in the string") {
            std::vector<decltype(set.begin())> results;
            trl::find_all_if(set.begin(), set.end(), std::back_inserter(results), [](int i) {return i == 9;});

            THEN("One items are found at position 16") {
                REQUIRE(results.size() == 1);
                REQUIRE(*results[0] == 9);
            }
        }

        WHEN("Finding all 0's in the string") {
            std::vector<decltype(set.begin())> results;
            trl::find_all_if(set.begin(), set.end(), std::back_inserter(results), [](int i) {return i == 0;});

            THEN("Zero items are found") {
                REQUIRE(results.size() == 0);
            }
        }
    }
    GIVEN("A std::unordered_multiset with integers '12344321123443219" ) {

        auto set = std::unordered_multiset<int> {1, 2, 3, 4, 4, 3, 2, 1, 1, 2, 3, 4, 4, 3, 2, 1, 9};
        REQUIRE(set.size() == 17);

        WHEN("Finding all 1's in the vector") {
            std::vector<decltype(set.begin())> results;
            trl::find_all_if(set.begin(), set.end(), std::back_inserter(results), [](int i) {return i == 1;});

            THEN("Four items are found at position 0, 7, 8 and 15") {
                REQUIRE(results.size() == 4);
                REQUIRE(*results[0] == 1);
                REQUIRE(*results[1] == 1);
                REQUIRE(*results[2] == 1);
                REQUIRE(*results[3] == 1);

                REQUIRE(results[0] != results[1]);
                REQUIRE(results[0] != results[2]);
                REQUIRE(results[0] != results[3]);
                REQUIRE(results[1] != results[2]);
                REQUIRE(results[1] != results[3]);
                REQUIRE(results[2] != results[3]);
            }
        }

        WHEN("Finding all 2's in the string") {
            std::vector<decltype(set.begin())> results;
            trl::find_all_if(set.begin(), set.end(), std::back_inserter(results), [](int i) {return i == 2;});

            THEN("Four items are found at position 1, 6, 9 and 14") {
                REQUIRE(results.size() == 4);
                REQUIRE(*results[0] == 2);
                REQUIRE(*results[1] == 2);
                REQUIRE(*results[2] == 2);
                REQUIRE(*results[3] == 2);

                REQUIRE(results[0] != results[1]);
                REQUIRE(results[0] != results[2]);
                REQUIRE(results[0] != results[3]);
                REQUIRE(results[1] != results[2]);
                REQUIRE(results[1] != results[3]);
                REQUIRE(results[2] != results[3]);
            }
        }

        WHEN("Finding all 3's in the string") {
            std::vector<decltype(set.begin())> results;
            trl::find_all_if(set.begin(), set.end(), std::back_inserter(results), [](int i) {return i == 3;});

            THEN("Four items are found at position 2, 5, 10 and 13") {
                REQUIRE(results.size() == 4);
                REQUIRE(*results[0] == 3);
                REQUIRE(*results[1] == 3);
                REQUIRE(*results[2] == 3);
                REQUIRE(*results[3] == 3);

                REQUIRE(results[0] != results[1]);
                REQUIRE(results[0] != results[2]);
                REQUIRE(results[0] != results[3]);
                REQUIRE(results[1] != results[2]);
                REQUIRE(results[1] != results[3]);
                REQUIRE(results[2] != results[3]);
            }
        }

        WHEN("Finding all 4's in the string") {
            std::vector<decltype(set.begin())> results;
            trl::find_all_if(set.begin(), set.end(), std::back_inserter(results), [](int i) {return i == 4;});

            THEN("Four items are found at position 3, 4, 11 and 12") {
                REQUIRE(results.size() == 4);
                REQUIRE(*results[0] == 4);
                REQUIRE(*results[1] == 4);
                REQUIRE(*results[2] == 4);
                REQUIRE(*results[3] == 4);

                REQUIRE(results[0] != results[1]);
                REQUIRE(results[0] != results[2]);
                REQUIRE(results[0] != results[3]);
                REQUIRE(results[1] != results[2]);
                REQUIRE(results[1] != results[3]);
                REQUIRE(results[2] != results[3]);
            }
        }

        WHEN("Finding all 9's in the string") {
            std::vector<decltype(set.begin())> results;
            trl::find_all_if(set.begin(), set.end(), std::back_inserter(results), [](int i) {return i == 9;});

            THEN("One items are found at position 16") {
                REQUIRE(results.size() == 1);
                REQUIRE(*results[0] == 9);
            }
        }

        WHEN("Finding all 0's in the string") {
            std::vector<decltype(set.begin())> results;
            trl::find_all_if(set.begin(), set.end(), std::back_inserter(results), [](int i) {return i == 0;});

            THEN("Zero items are found") {
                REQUIRE(results.size() == 0);
            }
        }
    }
    GIVEN("An empty std::string" ) {

        auto str = std::string();
        REQUIRE(str.size() == 0);

        WHEN("Finding all 'Z's in the string") {
            std::vector<decltype(str.begin())> results;
            trl::find_all_if(str.begin(), str.end(), std::back_inserter(results), [](char c) {return c == 'Z';});

            THEN("Zero items are found") {
                REQUIRE(results.size() == 0);
            }
        }
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
SCENARIO("Find all elements matching a certain criteria in a collection using find_all_if_not.", "[find_all_if_not]") {

    GIVEN("A std::string with characters'ABCDDCBAABCDDCBAX'" ) {

        auto str = std::string("ABCDDCBAABCDDCBAX");
        REQUIRE(str.size() == 17);

        WHEN("Finding all elements !='A' in the string") {
            std::vector<decltype(str.begin())> results;
            trl::find_all_if_not(str.begin(), str.end(), std::back_inserter(results), [](char c) {return c == 'A';});

            THEN("13 items are found at position 1, 2, 3, 4, 5, 6, 9, 10, 11, 12, 13, 14 and 16") {
                REQUIRE(results.size() == 13);
                REQUIRE(std::distance(str.begin(), results[0]) == 1);
                REQUIRE(std::distance(str.begin(), results[1]) == 2);
                REQUIRE(std::distance(str.begin(), results[2]) == 3);
                REQUIRE(std::distance(str.begin(), results[3]) == 4);
                REQUIRE(std::distance(str.begin(), results[4]) == 5);
                REQUIRE(std::distance(str.begin(), results[5]) == 6);
                REQUIRE(std::distance(str.begin(), results[6]) == 9);
                REQUIRE(std::distance(str.begin(), results[7]) == 10);
                REQUIRE(std::distance(str.begin(), results[8]) == 11);
                REQUIRE(std::distance(str.begin(), results[9]) == 12);
                REQUIRE(std::distance(str.begin(), results[10]) == 13);
                REQUIRE(std::distance(str.begin(), results[11]) == 14);
                REQUIRE(std::distance(str.begin(), results[12]) == 16);
                REQUIRE(*results[0] == 'B');
                REQUIRE(*results[1] == 'C');
                REQUIRE(*results[2] == 'D');
                REQUIRE(*results[3] == 'D');
                REQUIRE(*results[4] == 'C');
                REQUIRE(*results[5] == 'B');
                REQUIRE(*results[6] == 'B');
                REQUIRE(*results[7] == 'C');
                REQUIRE(*results[8] == 'D');
                REQUIRE(*results[9] == 'D');
                REQUIRE(*results[10] == 'C');
                REQUIRE(*results[11] == 'B');
                REQUIRE(*results[12] == 'X');
            }
        }
        WHEN("Finding all elements !='B' in the string") {
            std::vector<decltype(str.begin())> results;
            trl::find_all_if_not(str.begin(), str.end(), std::back_inserter(results), [](char c) {return c == 'B';});

            THEN("Four items are found at position 0, 2, 3, 4, 5, 7, 8, 10, 11, 12, 13, 15, 16") {
                REQUIRE(results.size() == 13);
                REQUIRE(std::distance(str.begin(), results[0]) == 0);
                REQUIRE(std::distance(str.begin(), results[1]) == 2);
                REQUIRE(std::distance(str.begin(), results[2]) == 3);
                REQUIRE(std::distance(str.begin(), results[3]) == 4);
                REQUIRE(std::distance(str.begin(), results[4]) == 5);
                REQUIRE(std::distance(str.begin(), results[5]) == 7);
                REQUIRE(std::distance(str.begin(), results[6]) == 8);
                REQUIRE(std::distance(str.begin(), results[7]) == 10);
                REQUIRE(std::distance(str.begin(), results[8]) == 11);
                REQUIRE(std::distance(str.begin(), results[9]) == 12);
                REQUIRE(std::distance(str.begin(), results[10]) == 13);
                REQUIRE(std::distance(str.begin(), results[11]) == 15);
                REQUIRE(std::distance(str.begin(), results[12]) == 16);
                REQUIRE(*results[0] == 'A');
                REQUIRE(*results[1] == 'C');
                REQUIRE(*results[2] == 'D');
                REQUIRE(*results[3] == 'D');
                REQUIRE(*results[4] == 'C');
                REQUIRE(*results[5] == 'A');
                REQUIRE(*results[6] == 'A');
                REQUIRE(*results[7] == 'C');
                REQUIRE(*results[8] == 'D');
                REQUIRE(*results[9] == 'D');
                REQUIRE(*results[10] == 'C');
                REQUIRE(*results[11] == 'A');
                REQUIRE(*results[12] == 'X');
            }
        }
        WHEN("Finding all 'C's in the string") {
            std::vector<decltype(str.begin())> results;
            trl::find_all_if_not(str.begin(), str.end(), std::back_inserter(results), [](char c) {return c == 'C';});

            THEN("Four items are found at position 2, 5, 10 and 13") {
                REQUIRE(results.size() == 4);
                REQUIRE(std::distance(str.begin(), results[0]) == 2);
                REQUIRE(std::distance(str.begin(), results[1]) == 5);
                REQUIRE(std::distance(str.begin(), results[2]) == 10);
                REQUIRE(std::distance(str.begin(), results[3]) == 13);
                REQUIRE(*results[0] == 'C');
                REQUIRE(*results[1] == 'C');
                REQUIRE(*results[2] == 'C');
                REQUIRE(*results[3] == 'C');
            }
        }

        WHEN("Finding all 'D's in the string") {
            std::vector<decltype(str.begin())> results;
            trl::find_all_if_not(str.begin(), str.end(), std::back_inserter(results), [](char c) {return c == 'D';});

            THEN("Four items are found at position 3, 4, 11 and 12") {
                REQUIRE(results.size() == 4);
                REQUIRE(std::distance(str.begin(), results[0]) == 3);
                REQUIRE(std::distance(str.begin(), results[1]) == 4);
                REQUIRE(std::distance(str.begin(), results[2]) == 11);
                REQUIRE(std::distance(str.begin(), results[3]) == 12);
                REQUIRE(*results[0] == 'D');
                REQUIRE(*results[1] == 'D');
                REQUIRE(*results[2] == 'D');
                REQUIRE(*results[3] == 'D');
            }
        }

        WHEN("Finding all 'X's in the string") {
            std::vector<decltype(str.begin())> results;
            trl::find_all_if_not(str.begin(), str.end(), std::back_inserter(results), [](char c) {return c == 'X';});

            THEN("One items are found at position 16") {
                REQUIRE(results.size() == 1);
                REQUIRE(std::distance(str.begin(), results[0]) == 16);
                REQUIRE(*results[0] == 'X');
            }
        }

        WHEN("Finding all 'Z's in the string") {
            std::vector<decltype(str.begin())> results;
            trl::find_all_if_not(str.begin(), str.end(), std::back_inserter(results), [](char c) {return c == 'Z';});

            THEN("Zero items are found") {
                REQUIRE(results.size() == 0);
            }
        }
    }
    GIVEN("A std::vector with integers '12344321123443219" ) {

        auto vec = std::vector<int> {1,2,3,4,4,3,2,1,1,2,3,4,4,3,2,1,9};
        REQUIRE(vec.size() == 17);

        WHEN("Finding all 1's in the vector") {
            std::vector<decltype(vec.begin())> results;
            trl::find_all_if_not(vec.begin(), vec.end(), std::back_inserter(results), [](int i) {return i == 1;});

            THEN("Four items are found at position 0, 7, 8 and 15") {
                REQUIRE(results.size() == 4);
                REQUIRE(std::distance(vec.begin(), results[0]) == 0);
                REQUIRE(std::distance(vec.begin(), results[1]) == 7);
                REQUIRE(std::distance(vec.begin(), results[2]) == 8);
                REQUIRE(std::distance(vec.begin(), results[3]) == 15);
                REQUIRE(*results[0] == 1);
                REQUIRE(*results[1] == 1);
                REQUIRE(*results[2] == 1);
                REQUIRE(*results[3] == 1);
            }
        }

        WHEN("Finding all 2's in the string") {
            std::vector<decltype(vec.begin())> results;
            trl::find_all_if_not(vec.begin(), vec.end(), std::back_inserter(results), [](int i) {return i == 2;});

            THEN("Four items are found at position 1, 6, 9 and 14") {
                REQUIRE(results.size() == 4);
                REQUIRE(std::distance(vec.begin(), results[0]) == 1);
                REQUIRE(std::distance(vec.begin(), results[1]) == 6);
                REQUIRE(std::distance(vec.begin(), results[2]) == 9);
                REQUIRE(std::distance(vec.begin(), results[3]) == 14);
                REQUIRE(*results[0] == 2);
                REQUIRE(*results[1] == 2);
                REQUIRE(*results[2] == 2);
                REQUIRE(*results[3] == 2);
            }
        }

        WHEN("Finding all 3's in the string") {
            std::vector<decltype(vec.begin())> results;
            trl::find_all_if_not(vec.begin(), vec.end(), std::back_inserter(results), [](int i) {return i == 3;});

            THEN("Four items are found at position 2, 5, 10 and 13") {
                REQUIRE(results.size() == 4);
                REQUIRE(std::distance(vec.begin(), results[0]) == 2);
                REQUIRE(std::distance(vec.begin(), results[1]) == 5);
                REQUIRE(std::distance(vec.begin(), results[2]) == 10);
                REQUIRE(std::distance(vec.begin(), results[3]) == 13);
                REQUIRE(*results[0] == 3);
                REQUIRE(*results[1] == 3);
                REQUIRE(*results[2] == 3);
                REQUIRE(*results[3] == 3);
            }
        }

        WHEN("Finding all 4's in the string") {
            std::vector<decltype(vec.begin())> results;
            trl::find_all_if_not(vec.begin(), vec.end(), std::back_inserter(results), [](int i) {return i == 4;});

            THEN("Four items are found at position 3, 4, 11 and 12") {
                REQUIRE(results.size() == 4);
                REQUIRE(std::distance(vec.begin(), results[0]) == 3);
                REQUIRE(std::distance(vec.begin(), results[1]) == 4);
                REQUIRE(std::distance(vec.begin(), results[2]) == 11);
                REQUIRE(std::distance(vec.begin(), results[3]) == 12);
                REQUIRE(*results[0] == 4);
                REQUIRE(*results[1] == 4);
                REQUIRE(*results[2] == 4);
                REQUIRE(*results[3] == 4);
            }
        }

        WHEN("Finding all 9's in the string") {
            std::vector<decltype(vec.begin())> results;
            trl::find_all_if_not(vec.begin(), vec.end(), std::back_inserter(results), [](int i) {return i == 9;});

            THEN("One items are found at position 16") {
                REQUIRE(results.size() == 1);
                REQUIRE(std::distance(vec.begin(), results[0]) == 16);
                REQUIRE(*results[0] == 9);
            }
        }

        WHEN("Finding all 0's in the string") {
            std::vector<decltype(vec.begin())> results;
            trl::find_all_if_not(vec.begin(), vec.end(), std::back_inserter(results), [](int i) {return i == 0;});

            THEN("Zero items are found") {
                REQUIRE(results.size() == 0);
            }
        }
    }
    GIVEN("A std::deque with integers '12344321123443219" ) {

        auto dqe = std::deque<int> {1, 2, 3, 4, 4, 3, 2, 1, 1, 2, 3, 4, 4, 3, 2, 1, 9};
        REQUIRE(dqe.size() == 17);

        WHEN("Finding all 1's in the vector") {
            std::vector<decltype(dqe.begin())> results;
            trl::find_all_if_not(dqe.begin(), dqe.end(), std::back_inserter(results), [](int i) {return i == 1;});

            THEN("Four items are found at position 0, 7, 8 and 15") {
                REQUIRE(results.size() == 4);
                REQUIRE(std::distance(dqe.begin(), results[0]) == 0);
                REQUIRE(std::distance(dqe.begin(), results[1]) == 7);
                REQUIRE(std::distance(dqe.begin(), results[2]) == 8);
                REQUIRE(std::distance(dqe.begin(), results[3]) == 15);
                REQUIRE(*results[0] == 1);
                REQUIRE(*results[1] == 1);
                REQUIRE(*results[2] == 1);
                REQUIRE(*results[3] == 1);
            }
        }

        WHEN("Finding all 2's in the string") {
            std::vector<decltype(dqe.begin())> results;
            trl::find_all_if_not(dqe.begin(), dqe.end(), std::back_inserter(results), [](int i) {return i == 2;});

            THEN("Four items are found at position 1, 6, 9 and 14") {
                REQUIRE(results.size() == 4);
                REQUIRE(std::distance(dqe.begin(), results[0]) == 1);
                REQUIRE(std::distance(dqe.begin(), results[1]) == 6);
                REQUIRE(std::distance(dqe.begin(), results[2]) == 9);
                REQUIRE(std::distance(dqe.begin(), results[3]) == 14);
                REQUIRE(*results[0] == 2);
                REQUIRE(*results[1] == 2);
                REQUIRE(*results[2] == 2);
                REQUIRE(*results[3] == 2);
            }
        }

        WHEN("Finding all 3's in the string") {
            std::vector<decltype(dqe.begin())> results;
            trl::find_all_if_not(dqe.begin(), dqe.end(), std::back_inserter(results), [](int i) {return i == 3;});

            THEN("Four items are found at position 2, 5, 10 and 13") {
                REQUIRE(results.size() == 4);
                REQUIRE(std::distance(dqe.begin(), results[0]) == 2);
                REQUIRE(std::distance(dqe.begin(), results[1]) == 5);
                REQUIRE(std::distance(dqe.begin(), results[2]) == 10);
                REQUIRE(std::distance(dqe.begin(), results[3]) == 13);
                REQUIRE(*results[0] == 3);
                REQUIRE(*results[1] == 3);
                REQUIRE(*results[2] == 3);
                REQUIRE(*results[3] == 3);
            }
        }

        WHEN("Finding all 4's in the string") {
            std::vector<decltype(dqe.begin())> results;
            trl::find_all_if_not(dqe.begin(), dqe.end(), std::back_inserter(results), [](int i) {return i == 4;});

            THEN("Four items are found at position 3, 4, 11 and 12") {
                REQUIRE(results.size() == 4);
                REQUIRE(std::distance(dqe.begin(), results[0]) == 3);
                REQUIRE(std::distance(dqe.begin(), results[1]) == 4);
                REQUIRE(std::distance(dqe.begin(), results[2]) == 11);
                REQUIRE(std::distance(dqe.begin(), results[3]) == 12);
                REQUIRE(*results[0] == 4);
                REQUIRE(*results[1] == 4);
                REQUIRE(*results[2] == 4);
                REQUIRE(*results[3] == 4);
            }
        }

        WHEN("Finding all 9's in the string") {
            std::vector<decltype(dqe.begin())> results;
            trl::find_all_if_not(dqe.begin(), dqe.end(), std::back_inserter(results), [](int i) {return i == 9;});

            THEN("One items are found at position 16") {
                REQUIRE(results.size() == 1);
                REQUIRE(std::distance(dqe.begin(), results[0]) == 16);
                REQUIRE(*results[0] == 9);
            }
        }

        WHEN("Finding all 0's in the string") {
            std::vector<decltype(dqe.begin())> results;
            trl::find_all_if_not(dqe.begin(), dqe.end(), std::back_inserter(results), [](int i) {return i == 0;});

            THEN("Zero items are found") {
                REQUIRE(results.size() == 0);
            }
        }
    }
    GIVEN("A std::array with integers '12344321123443219" ) {

        auto arr = std::array<int, 17> {1, 2, 3, 4, 4, 3, 2, 1, 1, 2, 3, 4, 4, 3, 2, 1, 9};
        REQUIRE(arr.size() == 17);

        WHEN("Finding all 1's in the vector") {
            std::vector<decltype(arr.begin())> results;
            trl::find_all_if_not(arr.begin(), arr.end(), std::back_inserter(results), [](int i) {return i == 1;});

            THEN("Four items are found at position 0, 7, 8 and 15") {
                REQUIRE(results.size() == 4);
                REQUIRE(std::distance(arr.begin(), results[0]) == 0);
                REQUIRE(std::distance(arr.begin(), results[1]) == 7);
                REQUIRE(std::distance(arr.begin(), results[2]) == 8);
                REQUIRE(std::distance(arr.begin(), results[3]) == 15);
                REQUIRE(*results[0] == 1);
                REQUIRE(*results[1] == 1);
                REQUIRE(*results[2] == 1);
                REQUIRE(*results[3] == 1);
            }
        }

        WHEN("Finding all 2's in the string") {
            std::vector<decltype(arr.begin())> results;
            trl::find_all_if_not(arr.begin(), arr.end(), std::back_inserter(results), [](int i) {return i == 2;});

            THEN("Four items are found at position 1, 6, 9 and 14") {
                REQUIRE(results.size() == 4);
                REQUIRE(std::distance(arr.begin(), results[0]) == 1);
                REQUIRE(std::distance(arr.begin(), results[1]) == 6);
                REQUIRE(std::distance(arr.begin(), results[2]) == 9);
                REQUIRE(std::distance(arr.begin(), results[3]) == 14);
                REQUIRE(*results[0] == 2);
                REQUIRE(*results[1] == 2);
                REQUIRE(*results[2] == 2);
                REQUIRE(*results[3] == 2);
            }
        }

        WHEN("Finding all 3's in the string") {
            std::vector<decltype(arr.begin())> results;
            trl::find_all_if_not(arr.begin(), arr.end(), std::back_inserter(results), [](int i) {return i == 3;});

            THEN("Four items are found at position 2, 5, 10 and 13") {
                REQUIRE(results.size() == 4);
                REQUIRE(std::distance(arr.begin(), results[0]) == 2);
                REQUIRE(std::distance(arr.begin(), results[1]) == 5);
                REQUIRE(std::distance(arr.begin(), results[2]) == 10);
                REQUIRE(std::distance(arr.begin(), results[3]) == 13);
                REQUIRE(*results[0] == 3);
                REQUIRE(*results[1] == 3);
                REQUIRE(*results[2] == 3);
                REQUIRE(*results[3] == 3);
            }
        }

        WHEN("Finding all 4's in the string") {
            std::vector<decltype(arr.begin())> results;
            trl::find_all_if_not(arr.begin(), arr.end(), std::back_inserter(results), [](int i) {return i == 4;});

            THEN("Four items are found at position 3, 4, 11 and 12") {
                REQUIRE(results.size() == 4);
                REQUIRE(std::distance(arr.begin(), results[0]) == 3);
                REQUIRE(std::distance(arr.begin(), results[1]) == 4);
                REQUIRE(std::distance(arr.begin(), results[2]) == 11);
                REQUIRE(std::distance(arr.begin(), results[3]) == 12);
                REQUIRE(*results[0] == 4);
                REQUIRE(*results[1] == 4);
                REQUIRE(*results[2] == 4);
                REQUIRE(*results[3] == 4);
            }
        }

        WHEN("Finding all 9's in the string") {
            std::vector<decltype(arr.begin())> results;
            trl::find_all_if_not(arr.begin(), arr.end(), std::back_inserter(results), [](int i) {return i == 9;});

            THEN("One items are found at position 16") {
                REQUIRE(results.size() == 1);
                REQUIRE(std::distance(arr.begin(), results[0]) == 16);
                REQUIRE(*results[0] == 9);
            }
        }

        WHEN("Finding all 0's in the string") {
            std::vector<decltype(arr.begin())> results;
            trl::find_all_if_not(arr.begin(), arr.end(), std::back_inserter(results), [](int i) {return i == 0;});

            THEN("Zero items are found") {
                REQUIRE(results.size() == 0);
            }
        }
    }
    GIVEN("A std::multiset with integers '12344321123443219" ) {

        auto set = std::multiset<int> {1, 2, 3, 4, 4, 3, 2, 1, 1, 2, 3, 4, 4, 3, 2, 1, 9};
        REQUIRE(set.size() == 17);

        WHEN("Finding all 1's in the vector") {
            std::vector<decltype(set.begin())> results;
            trl::find_all_if_not(set.begin(), set.end(), std::back_inserter(results), [](int i) {return i == 1;});

            THEN("Four items are found at position 0, 7, 8 and 15") {
                REQUIRE(results.size() == 4);
                REQUIRE(*results[0] == 1);
                REQUIRE(*results[1] == 1);
                REQUIRE(*results[2] == 1);
                REQUIRE(*results[3] == 1);

                REQUIRE(results[0] != results[1]);
                REQUIRE(results[0] != results[2]);
                REQUIRE(results[0] != results[3]);
                REQUIRE(results[1] != results[2]);
                REQUIRE(results[1] != results[3]);
                REQUIRE(results[2] != results[3]);
            }
        }

        WHEN("Finding all 2's in the string") {
            std::vector<decltype(set.begin())> results;
            trl::find_all_if_not(set.begin(), set.end(), std::back_inserter(results), [](int i) {return i == 2;});

            THEN("Four items are found at position 1, 6, 9 and 14") {
                REQUIRE(results.size() == 4);
                REQUIRE(*results[0] == 2);
                REQUIRE(*results[1] == 2);
                REQUIRE(*results[2] == 2);
                REQUIRE(*results[3] == 2);

                REQUIRE(results[0] != results[1]);
                REQUIRE(results[0] != results[2]);
                REQUIRE(results[0] != results[3]);
                REQUIRE(results[1] != results[2]);
                REQUIRE(results[1] != results[3]);
                REQUIRE(results[2] != results[3]);
            }
        }

        WHEN("Finding all 3's in the string") {
            std::vector<decltype(set.begin())> results;
            trl::find_all_if_not(set.begin(), set.end(), std::back_inserter(results), [](int i) {return i == 3;});

            THEN("Four items are found at position 2, 5, 10 and 13") {
                REQUIRE(results.size() == 4);
                REQUIRE(*results[0] == 3);
                REQUIRE(*results[1] == 3);
                REQUIRE(*results[2] == 3);
                REQUIRE(*results[3] == 3);

                REQUIRE(results[0] != results[1]);
                REQUIRE(results[0] != results[2]);
                REQUIRE(results[0] != results[3]);
                REQUIRE(results[1] != results[2]);
                REQUIRE(results[1] != results[3]);
                REQUIRE(results[2] != results[3]);
            }
        }

        WHEN("Finding all 4's in the string") {
            std::vector<decltype(set.begin())> results;
            trl::find_all_if_not(set.begin(), set.end(), std::back_inserter(results), [](int i) {return i == 4;});

            THEN("Four items are found at position 3, 4, 11 and 12") {
                REQUIRE(results.size() == 4);
                REQUIRE(*results[0] == 4);
                REQUIRE(*results[1] == 4);
                REQUIRE(*results[2] == 4);
                REQUIRE(*results[3] == 4);

                REQUIRE(results[0] != results[1]);
                REQUIRE(results[0] != results[2]);
                REQUIRE(results[0] != results[3]);
                REQUIRE(results[1] != results[2]);
                REQUIRE(results[1] != results[3]);
                REQUIRE(results[2] != results[3]);
            }
        }

        WHEN("Finding all 9's in the string") {
            std::vector<decltype(set.begin())> results;
            trl::find_all_if_not(set.begin(), set.end(), std::back_inserter(results), [](int i) {return i == 9;});

            THEN("One items are found at position 16") {
                REQUIRE(results.size() == 1);
                REQUIRE(*results[0] == 9);
            }
        }

        WHEN("Finding all 0's in the string") {
            std::vector<decltype(set.begin())> results;
            trl::find_all_if_not(set.begin(), set.end(), std::back_inserter(results), [](int i) {return i == 0;});

            THEN("Zero items are found") {
                REQUIRE(results.size() == 0);
            }
        }
    }
    GIVEN("A std::unordered_multiset with integers '12344321123443219" ) {

        auto set = std::unordered_multiset<int> {1, 2, 3, 4, 4, 3, 2, 1, 1, 2, 3, 4, 4, 3, 2, 1, 9};
        REQUIRE(set.size() == 17);

        WHEN("Finding all 1's in the vector") {
            std::vector<decltype(set.begin())> results;
            trl::find_all_if_not(set.begin(), set.end(), std::back_inserter(results), [](int i) {return i == 1;});

            THEN("Four items are found at position 0, 7, 8 and 15") {
                REQUIRE(results.size() == 4);
                REQUIRE(*results[0] == 1);
                REQUIRE(*results[1] == 1);
                REQUIRE(*results[2] == 1);
                REQUIRE(*results[3] == 1);

                REQUIRE(results[0] != results[1]);
                REQUIRE(results[0] != results[2]);
                REQUIRE(results[0] != results[3]);
                REQUIRE(results[1] != results[2]);
                REQUIRE(results[1] != results[3]);
                REQUIRE(results[2] != results[3]);
            }
        }

        WHEN("Finding all 2's in the string") {
            std::vector<decltype(set.begin())> results;
            trl::find_all_if_not(set.begin(), set.end(), std::back_inserter(results), [](int i) {return i == 2;});

            THEN("Four items are found at position 1, 6, 9 and 14") {
                REQUIRE(results.size() == 4);
                REQUIRE(*results[0] == 2);
                REQUIRE(*results[1] == 2);
                REQUIRE(*results[2] == 2);
                REQUIRE(*results[3] == 2);

                REQUIRE(results[0] != results[1]);
                REQUIRE(results[0] != results[2]);
                REQUIRE(results[0] != results[3]);
                REQUIRE(results[1] != results[2]);
                REQUIRE(results[1] != results[3]);
                REQUIRE(results[2] != results[3]);
            }
        }

        WHEN("Finding all 3's in the string") {
            std::vector<decltype(set.begin())> results;
            trl::find_all_if_not(set.begin(), set.end(), std::back_inserter(results), [](int i) {return i == 3;});

            THEN("Four items are found at position 2, 5, 10 and 13") {
                REQUIRE(results.size() == 4);
                REQUIRE(*results[0] == 3);
                REQUIRE(*results[1] == 3);
                REQUIRE(*results[2] == 3);
                REQUIRE(*results[3] == 3);

                REQUIRE(results[0] != results[1]);
                REQUIRE(results[0] != results[2]);
                REQUIRE(results[0] != results[3]);
                REQUIRE(results[1] != results[2]);
                REQUIRE(results[1] != results[3]);
                REQUIRE(results[2] != results[3]);
            }
        }

        WHEN("Finding all 4's in the string") {
            std::vector<decltype(set.begin())> results;
            trl::find_all_if_not(set.begin(), set.end(), std::back_inserter(results), [](int i) {return i == 4;});

            THEN("Four items are found at position 3, 4, 11 and 12") {
                REQUIRE(results.size() == 4);
                REQUIRE(*results[0] == 4);
                REQUIRE(*results[1] == 4);
                REQUIRE(*results[2] == 4);
                REQUIRE(*results[3] == 4);

                REQUIRE(results[0] != results[1]);
                REQUIRE(results[0] != results[2]);
                REQUIRE(results[0] != results[3]);
                REQUIRE(results[1] != results[2]);
                REQUIRE(results[1] != results[3]);
                REQUIRE(results[2] != results[3]);
            }
        }

        WHEN("Finding all 9's in the string") {
            std::vector<decltype(set.begin())> results;
            trl::find_all_if(set.begin(), set.end(), std::back_inserter(results), [](int i) {return i == 9;});

            THEN("One items are found at position 16") {
                REQUIRE(results.size() == 1);
                REQUIRE(*results[0] == 9);
            }
        }

        WHEN("Finding all 0's in the string") {
            std::vector<decltype(set.begin())> results;
            trl::find_all_if(set.begin(), set.end(), std::back_inserter(results), [](int i) {return i == 0;});

            THEN("Zero items are found") {
                REQUIRE(results.size() == 0);
            }
        }
    }
    GIVEN("An empty std::string" ) {

        auto str = std::string();
        REQUIRE(str.size() == 0);

        WHEN("Finding all 'Z's in the string") {
            std::vector<decltype(str.begin())> results;
            trl::find_all_if_not(str.begin(), str.end(), std::back_inserter(results), [](char c) {return c == 'Z';});

            THEN("Zero items are found") {
                REQUIRE(results.size() == 0);
            }
        }
    }
}