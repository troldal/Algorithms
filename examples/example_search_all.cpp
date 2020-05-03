#include <iostream>
#include <vector>
#include <string>
#include <troldalgo.hpp>

using namespace std::string_literals;

void example_search_all();
void example_search_all_with_pred();

int main() {

    std::cout << "trl::search_all example:" << std::endl;
    std::cout << "========================================" << std::endl;
    example_search_all();
    std::cout << std::endl;

    std::cout << "trl::search_all with predicate:" << std::endl;
    std::cout << "========================================" << std::endl;
    example_search_all_with_pred();
    std::cout << std::endl;

    return 0;
}

void example_search_all() {

    // ===== Initiate source string.
    std::string src = "=====SPLIT#####SPLIT@@@@@SPLIT";
    std::string sep = "SPLIT";

    // ===== initiate string to search, and append 1000000 copies of the source string
    std::string str;
    auto        itr = std::back_inserter(str);

    for (auto i = 0; i < 100; ++i)
        std::copy(src.begin(), src.end(), itr);

    // ===== Create a vector to hold the results (iterators to the found elements)
    std::vector<decltype(str.begin())> results;

    // ===== Find all occurences of the string 'SPLIT' and add iterators to the first character to the results vector.
    trl::search_all(str.begin(), str.end(), sep.begin(), sep.end(), std::back_inserter(results));

    // ===== Print results
    std::cout << "Size of string: " << str.size() << std::endl;
    std::cout << "Number of SPLIT's found: " << results.size() << std::endl;
    std::cout << "Character at index 0: " << *results[0] << std::endl;
}

void example_search_all_with_pred() {

    // ===== Initiate source string.
    std::string src = "=====SPLIT#####SPLIT@@@@@SPLIT";
    std::string sep = "SPLIT";

    // ===== initiate string to search, and append 1000000 copies of the source string
    std::string str;
    auto        itr = std::back_inserter(str);

    for (auto i = 0; i < 100; ++i)
        std::copy(src.begin(), src.end(), itr);

    // ===== Create a vector to hold the results (iterators to the found elements)
    std::vector<decltype(str.begin())> results;

    // ===== Find all occurences of the string 'SPLIT' and add iterators to the first character to the results vector.
    trl::search_all(str.begin(), str.end(), sep.begin(), sep.end(), std::back_inserter(results),
                    [&](decltype(*str.begin())& a,
                        decltype(*sep.begin())& b) {
                        return a == b;
                    });

    // ===== Print results
    std::cout << "Size of string: " << str.size() << std::endl;
    std::cout << "Number of SPLIT's found: " << results.size() << std::endl;
    std::cout << "Character at index 0: " << *results[0] << std::endl;
}
