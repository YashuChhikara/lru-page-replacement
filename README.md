This repository contains an implementation of the Least Recently Used (LRU) page replacement algorithm using the C programming language. Internally, the program uses a matrix (2D array) to keep track of page values and the positions of their most recent use within the reference string. This allows the algorithm to determine the least recently used page efficiently without maintaining complex timestamps or additional data structures.


## Description

LRU is a page replacement strategy that evicts the page that was used the longest time ago. This implementation:
- Uses a fixed-size reference string.
- Simulates a fixed number of memory frames.
- Tracks page hits and misses.
- Displays the state of the memory frames after each operation.
- Identifies the least recently used page using backward search in the reference string.

## Features

- Fully functional LRU simulation
- Frame state printing after every step
- Clear logic with minimal swaps to find the least recently used page
- Easy to modify reference string and frame size

