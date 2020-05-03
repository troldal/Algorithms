#=======================================================================================================================
# Define example_find_all target
#=======================================================================================================================
add_executable(example_find_all example_find_all.cpp)
target_link_libraries(example_find_all PRIVATE Troldalgo)

#=======================================================================================================================
# Define example_search_all target
#=======================================================================================================================
add_executable(example_search_all example_search_all.cpp)
target_link_libraries(example_search_all PRIVATE Troldalgo)

#=======================================================================================================================
# Define example_split target
#=======================================================================================================================
add_executable(example_split example_split.cpp)
target_link_libraries(example_split PRIVATE Troldalgo)

