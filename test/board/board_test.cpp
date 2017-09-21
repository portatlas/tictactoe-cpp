#define CATCH_CONFIG_MAIN
#include "../../lib/catch.hpp"
#include "../../src/marker.hpp"
#include "../../src/board/board.hpp"

SCENARIO ("Board: Empty Board ", "[empty-board]") {
    std::vector<std::string> empty_grid = {" ", " ", " ",
                                           " ", " ", " ",
                                           " ", " ", " "};

    GIVEN("Empty Board initialized with a size of 9") {
        Board board(9);
        WHEN("#getSize is called") {
            THEN("return the size of the board") {
                REQUIRE(board.getSize() == 9);
            }
        }

        WHEN("#getSlot is called for the first slot") {
            THEN("return an empty slot") {
                REQUIRE(board.getSlot(1) == " ");
            }
        }

        WHEN("#isSlotEmpty is called for the first slot") {
            THEN("return true") {
                REQUIRE(board.isSlotEmpty(1) == true);
            }
        }

        WHEN("#countMarker is called for X") {
            THEN("return 0") {
                REQUIRE(board.countMarker(X) == 0);
            }
        }

        WHEN("#countMarker is called for O") {
            THEN("return 0") {
                REQUIRE(board.countMarker(O) == 0);
            }
        }

        WHEN("#isGridFull is called") {
            THEN("return false") {
                REQUIRE(board.isGridFull() == false);
            }
        }

        WHEN("#validSlots is called") {
            THEN("return the values from 1 to 9") {
                std::vector<int> valid_slots = {1, 2, 3, 4, 5, 6, 7, 8, 9};
                REQUIRE(board.validSlots() == valid_slots);
            }
        }
    }
}

SCENARIO("Board: Marked Board", "[marked-board]") {
    GIVEN("Marked Board with X on the first slot") {
        Board board(9);
        board.fillSlot(1, X);

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
            THEN("return a vector with values from 2 to 9") {
                std::vector<int> empty_slots = {2, 3, 4, 5, 6, 7, 8, 9};
                REQUIRE(board.validSlots() == empty_slots);
            }
        }

        WHEN("#fillSlot is called with 2") {
            board.fillSlot(2, O);
            AND_WHEN("#getSlot is called on 2") {
                THEN("return O") {
                    REQUIRE(board.getSlot(2) == O);
                }
                AND_WHEN("#fillSlot is called with 7") {
                    board.fillSlot(7, X);
                    THEN("#getSlot on 7 returns X") {
                        REQUIRE(board.getSlot(7) == X);
                    }
                }
            }
        }
    }

    GIVEN("A board initialized with another grid") {
        std::vector<std::string> marked_grid = { X ,  X ,  X ,
                                                " ", " ", " ",
                                                 O ,  O , " "};
        Board active_board(marked_grid);

        WHEN("#countMarker is called") {
            THEN("return 3 for X") {
                REQUIRE(active_board.countMarker(X) == 3);
            }
        }

        WHEN("#countMarker is called") {
            THEN("return 2 for O") {
                REQUIRE(active_board.countMarker(O) == 2);
            }
        }

        WHEN("#validSlots is called") {
            THEN("return the values from 4,5,6,9") {
                std::vector<int> valid_slots = {4, 5, 6, 9};
                REQUIRE(active_board.validSlots() == valid_slots);
            }
        }
    }
}

SCENARIO("Board: Full board", "[full-board]") {
    GIVEN("A full 3x3 board") {
        std::vector<std::string> current_board = {X, O, X,
                                                  O, X, O,
                                                  X, O, X};
        Board full_board(current_board);

        WHEN("#countMarker is called") {
            THEN("return 5 for X") {
                REQUIRE(full_board.countMarker(X) == 5);
            }
        }

        WHEN("#countMarker is called") {
            THEN("return 4 for O") {
                REQUIRE(full_board.countMarker(O) == 4);
            }
        }

        WHEN("#isGridFull is called") {
            THEN("return true") {
                REQUIRE(full_board.isGridFull() == true);
            }
        }

        WHEN("#validSlots is called") {
            THEN("#return an empty vector") {
                std::vector<int> empty_slots = {};
                REQUIRE(full_board.validSlots() == empty_slots);
            }
        }
    }
}
