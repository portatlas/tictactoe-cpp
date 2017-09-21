# TICTACTOE written in C++

## Dependencies
* You will need [cmake](https://cmake.org/) to compile the project
* You can install cmake with brew ```$ brew install cmake```
* Note: other c++ compilers may work as well

## Build and Compile
* Run the following command in the project root directory where the CMakeLists.txt exists

	```$ cmake -H. -Bbuild```

	```$ cmake --build build -- -j3```


## Unit Test
* Run the following command to run the unit tests

	```$ ./build/test_lib```

* Appending the -s option will provide you with additional details

	```$ ./build/test_lib -s```

* Test are written with [Catch](https://github.com/philsquared/Catch)

## To play the game
* Execute the tictactoe_cpp file

	```$ ./build/tictactoe_cpp```

## Main Features
* Select opponent type (human vs human, human vs computer, computer vs human, computer vs computer)
* Computer will never loose (although the computer is slow when going first and making the first move)
