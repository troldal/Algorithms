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
    * [trl::split](#trlsplit)
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
The trl::find_all algorithm finds all elements with a certain value in a container. It takes a begin/end iterator pair for the container, an output iterator to the destination container and the value to find. The destination must hold iterators to the elements in the container.

Example code:

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
The trl::find_all_if algorithm finds all elements matching a predicate in a container. It takes a begin/end iterator pair for the container, an output iterator to the destination container and the value to find. The destination must hold iterators to the elements in the container.

The predicate function takes an argument (possibly as const reference) of the container value type. The predicate function returns true for those elements that should be added to the destination.

Example code:
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
    trl::find_all_if(str.begin(), str.end(), std::back_inserter(results), [](decltype(*str.begin()) c) {
        return c == 'Z';
    });

    std::cout << "Size of string: " << str.size() << std::endl;
    std::cout << "Number of Z's found: " << results.size() << std::endl;
    std::cout << "Character at index 0: " << *results[0] << std::endl;
}
```

### trl::find_all_if_not
The trl::find_all_if_not algorithm finds all elements matching a predicate in a container. It takes a begin/end iterator pair for the container, an output iterator to the destination container and the value to find. The destination must hold iterators to the elements in the container.

The predicate function takes an argument (possibly as const reference) of the container value type. The predicate function returns true for those elements that should NOT be added to the destination.

Example code:
```cpp
#include <iostream>
#include <vector>
#include <string>
#include <troldalgo.hpp>

int main() {
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
```

### trl::find_all_of
The trl::find_all_of algorithm finds all elements matching any of a set of given elements. It takes a begin/end iterator pair for the container, , b begin/end iterator pair to the collection of elements to find, and an output iterator to the destination container. The destination must hold iterators to the elements in the container.

Example code:
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
```

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

