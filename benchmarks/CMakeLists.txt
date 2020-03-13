#=======================================================================================================================
# Define Example1 target
#=======================================================================================================================
add_subdirectory(googlebench)

add_executable(bench_find_all bench_find_all.cpp)
target_link_libraries(bench_find_all PRIVATE Troldalgo benchmark)
