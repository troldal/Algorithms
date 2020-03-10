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

TEMPLATE_TEST_CASE("Split a container using ByElement",
                   "[Split ByElement]",
                   (std::string),
                   (std::vector<char>),
                   (std::deque<char>)) {

    // ===== Run tests for the current case definition
    SECTION("Split ByElement: Case 1") {
        // ===== Create container and populate it with data from the current case definition.
        TestType container = {'H', 'E', 'L', 'L', 'O', ';', 'H', 'E', 'L', 'L', 'O', ';', 'H', 'E', 'L', 'L', 'O'};

        // ===== Run the find_all_if algorithm and check that the number of found elements are correct.
        std::vector<TestType> results;
        trl::split(container, std::back_inserter(results), trl::ByElement(';'));

        REQUIRE(results.size() == 3);
        REQUIRE(results[0] == TestType{'H', 'E', 'L', 'L', 'O'});
        REQUIRE(results[1] == TestType{'H', 'E', 'L', 'L', 'O'});
        REQUIRE(results[2] == TestType{'H', 'E', 'L', 'L', 'O'});
    }

        // ===== Run tests for the current case definition
    SECTION("Split ByElement: Case 2") {
        // ===== Create container and populate it with data from the current case definition.
        TestType container = {'H', 'E', 'L', 'L', 'O', ';', 'H', 'E', 'L', 'L', 'O', ';', 'H', 'E', 'L', 'L', 'O', ';'};

        // ===== Run the find_all_if algorithm and check that the number of found elements are correct.
        std::vector<TestType> results;
        trl::split(container, std::back_inserter(results), trl::ByElement(';'));

        REQUIRE(results.size() == 4);
        REQUIRE(results[0] == TestType{'H', 'E', 'L', 'L', 'O'});
        REQUIRE(results[1] == TestType{'H', 'E', 'L', 'L', 'O'});
        REQUIRE(results[2] == TestType{'H', 'E', 'L', 'L', 'O'});
        REQUIRE(results[3] == TestType{});
    }


        // ===== Run tests for the current case definition
    SECTION("Split ByElement: Case 3") {
        // ===== Create container and populate it with data from the current case definition.
        TestType container = {';', 'H', 'E', 'L', 'L', 'O', ';', 'H', 'E', 'L', 'L', 'O', ';', 'H', 'E', 'L', 'L', 'O',
                              ';'};

        // ===== Run the find_all_if algorithm and check that the number of found elements are correct.
        std::vector<TestType> results;
        trl::split(container, std::back_inserter(results), trl::ByElement(';'));

        REQUIRE(results.size() == 5);
        REQUIRE(results[0] == TestType{});
        REQUIRE(results[1] == TestType{'H', 'E', 'L', 'L', 'O'});
        REQUIRE(results[2] == TestType{'H', 'E', 'L', 'L', 'O'});
        REQUIRE(results[3] == TestType{'H', 'E', 'L', 'L', 'O'});
        REQUIRE(results[4] == TestType{});
    }

        // ===== Run tests for the current case definition
    SECTION("Split ByElement: Case 4") {
        // ===== Create container and populate it with data from the current case definition.
        TestType container = {';', 'H', 'E', 'L', 'L', 'O', ';', ';', 'H', 'E', 'L', 'L', 'O', ';', 'H', 'E', 'L', 'L',
                              'O', ';'};

        // ===== Run the find_all_if algorithm and check that the number of found elements are correct.
        std::vector<TestType> results;
        trl::split(container, std::back_inserter(results), trl::ByElement(';'));

        REQUIRE(results.size() == 6);
        REQUIRE(results[0].empty());
        REQUIRE(results[1] == TestType{'H', 'E', 'L', 'L', 'O'});
        REQUIRE(results[2].empty());
        REQUIRE(results[3] == TestType{'H', 'E', 'L', 'L', 'O'});
        REQUIRE(results[4] == TestType{'H', 'E', 'L', 'L', 'O'});
        REQUIRE(results[5].empty());
    }
}

