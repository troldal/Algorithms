# Troldalgo
Troldalgo is a collection of useful algorithms not present in the C++ Standard Library. They are contained within namespace `trl`.

## Table of Contents
* [Motivation](#Motivation)
* [Generic Algorithms](#Generic-Algorithms)
    * [trl::find_first_not_of](#trlfind_first_not_of)
    * [trl::find_all](#trlfind_all)
    * [trl::find_all_if](#trlfind_all_if)
    * [trl::find_all_if_not](#trlfind_all_if_not)
    * [trl::find_all_of](#trlfind_all_of)
    * [trl::find_all_not_of](#trlfind_all_not_of)
    * [trl::search_all](#trlsearch_all)
* [Special Purpose Algorithms](#Special-Purpose-Algorithms)
* [Parallel Algorithms](#Parallel-Algorithms)
* [Setup](#Setup)
* [Status](#Status)
* [Contact](#Contact)

## Motivation
The motivation for the algorithms included in Troldalgo os found in Sean Parent's "[C++ Seasoning](https://youtu.be/W2tWOdzgXHA)", where it is stated that raw loops should be avoided. 

In some situations, I could not find a solution that did not involve a raw loop. For example, if I wanted to find all elements in a vector that has a certain value or matches a certain predicate. Using std::find only finds the first element. 

For this reason, I wanted to develop a few lightweight algorithms that could bridge the gap. Internally, they do use raw loops combined with the algorithms in the `<algorithm>` header. However, client code will be able to use these algorithms without resorting to raw loops.

I have developed these algorithms mostly for my own benefit, but uploaded them to GitHub in case that others may find them useful.

## Generic Algorithms
The generic algorithms are simple, general-purpose algorithms that have been developed to augment the find/search algorithms in the `<algorithm>` header.

### trl::find_first_not_of

### trl::find_all
The trl::find_all algorithm finds elements with a certain value in a container.

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <troldalgo.hpp>

int main() {

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
    
    return 0;

}

```

### trl::find_all_if

### trl::find_all_if_not

### trl::find_all_of

### trl::find_all_not_of

### trl::search_all


## Special Purpose Algorithms
The special purpose algorithms are more complex than the generic algorithms. Currently, only one algorithm, `trl::split`, is included.

### trl::split


## Parallel Algorithms
I did attempt to use the parallel algorithms included in C++17. However, the parallel search_all/find_all_* algorithms ended up being slower than the non-parallel counterparts. For that reason, they have currently been excluded.

## Setup
All the algorithms are contained in a single header file, `troldalgo.hpp`. Simply include the header file in your own project, and you are good to go.

## Status
All the algorithms in Troldalgo are functioning and can be used in other projects. However, additional algorithms may be added later.

## Contact
Feel free to contact me on [kenneth.balslev@gmail.com](mailto:kenneth.balslev@gmail.com)

