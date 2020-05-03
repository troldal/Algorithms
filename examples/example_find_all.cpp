#include <iostream>
#include <vector>
#include <string>
#include <troldalgo.hpp>

using namespace std::string_literals;

void example_find_all();
void example_find_all_if();
void example_find_all_if_not();
void example_find_all_of();
void example_find_all_of_with_pred();
void example_find_all_not_of();
void example_find_all_not_of_with_pred();

int main() {

    std::cout << "trl::find_all example:" << std::endl;
    std::cout << "========================================" << std::endl;
    example_find_all();
    std::cout << std::endl;

    std::cout << "trl::find_all_if example:" << std::endl;
    std::cout << "========================================" << std::endl;
    example_find_all_if();
    std::cout << std::endl;

    std::cout << "trl::find_all_if_not example:" << std::endl;
    std::cout << "========================================" << std::endl;
    example_find_all_if_not();
    std::cout << std::endl;

    std::cout << "trl::find_all_of example:" << std::endl;
    std::cout << "========================================" << std::endl;
    example_find_all_of();
    std::cout << std::endl;

    std::cout << "trl::find_all_of example:" << std::endl;
    std::cout << "========================================" << std::endl;
    example_find_all_of_with_pred();
    std::cout << std::endl;

    std::cout << "trl::find_all_of example:" << std::endl;
    std::cout << "========================================" << std::endl;
    example_find_all_not_of();
    std::cout << std::endl;

    std::cout << "trl::find_all_of example:" << std::endl;
    std::cout << "========================================" << std::endl;
    example_find_all_not_of_with_pred();

    return 0;
}

void example_find_all() {

    // ===== Initiate source string.
    std::string src = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // ===== initiate string to search, and append 1000000 copies of the source string
    std::string str;
    auto        itr = std::back_inserter(str);

    for (auto i = 0; i < 100; ++i)
        std::copy(src.begin(), src.end(), itr);

    // ===== Create a vector to hold the results (iterators to the found elements)
    std::vector<decltype(str.begin())> results;

    // ===== Find all occurences of the character 'Z' and add iterators to those elements to the results vector.
    trl::find_all(str.begin(), str.end(), std::back_inserter(results), 'Z');

    // ===== Print results
    std::cout << "Size of string: " << str.size() << std::endl;
    std::cout << "Number of Z's found: " << results.size() << std::endl;
    std::cout << "Character at index 0: " << *results[0] << std::endl;
}

void example_find_all_if() {

    std::string src = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string str;
    auto itr = std::back_inserter(str);

    for (auto i = 0; i < 100; ++i)
        std::copy(src.begin(), src.end(), itr);

    std::vector<decltype(str.begin())> results;
    trl::find_all_if(str.begin(), str.end(), std::back_inserter(results), [](decltype(*str.begin()) c) {
        return c == 'Z';
    });

    std::cout << "Size of string: " << str.size() << std::endl;
    std::cout << "Number of Z's found: " << results.size() << std::endl;
    std::cout << "Character at index 0: " << *results[0] << std::endl;
}

void example_find_all_if_not() {
    std::string src = "AB";
    std::string str;
    auto itr = std::back_inserter(str);

    for (auto i = 0; i < 100; ++i)
        std::copy(src.begin(), src.end(), itr);

    std::vector<decltype(str.begin())> results;
    trl::find_all_if_not(str.begin(), str.end(), std::back_inserter(results), [](decltype(*str.begin()) c) {
        return c == 'A';
    });

    std::cout << "Size of string: " << str.size() << std::endl;
    std::cout << "Number of B's found: " << results.size() << std::endl;
    std::cout << "Character at index 0: " << *results[0] << std::endl;
}

void example_find_all_of() {
    std::string src = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string str;
    auto itr = std::back_inserter(str);

    for (auto i = 0; i < 100; ++i)
        std::copy(src.begin(), src.end(), itr);

    std::string s = "AGQX";
    std::vector<decltype(str.begin())> results;
    trl::find_all_of(str.begin(), str.end(), s.begin(), s.end(), std::back_inserter(results));

    std::cout << "Size of string: " << str.size() << std::endl;
    std::cout << "Number of characters found: " << results.size() << std::endl;
    std::cout << "Character at index 0: " << *results[0] << std::endl;
    std::cout << "Character at index 1: " << *results[1] << std::endl;
    std::cout << "Character at index 2: " << *results[2] << std::endl;
    std::cout << "Character at index 3: " << *results[3] << std::endl;
}

void example_find_all_of_with_pred() {
    //TODO: To be implemented
}

void example_find_all_not_of() {
    //TODO: To be implemented
}

void example_find_all_not_of_with_pred() {
    //TODO: To be implemented
}