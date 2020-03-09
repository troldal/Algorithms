#include <iostream>
#include <vector>
#include <string>
#include <troldalgo.hpp>

using namespace std::string_literals;

int main() {

    std::string string = {'A','B','C','D','D','C','B','A','A','B','C','D','D','C','B','A','X'};
    std::string search = {'A','B'};

    std::cout << string << std::endl;
    std::cout << search << std::endl;

    auto result = trl::find_first_not_of(string.begin(), string.end(), search.begin(), search.end());

    std::cout << *result << std::endl;

    return 0;
}