TEMPLATE_TEST_CASE("Split a container using BySequence",
                   "[Split BySequence]",
                   (std::string),
                   (std::vector<char>),
                   (std::deque<char>)) {

    // ===== Run tests for the current case definition
    SECTION("Split BySequence: Case 1") {
        // ===== Create container and populate it with data from the current case definition.
        TestType container = {'H', 'E', 'L', 'L', 'O', '#', '#', 'H', 'E', 'L', 'L', 'O', '#', '#', 'H', 'E', 'L', 'L',
                              'O'};

        // ===== Run the find_all_if algorithm and check that the number of found elements are correct.
        std::vector<TestType> results;
        trl::split(container, std::back_inserter(results), trl::BySequence(TestType{'#', '#'}));

        REQUIRE(results.size() == 3);
        REQUIRE(results[0] == TestType{'H', 'E', 'L', 'L', 'O'});
        REQUIRE(results[1] == TestType{'H', 'E', 'L', 'L', 'O'});
        REQUIRE(results[2] == TestType{'H', 'E', 'L', 'L', 'O'});
    }

        // ===== Run tests for the current case definition
    SECTION("Split BySequence: Case 2") {
        // ===== Create container and populate it with data from the current case definition.
        TestType container = {'H', 'E', 'L', 'L', 'O', '#', '#', 'H', 'E', 'L', 'L', 'O', '#', '#', 'H', 'E', 'L', 'L',
                              'O', '#', '#'};

        // ===== Run the find_all_if algorithm and check that the number of found elements are correct.
        std::vector<TestType> results;
        trl::split(container, std::back_inserter(results), trl::BySequence(TestType{'#', '#'}));

        REQUIRE(results.size() == 4);
        REQUIRE(results[0] == TestType{'H', 'E', 'L', 'L', 'O'});
        REQUIRE(results[1] == TestType{'H', 'E', 'L', 'L', 'O'});
        REQUIRE(results[2] == TestType{'H', 'E', 'L', 'L', 'O'});
        REQUIRE(results[3] == TestType{});
    }


        // ===== Run tests for the current case definition
    SECTION("Split BySequence: Case 3") {
        // ===== Create container and populate it with data from the current case definition.
        TestType container = {'#', '#', 'H', 'E', 'L', 'L', 'O', '#', '#', 'H', 'E', 'L', 'L', 'O', '#', '#', 'H', 'E',
                              'L', 'L', 'O',
                              '#', '#'};

        // ===== Run the find_all_if algorithm and check that the number of found elements are correct.
        std::vector<TestType> results;
        trl::split(container, std::back_inserter(results), trl::BySequence(TestType{'#', '#'}));

        REQUIRE(results.size() == 5);
        REQUIRE(results[0] == TestType{});
        REQUIRE(results[1] == TestType{'H', 'E', 'L', 'L', 'O'});
        REQUIRE(results[2] == TestType{'H', 'E', 'L', 'L', 'O'});
        REQUIRE(results[3] == TestType{'H', 'E', 'L', 'L', 'O'});
        REQUIRE(results[4] == TestType{});
    }

        // ===== Run tests for the current case definition
    SECTION("Split BySequence: Case 4") {
        // ===== Create container and populate it with data from the current case definition.
        TestType container = {'#', '#', 'H', 'E', 'L', 'L', 'O', '#', '#', '#', '#', 'H', 'E', 'L', 'L', 'O', '#', '#',
                              'H', 'E', 'L', 'L',
                              'O', '#', '#'};

        // ===== Run the find_all_if algorithm and check that the number of found elements are correct.
        std::vector<TestType> results;
        trl::split(container, std::back_inserter(results), trl::BySequence(TestType{'#', '#'}));

        REQUIRE(results.size() == 6);
        REQUIRE(results[0].empty());
        REQUIRE(results[1] == TestType{'H', 'E', 'L', 'L', 'O'});
        REQUIRE(results[2].empty());
        REQUIRE(results[3] == TestType{'H', 'E', 'L', 'L', 'O'});
        REQUIRE(results[4] == TestType{'H', 'E', 'L', 'L', 'O'});
        REQUIRE(results[5].empty());
    }

}

