//
// Created by Troldal on 08/03/2020.
//

#ifndef ALGORITHMS_TEST_CASE_HELPERS_HPP
#define ALGORITHMS_TEST_CASE_HELPERS_HPP


template<typename T>
struct CCaseDef1
{
    std::string      case_title;
    std::vector<T>   array;
    T                search_item;
    std::vector<int> item_locations;
};

template<typename T>
struct CCaseDef2
{
    std::string      case_title;
    std::vector<T>   array;
    std::vector<T>   search_item;
    std::vector<int> item_locations;
};

template<typename T>
inline void fill_char(T& target, const std::vector<char>& source) {

    if constexpr (std::is_same<T, std::multiset<char>>::value){
        for (auto c : source) target.insert(c);
    }
    else if constexpr (std::is_same<T, std::unordered_multiset<char>>::value){
        for (auto c : source) target.insert(c);
    }
    else {
        std::copy(source.begin(), source.end(), std::back_inserter(target));
    }
}

inline auto create_find_all_cases() {

    CCaseDef1<char> CaseDef1;
    CaseDef1.case_title = "Find all 'A's in the container";
    CaseDef1.array = {'A','B','C','D','D','C','B','A','A','B','C','D','D','C','B','A','X'};
    CaseDef1.search_item = 'A';
    CaseDef1.item_locations = {0, 7, 8, 15};

    CCaseDef1<char> CaseDef2;
    CaseDef2.case_title = "Find all 'B's in the container";
    CaseDef2.array = {'A','B','C','D','D','C','B','A','A','B','C','D','D','C','B','A','X'};
    CaseDef2.search_item = 'B';
    CaseDef2.item_locations = {1, 6, 9, 14};

    CCaseDef1<char> CaseDef3;
    CaseDef3.case_title = "Find all 'C's in the container";
    CaseDef3.array = {'A','B','C','D','D','C','B','A','A','B','C','D','D','C','B','A','X'};
    CaseDef3.search_item = 'C';
    CaseDef3.item_locations = {2, 5, 10, 13};

    CCaseDef1<char> CaseDef4;
    CaseDef4.case_title = "Find all 'D's in the container";
    CaseDef4.array = {'A','B','C','D','D','C','B','A','A','B','C','D','D','C','B','A','X'};
    CaseDef4.search_item = 'D';
    CaseDef4.item_locations = {3, 4, 11, 12};

    CCaseDef1<char> CaseDef5;
    CaseDef5.case_title = "Find all 'X's in the container";
    CaseDef5.array = {'A','B','C','D','D','C','B','A','A','B','C','D','D','C','B','A','X'};
    CaseDef5.search_item = 'X';
    CaseDef5.item_locations = {16};

    CCaseDef1<char> CaseDef6;
    CaseDef6.case_title = "Find all 'Z's in the container";
    CaseDef6.array = {'A','B','C','D','D','C','B','A','A','B','C','D','D','C','B','A','X'};
    CaseDef6.search_item = 'Z';
    CaseDef6.item_locations = {};

    CCaseDef1<char> CaseDef7;
    CaseDef7.case_title = "Find all 'Z's in an empty container";
    CaseDef7.array = {};
    CaseDef7.search_item = 'Z';
    CaseDef7.item_locations = {};

    std::vector<CCaseDef1<char>> cases;
    cases.emplace_back(CaseDef1);
    cases.emplace_back(CaseDef2);
    cases.emplace_back(CaseDef3);
    cases.emplace_back(CaseDef4);
    cases.emplace_back(CaseDef5);
    cases.emplace_back(CaseDef6);
    cases.emplace_back(CaseDef7);

    return cases;
}

