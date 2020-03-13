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

    return 0;
}

void example_find_all() {

    std::string src = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string str;
    auto itr = std::back_inserter(str);

    for (auto i = 0; i < 1000000; ++i)
        std::copy(src.begin(), src.end(), itr);

    std::vector<decltype(str.begin())> results;
    trl::find_all(str.begin(), str.end(), std::back_inserter(results), 'Z');

    std::cout << "Size of string: " << str.size() << std::endl;
    std::cout << "Number of Z's found: " << results.size() << std::endl;
    std::cout << "Character at index 0: " << *results[0] << std::endl;
}

void example_find_all_if() {

    std::string src = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string str;
    auto itr = std::back_inserter(str);

    for (auto i = 0; i < 1000000; ++i)
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

    for (auto i = 0; i < 1000000; ++i)
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

    for (auto i = 0; i < 1000000; ++i)
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
