//
// Created by Troldal on 15/11/2019.
//

#include <fstream>
#include <iostream>
#include <troldalgo.hpp>

int main() {

    std::ifstream f("/Users/Troldal/Desktop/Moby Dick.txt");
    auto str = std::string(std::istreambuf_iterator<char>(f),
                  std::istreambuf_iterator<char>());

    std::string sep("-.,;#!? ");

    auto vec = trl::split(str, trl::ByAnyElement(sep));

    for (auto& word : vec)
        std::cout << word << std::endl;
}