inline auto create_find_first_cases() {

    CCaseDef2<char> CaseDef1;
    CaseDef1.case_title = "Find first char != 'A' in the container";
    CaseDef1.array = {'A','B','C','D','D','C','B','A','A','B','C','D','D','C','B','A','X'};
    CaseDef1.search_item = {'A'};
    CaseDef1.item_locations = {1};

    CCaseDef2<char> CaseDef2;
    CaseDef2.case_title = "Find first char != 'B' in the container";
    CaseDef2.array = {'A','B','C','D','D','C','B','A','A','B','C','D','D','C','B','A','X'};
    CaseDef2.search_item = {'B'};
    CaseDef2.item_locations = {0};

    CCaseDef2<char> CaseDef3;
    CaseDef3.case_title = "Find first char != {'A','B'} in the container";
    CaseDef3.array = {'A','B','C','D','D','C','B','A','A','B','C','D','D','C','B','A','X'};
    CaseDef3.search_item = {'A','B'};
    CaseDef3.item_locations = {2};

    CCaseDef2<char> CaseDef4;
    CaseDef4.case_title = "Find first char != {'A','B','C'} in the container";
    CaseDef4.array = {'A','B','C','D','D','C','B','A','A','B','C','D','D','C','B','A','X'};
    CaseDef4.search_item = {'A','B','C'};
    CaseDef4.item_locations = {3};

    CCaseDef2<char> CaseDef5;
    CaseDef5.case_title = "Find first char != {'A', 'B', 'C', 'D'} in the container";
    CaseDef5.array = {'A','B','C','D','D','C','B','A','A','B','C','D','D','C','B','A','X'};
    CaseDef5.search_item = {'A', 'B', 'C', 'D'};
    CaseDef5.item_locations = {16};

    CCaseDef2<char> CaseDef6;
    CaseDef6.case_title = "Find first char != 'Z' in the container";
    CaseDef6.array = {'Z','Z','Z','Z','Z','Z','Z','Z','Z','Z','Z','Z','Z','Z','Z','Z','Z'};
    CaseDef6.search_item = {'Z'};
    CaseDef6.item_locations = {};

    CCaseDef2<char> CaseDef7;
    CaseDef7.case_title = "Find first char != 'Z' in an empty container";
    CaseDef7.array = {};
    CaseDef7.search_item = {'Z'};
    CaseDef7.item_locations = {};

    std::vector<CCaseDef2<char>> cases;
    cases.emplace_back(CaseDef1);
    cases.emplace_back(CaseDef2);
    cases.emplace_back(CaseDef3);
    cases.emplace_back(CaseDef4);
    cases.emplace_back(CaseDef5);
    cases.emplace_back(CaseDef6);
    cases.emplace_back(CaseDef7);

    return cases;
}

inline auto create_find_all_of_cases() {

    CCaseDef2<char> CaseDef1;
    CaseDef1.case_title = "Find all char == 'A' in the container";
    CaseDef1.array = {'A','B','C','D','D','C','B','A','A','B','C','D','D','C','B','A','X'};
    CaseDef1.search_item = {'A'};
    CaseDef1.item_locations = {0, 7, 8, 15};

    CCaseDef2<char> CaseDef2;
    CaseDef2.case_title = "Find all char == 'B' in the container";
    CaseDef2.array = {'A','B','C','D','D','C','B','A','A','B','C','D','D','C','B','A','X'};
    CaseDef2.search_item = {'B'};
    CaseDef2.item_locations = {1, 6, 9, 14};

    CCaseDef2<char> CaseDef3;
    CaseDef3.case_title = "Find all char == {'A','B'} in the container";
    CaseDef3.array = {'A','B','C','D','D','C','B','A','A','B','C','D','D','C','B','A','X'};
    CaseDef3.search_item = {'A','B'};
    CaseDef3.item_locations = {0, 1, 6, 7, 8, 9, 14, 15};

    CCaseDef2<char> CaseDef4;
    CaseDef4.case_title = "Find all char == {'A','B','C'} in the container";
    CaseDef4.array = {'A','B','C','D','D','C','B','A','A','B','C','D','D','C','B','A','X'};
    CaseDef4.search_item = {'A','B','C'};
    CaseDef4.item_locations = {0, 1, 2, 5, 6, 7, 8, 9, 10, 13, 14, 15};

    CCaseDef2<char> CaseDef5;
    CaseDef5.case_title = "Find all char == {'A', 'B', 'C', 'D'} in the container";
    CaseDef5.array = {'A','B','C','D','D','C','B','A','A','B','C','D','D','C','B','A','X'};
    CaseDef5.search_item = {'A', 'B', 'C', 'D'};
    CaseDef5.item_locations = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

    CCaseDef2<char> CaseDef6;
    CaseDef6.case_title = "Find all char == 'Z' in the container";
    CaseDef6.array = {'A','B','C','D','D','C','B','A','A','B','C','D','D','C','B','A','X'};
    CaseDef6.search_item = {'Z'};
    CaseDef6.item_locations = {};

    CCaseDef2<char> CaseDef7;
    CaseDef7.case_title = "Find all char == 'Z' in an empty container";
    CaseDef7.array = {};
    CaseDef7.search_item = {'Z'};
    CaseDef7.item_locations = {};

    std::vector<CCaseDef2<char>> cases;
    cases.emplace_back(CaseDef1);
    cases.emplace_back(CaseDef2);
    cases.emplace_back(CaseDef3);
    cases.emplace_back(CaseDef4);
    cases.emplace_back(CaseDef5);
    cases.emplace_back(CaseDef6);
    cases.emplace_back(CaseDef7);

    return cases;
}

#endif //ALGORITHMS_TEST_CASE_HELPERS_HPP
