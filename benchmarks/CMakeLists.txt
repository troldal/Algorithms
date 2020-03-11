#=======================================================================================================================
# Define Example1 target
#=======================================================================================================================
add_subdirectory(googlebench)

add_executable(bench_find_all bench_find_all.cpp)
target_link_libraries(bench_find_all PRIVATE Algorithms benchmark)

find_package(TBB REQUIRED)
target_include_directories(bench_find_all PRIVATE ${TBB_INCLUDE_DIRS})
target_link_libraries(bench_find_all PRIVATE ${TBB_LIBRARIES})