TEMPLATE_TEST_CASE("Split a container using ByAnyElement",
                   "[Split ByAnyElement]",
                   (std::string),
                   (std::vector<char>),
                   (std::deque<char>)) {

    // ===== Run tests for the current case definition
    SECTION("Split ByAnyElement: Case 1") {
        // ===== Create container and populate it with data from the current case definition.
        TestType container = {'H', 'E', 'L', 'L', 'O', ';', 'H', 'E', 'L', 'L', 'O', ':', 'H', 'E', 'L', 'L',
                              'O'};

        // ===== Run the find_all_if algorithm and check that the number of found elements are correct.
        std::vector<TestType> results;
        trl::split(container, std::back_inserter(results), trl::ByAnyElement(TestType{':', ';', ',', '.'}));

        REQUIRE(results.size() == 3);
        REQUIRE(results[0] == TestType{'H', 'E', 'L', 'L', 'O'});
        REQUIRE(results[1] == TestType{'H', 'E', 'L', 'L', 'O'});
        REQUIRE(results[2] == TestType{'H', 'E', 'L', 'L', 'O'});
    }

        // ===== Run tests for the current case definition
    SECTION("Split ByAnyElement: Case 2") {
        // ===== Create container and populate it with data from the current case definition.
        TestType container = {'H', 'E', 'L', 'L', 'O', '.', 'H', 'E', 'L', 'L', 'O', ',', 'H', 'E', 'L', 'L',
                              'O', ';'};

        // ===== Run the find_all_if algorithm and check that the number of found elements are correct.
        std::vector<TestType> results;
        trl::split(container, std::back_inserter(results), trl::ByAnyElement(TestType{':', ';', ',', '.'}));

        REQUIRE(results.size() == 4);
        REQUIRE(results[0] == TestType{'H', 'E', 'L', 'L', 'O'});
        REQUIRE(results[1] == TestType{'H', 'E', 'L', 'L', 'O'});
        REQUIRE(results[2] == TestType{'H', 'E', 'L', 'L', 'O'});
        REQUIRE(results[3] == TestType{});
    }


        // ===== Run tests for the current case definition
    SECTION("Split ByAnyElement: Case 3") {
        // ===== Create container and populate it with data from the current case definition.
        TestType container = {':', 'H', 'E', 'L', 'L', 'O', '.', 'H', 'E', 'L', 'L', 'O', ';', 'H', 'E',
                              'L', 'L', 'O',
                              ','};

        // ===== Run the find_all_if algorithm and check that the number of found elements are correct.
        std::vector<TestType> results;
        trl::split(container, std::back_inserter(results), trl::ByAnyElement(TestType{':', ';', ',', '.'}));

        REQUIRE(results.size() == 5);
        REQUIRE(results[0] == TestType{});
        REQUIRE(results[1] == TestType{'H', 'E', 'L', 'L', 'O'});
        REQUIRE(results[2] == TestType{'H', 'E', 'L', 'L', 'O'});
        REQUIRE(results[3] == TestType{'H', 'E', 'L', 'L', 'O'});
        REQUIRE(results[4] == TestType{});
    }

        // ===== Run tests for the current case definition
    SECTION("Split ByAnyElement: Case 4") {
        // ===== Create container and populate it with data from the current case definition.
        TestType container = {';', 'H', 'E', 'L', 'L', 'O', ':', ',', 'H', 'E', 'L', 'L', 'O', '.',
                              'H', 'E', 'L', 'L',
                              'O', ';'};

        // ===== Run the find_all_if algorithm and check that the number of found elements are correct.
        std::vector<TestType> results;
        trl::split(container, std::back_inserter(results), trl::ByAnyElement(TestType{':', ';', ',', '.'}));

        REQUIRE(results.size() == 6);
        REQUIRE(results[0].empty());
        REQUIRE(results[1] == TestType{'H', 'E', 'L', 'L', 'O'});
        REQUIRE(results[2].empty());
        REQUIRE(results[3] == TestType{'H', 'E', 'L', 'L', 'O'});
        REQUIRE(results[4] == TestType{'H', 'E', 'L', 'L', 'O'});
        REQUIRE(results[5].empty());
    }
}

