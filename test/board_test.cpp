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
                REQUIRE(9 == board.getSize());
            }
        }
        WHEN("#getGrid is called") {
            THEN("return an empty grid") {
                REQUIRE(empty_grid == board.getGrid());
            }
        }

        WHEN("#getSlot is called for the first slot") {
            THEN("return an empty slot") {
                REQUIRE(" " == board.getSlot(1));
            }
        }

        WHEN("#isSlotEmpty is called for the first slot") {
            THEN("return true") {
                REQUIRE(true == board.isSlotEmpty(1));
            }
        }

        WHEN("#countMarker is called") {
            THEN("return 0") {
                REQUIRE(0 == board.countMarker(X));
                REQUIRE(0 == board.countMarker(O));
            }
        }

        WHEN("#isGridFull is called") {
            THEN("returns false") {
                REQUIRE(false == board.isGridFull());
            }
        }

        WHEN("#validSlots is called") {
            THEN("returns the values from 1 to 9") {
                vector<int> valid_slots = {1, 2, 3, 4, 5, 6, 7, 8, 9};
                REQUIRE(valid_slots == board.validSlots());
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
                REQUIRE(expected_board.getGrid() == board.getGrid());
            }
        }

        WHEN("#getSlot is called with the first slot") {
            THEN("return X since it was placed on the first slot") {
                REQUIRE(X == board.getSlot(1));
            }
        }

        WHEN("#isSlotEmpty is called for the first slot") {
            THEN("return false") {
                REQUIRE(false == board.isSlotEmpty(1));
            }
        }

        WHEN("#countMarker is called") {
            THEN("return 1") {
                REQUIRE(1 == board.countMarker(X));
            }
        }

        WHEN("#validSlots is called") {
            THEN("return a vector with values from 1 to 8") {
                vector<int> empty_slots = {2, 3, 4, 5, 6, 7, 8, 9};
                REQUIRE(empty_slots == board.validSlots());
            }
        }

        WHEN("#fillSlot is called with 2") {
            board.fillSlot(2, O);
            AND_WHEN("#getGrid is called") {
                THEN("return a new grid with X and O on 1 and 2 respectively") {
                    vector<string> marked_grid = {X, O, " ", " ", " ", " ", " ", " ", " "};
                    Board expected_board(marked_grid);
                    REQUIRE(expected_board.getGrid() == board.getGrid());
                }
                AND_WHEN("#fillSlot is called with 7") {
                    THEN("#getGrid return a new grid with X,O,X on 1,2,7 respectively") {
                        vector<string> marked_grid = {X, O, " ", " ", " ", " ", X, " ", " "};
                        Board expected_board(marked_grid);
                        REQUIRE(expected_board.getGrid() == board.fillSlot(7, X).getGrid());
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
                REQUIRE(marked_grid == active_board.getGrid());
            }
        }

        THEN("#countMarker return 3 for X and 2 for O") {
            REQUIRE(3 == active_board.countMarker(X));
            REQUIRE(2 == active_board.countMarker(O));
        }

        THEN("#validSlots returns the values from 4,5,6,9") {
            vector<int> valid_slots = {4, 5, 6, 9};
            REQUIRE(valid_slots == active_board.validSlots());
        }
    }

    GIVEN("A full 3x3 board") {
        vector<string> current_board = {X, O, X, O, X, O, X, O, X};
        Board full_board(current_board);

        WHEN("#getGrid is called") {
            THEN("return the board that it was set too") {
                REQUIRE(current_board == full_board.getGrid());
            }
        }

        WHEN("#countMarker is called") {
            THEN("return 5 for X and 4 for O") {
                REQUIRE(5 == full_board.countMarker(X));
                REQUIRE(4 == full_board.countMarker(O));
            }
        }

        WHEN("#isGridFull is called") {
            THEN("returns true") {
                REQUIRE(true == full_board.isGridFull());
            }
        }

        WHEN("#validSlots is called") {
            THEN("#returns an empty vector") {
                vector<int> empty_slots = {};
                REQUIRE(empty_slots == full_board.validSlots());
            }
        }
    }
}
