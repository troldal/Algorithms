//
// Created by Troldal on 15/11/2019.
//

#include <fstream>
#include <iostream>
#include <troldalgo.hpp>

int main() {

    std::ifstream f("/Users/Troldal/Desktop/Moby Dick.txt");
    auto          str = std::string(std::istreambuf_iterator<char>(f),
                                    std::istreambuf_iterator<char>());

    std::string              sep("-.,;#!? \n\t\r");
    std::vector<std::string> output;
    trl::split(str, std::back_inserter(output), trl::ByAnyElement(sep));

    for (auto& word : output)
        std::cout << word << std::endl;

    std::cout << "Count: " << output.size() << std::endl;
}
