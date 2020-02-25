//
// Created by Troldal on 2019-03-10.
//

#include <iostream>
#include <vector>
#include <string>
#include <troldalgo.hpp>

int main() {

    //std::string str("1234DIV1234DIVDIV1234DIV1234DIV5DIV");
    std::string str("12345123451234512345123");
    std::vector<std::string> vec;

    trl::split(str, std::back_inserter(vec), trl::ByLength(5));

    for (auto& word : vec)
        std::cout << word << std::endl;

    return 0;
}
