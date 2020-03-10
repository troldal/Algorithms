#include <iostream>
#include <vector>
#include <string>
#include <troldalgo.hpp>

using namespace std::string_literals;

int main() {

    std::string str("HELLO;HELLO;HELLO;");
    //std::string str("12345123451234512345");
    std::vector<std::string> vec;
    trl::split(str, std::back_inserter(vec), trl::ByElement(';'));

    for (auto& word : vec)
        std::cout << word << std::endl;

    return 0;
}
