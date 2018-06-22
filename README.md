# 2048.cpp

Made with <span style="color:#e25555;">❤</span> in India


[![Build Status](https://travis-ci.com/Dark-Passenger/2048.cpp.svg?branch=master)](https://travis-ci.com/Dark-Passenger/2048.cpp)

[![Build status](https://ci.appveyor.com/api/projects/status/8208hcyfil9a2sut?svg=true)](https://ci.appveyor.com/project/Dark-Passenger/2048-cpp)

> Console version of the game "2048" written in C++.
>
> Ability to save scores, choose board size and view statistics!

![Demo of usage](assets/demo.gif)

## To-Do:
- [x] Add start menu [19/04/2018]
- [x] Save highscore / score [21/04/2018]
- [ ] Move to c++17
- [ ] Save a game state into a file and load and play from saved state.
- [ ] ~~AI~~ *(Abandoned indefinitely)*

### Requirements:
* a mordern version of gcc or msvc (2017 or above).
* Linux, macOS or Windows (cygwin or git bash) with a working terminal.

### Instructions:
1. Open your terminal in your preferred directory and clone this project:
```bash
$ git clone https://github.com/plibither8/2048.cpp
```
2. Enter the project directory:
```bash
$ cd 2048.cpp
```
3. Create a `build` folder (Optional):
```bash
$ mkdir build
```
4. generate the MakeFile:
```bash
$ cmake ..
```
4. Compile the `2048.cpp` file and create an output using the Makefile:
```bash
$ make
```
5. Run the program and play the game!
```bash
$ ./build/2048
```

## Notes:


* Game board array is defined as `board[y][x]`
* Game board will follow the following structure:

```
'x' => x-axis OR the horizotal line OR rows
'y' => y-axis OR the vertical line OR columns
```

### For example (zero-indexed):

`board[2][0]` refers to the 0th tile (or column) in 2nd row as in this case, x = 0 and y = 2. The specific tile is denoted the by '@' symbol in the following gameboard:

```
+------+------+------+------+
|      |      |      |      |
+------+------+------+------+
|      |      |      |      |
+------+------+------+------+
|   @  |      |      |      |
+------+------+------+------+
|      |      |      |      |
+------+------+------+------+
```

# License

Copyright (c) Mihir Chaturvedi. All rights reserved.

Licensed under the [MIT](LICENSE) License.
