
# Ping Pong Game with SDL2

## Description
This project is a simple Ping Pong game using SDL2 for rendering graphics. The game features a ball bouncing around the screen and two movable walls controlled by the player. The game is implemented in C and utilizes shared memory and threading for interaction.

## Prerequisites

Make sure to have the following dependencies installed:

- SDL2
- POSIX shared memory (`shm_open`, `mmap`, etc.)
- C compiler (e.g., GCC)
- Make and CMake

## Installation

### Step 1: Create a `build` directory

Navigate to the project folder and create a `build` directory:

```bash
mkdir build
cd build
```

### Step 2: Run CMake

Generate the build files using CMake:

```bash
cmake ..
```

### Step 3: Build the project

Compile the project using `make`:

```bash
make
```

### Step 4: Run the game

Execute the game:

```bash
./ping_pong
```

## Game Controls

- Use the arrow keys to control player 1 (move up and down).
- Use the keys `z` and `s` to control player 2 (move up and down).
- The game runs in a loop and can be exited by closing the window.

## Notes

The program uses threading for controlling player movement, and SDL2 for handling the graphical rendering. The game is designed to be simple and runs in a terminal-based environment. You can quit by closing the window or sending a `CTRL+C` to stop the program. They may have some issues about the usage of keyboard events, you can't use keys at the same time.