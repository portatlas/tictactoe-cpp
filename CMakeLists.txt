cmake_minimum_required(VERSION 3.8)
project(tictactoe_cpp)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        src/main.cpp
        src/marker.cpp
        src/marker.hpp
        src/board/board.cpp
        src/board/board.hpp
        src/board/board_formatter.cpp
        src/board/board_formatter.hpp
        src/rules.cpp
        src/rules.hpp
        src/console.cpp
        src/console.hpp
        src/game/game.hpp
        src/game/game.cpp
        src/player/player.hpp
        src/player/human_player.cpp
        src/player/human_player.hpp
        src/player/computer_player.cpp
        src/player/computer_player.hpp
        src/game/game_setup.cpp
        src/game/game_setup.hpp)
add_executable(tictactoe_cpp ${SOURCE_FILES})
add_library(source_lib ${SOURCE_FILES})

set (TEST_SOURCE_FILES
        test/board/board_formatter_test.cpp
        test/board/board_test.cpp
        test/console_test.cpp
        test/rules_test.cpp
        test/game/game_test.cpp
        test/game/game_setup_test.cpp
        test/player/human_player_test.cpp
        test/player/computer_player_test.cpp)
add_executable(test_lib ${TEST_SOURCE_FILES})
target_link_libraries(test_lib source_lib)
