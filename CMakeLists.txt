cmake_minimum_required(VERSION 3.8)
project(tictactoe_cpp)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        src/board.cpp
        src/board.hpp
        src/board_formatter.cpp
        src/board_formatter.hpp
        src/console.cpp
        src/console.hpp
        src/marker.hpp)
add_executable(tictactoe_cpp ${SOURCE_FILES})
add_library(sample_lib ${SOURCE_FILES})

set (TEST_SOURCE_FILES
        test/board_formatter_test.cpp
        test/board_test.cpp
        test/console_test.cpp)
add_executable(test_lib ${TEST_SOURCE_FILES})
target_link_libraries(test_lib sample_lib)
