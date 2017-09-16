#define CATCH_CONFIG_MAIN
#include "../lib/catch.hpp"
#include "../src/marker.hpp"
#include "../src/board.hpp"

SCENARIO ("Board") {
    vector<string> empty_grid = {" ", " ", " ", " ", " ", " ", " ", " ", " "};
    
    GIVEN("Empty Board initialized by a given size") {
        Board board(9);

        WHEN("#getSize is called") {
            THEN("return the size of the board") {
                REQUIRE(board.getSize() == 9);
            }
        }
        WHEN("#getGrid is called") {
            THEN("return an empty grid") {
                REQUIRE(board.getGrid() == empty_grid);
            }
        }

        WHEN("#getSlot is called for the first slot") {
            THEN("return an empty slot") {
                REQUIRE(" " == board.getSlot(1));
            }
        }

        WHEN("#isSlotEmpty is called for the first slot") {
            THEN("return true") {
                REQUIRE(board.isSlotEmpty(1) == true);
            }
        }

        WHEN("#countMarker is called") {
            THEN("return 0") {
                REQUIRE(board.countMarker(X) == 0);
                REQUIRE(board.countMarker(O) == 0);
            }
        }

        WHEN("#isGridFull is called") {
            THEN("returns false") {
                REQUIRE(board.isGridFull() == false);
            }
        }

        WHEN("#validSlots is called") {
            THEN("returns the values from 1 to 9") {
                vector<int> valid_slots = {1, 2, 3, 4, 5, 6, 7, 8, 9};
                REQUIRE(board.validSlots() == valid_slots);
            }
        }
    }

    GIVEN("Marked Board with X on the first slot") {
        Board board(9);
        board.fillSlot(1, X);
        WHEN("#getGrid is called") {
            THEN("return a new board with X on the first slot") {
                vector<string> marked_grid = {X, " ", " ", " ", " ", " ", " ", " ", " "};
                Board expected_board(marked_grid);
                REQUIRE(board.getGrid() == expected_board.getGrid());
            }
        }

        WHEN("#getSlot is called with the first slot") {
            THEN("return X since it was placed on the first slot") {
                REQUIRE(board.getSlot(1) == X);
            }
        }

        WHEN("#isSlotEmpty is called for the first slot") {
            THEN("return false") {
                REQUIRE(board.isSlotEmpty(1) == false);
            }
        }

        WHEN("#countMarker is called") {
            THEN("return 1") {
                REQUIRE(board.countMarker(X) == 1);
            }
        }

        WHEN("#validSlots is called") {
            THEN("return a vector with values from 1 to 8") {
                vector<int> empty_slots = {2, 3, 4, 5, 6, 7, 8, 9};
                REQUIRE(board.validSlots() == empty_slots);
            }
        }

        WHEN("#fillSlot is called with 2") {
            board.fillSlot(2, O);
            AND_WHEN("#getGrid is called") {
                THEN("return a new grid with X and O on 1 and 2 respectively") {
                    vector<string> marked_grid = {X, O, " ", " ", " ", " ", " ", " ", " "};
                    Board expected_board(marked_grid);
                    REQUIRE(board.getGrid() == expected_board.getGrid());
                }
                AND_WHEN("#fillSlot is called with 7") {
                    THEN("#getGrid return a new grid with X,O,X on 1,2,7 respectively") {
                        vector<string> marked_grid = {X, O, " ", " ", " ", " ", X, " ", " "};
                        Board expected_board(marked_grid);
                        REQUIRE(board.fillSlot(7, X).getGrid() == expected_board.getGrid());
                    }
                }
            }
        }
    }

    GIVEN("A board initialized with another grid") {
        vector<string> marked_grid = {X, X, X, " ", " ", " ", O, O, " "};
        Board active_board(marked_grid);

        WHEN("#getGrid is called") {
            THEN("return the grid it was initialized with") {
                REQUIRE(active_board.getGrid() == marked_grid);
            }
        }

        THEN("#countMarker return 3 for X and 2 for O") {
            REQUIRE(active_board.countMarker(X) == 3);
            REQUIRE(active_board.countMarker(O) == 2);
        }

        THEN("#validSlots returns the values from 4,5,6,9") {
            vector<int> valid_slots = {4, 5, 6, 9};
            REQUIRE(active_board.validSlots() == valid_slots);
        }
    }

    GIVEN("A full 3x3 board") {
        vector<string> current_board = {X, O, X, O, X, O, X, O, X};
        Board full_board(current_board);

        WHEN("#getGrid is called") {
            THEN("return the board that it was set too") {
                REQUIRE(full_board.getGrid() == current_board);
            }
        }

        WHEN("#countMarker is called") {
            THEN("return 5 for X and 4 for O") {
                REQUIRE(full_board.countMarker(X) == 5);
                REQUIRE(full_board.countMarker(O) == 4);
            }
        }

        WHEN("#isGridFull is called") {
            THEN("returns true") {
                REQUIRE(full_board.isGridFull() == true);
            }
        }

        WHEN("#validSlots is called") {
            THEN("#returns an empty vector") {
                vector<int> empty_slots = {};
                REQUIRE(full_board.validSlots() == empty_slots);
            }
        }
    }
}
