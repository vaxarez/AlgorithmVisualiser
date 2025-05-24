# Algorithm Visualiser

A terminal-based program in C that visualizes various sorting algorithms by sorting strings based on their length. It demonstrates the inner workings of classic algorithms like Bubble Sort, Quick Sort, Heap Sort, and more — step by step, with animated output in the terminal.

## Features

- Visualizes 6 sorting algorithms:
  - Bubble Sort  
  - Insertion Sort  
  - Selection Sort  
  - Heap Sort  
  - Quick Sort  
  - Shell Sort  
- Animates the sorting process with live updates  
- Easy to extend with additional algorithms  
- Pure C, no external GUI dependencies, runs in terminal

## Usage

1. Clone the repository:
```bash
git clone https://github.com/vaxarez/AlgorithmVisualiser.git
cd AlgorithmVisualiser
```

2. Build the program:
```bash
make
```

3. Run the visualiser:
```bash
./main
```

4. Choose the sorting algorithm number when prompted and watch the visualization.

## Requirements

- GCC compiler supporting C17 standard  
- Unix-like environment (Linux, macOS)  
- `make` utility

## How it works

- The program stores an array of strings of varying lengths.
- Based on your algorithm choice, it sorts the strings by their length.
- After each key operation (like swapping elements), the terminal is cleared and the current array state is printed to show progress visually.
- Uses `usleep` for smooth animation pauses.

## Extending

You can add your own sorting algorithms by implementing the function and adding it to the menu in `main.c`. Follow the existing pattern for visualization calls.

## License

MIT License