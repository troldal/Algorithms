#=======================================================================================================================
# Define CATCH library target
#=======================================================================================================================
add_library(Catch INTERFACE)
target_include_directories(Catch SYSTEM INTERFACE ${CMAKE_CURRENT_LIST_DIR}/catch2)

#=======================================================================================================================
# Define TEST target
#=======================================================================================================================
add_executable(TroldalgoTestSuite "")
target_sources(TroldalgoTestSuite PRIVATE TroldalgoTestSuite.cpp)
target_link_libraries(TroldalgoTestSuite PRIVATE Catch Algorithms)

#=======================================================================================================================
# Set warning flags
#=======================================================================================================================
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    target_compile_options(TroldalgoTestSuite PRIVATE -Weverything)
    target_compile_options(TroldalgoTestSuite PRIVATE -Wno-c++98-compat)
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    target_compile_options(TroldalgoTestSuite PRIVATE -Wmisleading-indentation)
    target_compile_options(TroldalgoTestSuite PRIVATE -Wduplicated-cond)
    target_compile_options(TroldalgoTestSuite PRIVATE -Wduplicated-branches)
    target_compile_options(TroldalgoTestSuite PRIVATE -Wlogical-op)
    target_compile_options(TroldalgoTestSuite PRIVATE -Wnull-dereference)
    target_compile_options(TroldalgoTestSuite PRIVATE -Wuseless-cast)
elseif (("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang") OR ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU"))
    target_compile_options(TroldalgoTestSuite PRIVATE -Wall)
    target_compile_options(TroldalgoTestSuite PRIVATE -Wextra)
    target_compile_options(TroldalgoTestSuite PRIVATE -Wshadow)
    target_compile_options(TroldalgoTestSuite PRIVATE -Wnon-virtual-dtor)
    target_compile_options(TroldalgoTestSuite PRIVATE -Wold-style-cast)
    target_compile_options(TroldalgoTestSuite PRIVATE -Wcast-align)
    target_compile_options(TroldalgoTestSuite PRIVATE -Wunused)
    target_compile_options(TroldalgoTestSuite PRIVATE -Woverloaded-virtual)
    target_compile_options(TroldalgoTestSuite PRIVATE -Wpedantic)
    target_compile_options(TroldalgoTestSuite PRIVATE -Wconversion)
    target_compile_options(TroldalgoTestSuite PRIVATE -Wsign-conversion)
    target_compile_options(TroldalgoTestSuite PRIVATE -Wdouble-promotion)
    target_compile_options(TroldalgoTestSuite PRIVATE -Wformat=2)
    target_compile_options(TroldalgoTestSuite PRIVATE -Weffc++)
elseif (("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC") OR ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Intel"))
    target_compile_options(TroldalgoTestSuite PRIVATE /permissive)
    target_compile_options(TroldalgoTestSuite PRIVATE /W4)
    target_compile_options(TroldalgoTestSuite PRIVATE /w14242)
    target_compile_options(TroldalgoTestSuite PRIVATE /w14254)
    target_compile_options(TroldalgoTestSuite PRIVATE /w14263)
    target_compile_options(TroldalgoTestSuite PRIVATE /w14265)
    target_compile_options(TroldalgoTestSuite PRIVATE /w14287)
    target_compile_options(TroldalgoTestSuite PRIVATE /we4289)
    target_compile_options(TroldalgoTestSuite PRIVATE /w14296)
    target_compile_options(TroldalgoTestSuite PRIVATE /w14311)
    target_compile_options(TroldalgoTestSuite PRIVATE /w14545)
    target_compile_options(TroldalgoTestSuite PRIVATE /w14546)
    target_compile_options(TroldalgoTestSuite PRIVATE /w14547)
    target_compile_options(TroldalgoTestSuite PRIVATE /w14549)
    target_compile_options(TroldalgoTestSuite PRIVATE /w14555)
    target_compile_options(TroldalgoTestSuite PRIVATE /w14619)
    target_compile_options(TroldalgoTestSuite PRIVATE /w14640)
    target_compile_options(TroldalgoTestSuite PRIVATE /w14826)
    target_compile_options(TroldalgoTestSuite PRIVATE /w14905)
    target_compile_options(TroldalgoTestSuite PRIVATE /w14906)
    target_compile_options(TroldalgoTestSuite PRIVATE /w14928)
endif ()

#=======================================================================================================================
# Enable code coverage
#=======================================================================================================================
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    target_compile_options(TroldalgoTestSuite PRIVATE -fprofile-instr-generate -fcoverage-mapping)
    target_link_options(TroldalgoTestSuite PRIVATE -fprofile-instr-generate)
    #Uncomment in case of linker errors
    #link_libraries(clang_rt.profile-x86_64)
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    target_compile_options(TroldalgoTestSuite PRIVATE --coverage)
    target_link_options(TroldalgoTestSuite PRIVATE --coverage)
    #Uncomment in case of linker errors
    #link_libraries(gcov)
endif ()

#=======================================================================================================================
# Enable code sanitizers
#=======================================================================================================================
if (("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang") OR ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU"))
    target_compile_options(TroldalgoTestSuite PRIVATE -g -fno-omit-frame-pointer -fsanitize=undefined)
    target_link_options(TroldalgoTestSuite PRIVATE -fno-omit-frame-pointer -fsanitize=undefined)
endif ()

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -fno-omit-frame-pointer -fsanitize=leak")
#set(CMAKE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS}  -fno-omit-frame-pointer -fsanitize=leak")