TEMPLATE_TEST_CASE("Split a container using ByLength",
                   "[Split ByLength]",
                   (std::string),
                   (std::vector<char>),
                   (std::deque<char>)) {

    // ===== Run tests for the current case definition
    SECTION("Split ByLength: Case 1") {
        // ===== Create container and populate it with data from the current case definition.
        TestType container = {'H', 'E', 'L', 'L', 'O', 'Y', 'E', 'L', 'L', 'O', 'G', 'E', 'L', 'L',
                              'O'};

        // ===== Run the find_all_if algorithm and check that the number of found elements are correct.
        std::vector<TestType> results;
        trl::split(container, std::back_inserter(results), trl::ByLength(5));

        REQUIRE(results.size() == 3);
        REQUIRE(results[0] == TestType{'H', 'E', 'L', 'L', 'O'});
        REQUIRE(results[1] == TestType{'Y', 'E', 'L', 'L', 'O'});
        REQUIRE(results[2] == TestType{'G', 'E', 'L', 'L', 'O'});
    }

        // ===== Run tests for the current case definition
    SECTION("Split ByLength: Case 2") {
        // ===== Create container and populate it with data from the current case definition.
        TestType container = {'H', 'E', 'L', 'L', 'O', 'H', 'E', 'L', 'L', 'O', 'H', 'E', 'L', 'L',
                              'O', 'H'};

        // ===== Run the find_all_if algorithm and check that the number of found elements are correct.
        std::vector<TestType> results;
        trl::split(container, std::back_inserter(results), trl::ByLength(5));

        REQUIRE(results.size() == 4);
        REQUIRE(results[0] == TestType{'H', 'E', 'L', 'L', 'O'});
        REQUIRE(results[1] == TestType{'H', 'E', 'L', 'L', 'O'});
        REQUIRE(results[2] == TestType{'H', 'E', 'L', 'L', 'O'});
        REQUIRE(results[3] == TestType{'H'});
    }


        // ===== Run tests for the current case definition
    SECTION("Split ByLength: Case 3") {
        // ===== Create container and populate it with data from the current case definition.
        TestType container = {'H', 'E', 'L', 'L', 'O', 'H', 'E', 'L', 'L', 'O', 'H', 'E',
                              'L', 'L', 'O', 'H', 'E'};

        // ===== Run the find_all_if algorithm and check that the number of found elements are correct.
        std::vector<TestType> results;
        trl::split(container, std::back_inserter(results), trl::ByLength(5));

        REQUIRE(results.size() == 4);
        REQUIRE(results[0] == TestType{'H', 'E', 'L', 'L', 'O'});
        REQUIRE(results[1] == TestType{'H', 'E', 'L', 'L', 'O'});
        REQUIRE(results[2] == TestType{'H', 'E', 'L', 'L', 'O'});
        REQUIRE(results[3] == TestType{'H', 'E'});
    }

        // ===== Run tests for the current case definition
    SECTION("Split ByLength: Case 4") {
        // ===== Create container and populate it with data from the current case definition.
        TestType container = {'H', 'E', 'L', 'L', 'O', 'H', 'E', 'L', 'L', 'O',
                              'H', 'E', 'L', 'L',
                              'O', 'H', 'E', 'L'};

        // ===== Run the find_all_if algorithm and check that the number of found elements are correct.
        std::vector<TestType> results;
        trl::split(container, std::back_inserter(results), trl::ByLength(5));

        REQUIRE(results.size() == 4);
        REQUIRE(results[0] == TestType{'H', 'E', 'L', 'L', 'O'});
        REQUIRE(results[1] == TestType{'H', 'E', 'L', 'L', 'O'});
        REQUIRE(results[2] == TestType{'H', 'E', 'L', 'L', 'O'});
        REQUIRE(results[3] == TestType{'H', 'E', 'L'});
    }
}
