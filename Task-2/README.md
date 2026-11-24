# Medium - Matrix Operations

> A clean, menu-driven console program in **C** to perform Matrix Addition, Matrix Multiplication and Transpose using **functions and 2D arrays** for better modularity.

## Project Description

The **Medium - Matrix Operations** program is a menu-driven console application that implements three fundamental matrix operations:

- **Matrix Addition**
- **Matrix Multiplication**
- **Transpose**

The user selects an operation from a menu, enters the order and elements of the matrices, and the program displays the result in a neat tabular format. The code is fully modular - each operation is a separate function, and 2D arrays are used to store matrices. It also includes validation for matrix order, multiplication rules, and invalid input.

This project is ideal for learning 2D arrays, functions, nested loops, and switch-case in C.

## Features

- Matrix Addition (same order matrices)
- Matrix Multiplication (with Columns of A = Rows of B check)
- Transpose of Matrix (rows and columns swapped)
- Functions and 2D Arrays for better modularity
- Menu-Driven Interface, repeats until user chooses Exit
- Input Validation: Invalid size, invalid choice, multiplication rule check
- Neat Matrix Display: Formatted tabular output
- Well Commented: Every function and logic block is explained
- Supports matrices up to 10 x 10 (change MAX in code to increase)

## Project Structure

```
Medium-Matrix-Operations/
├── matrix_operations.c   # Main source code - Complete matrix logic
└── README.md             # Project documentation (this file)
```

## Requirements

- Any C Compiler: GCC (Linux / macOS / Windows via MinGW), Clang, Code::Blocks, Dev-C++ / Turbo C
- Terminal / Command Prompt

## How to Use

1. Run the program, the menu will appear.
2. Enter your choice 1 to 4.
3. Enter rows and columns when asked.
4. Enter matrix elements row by row.
5. The result will be displayed.
6. The menu will appear again. Choose 4 to exit.

## Sample Output

```
Welcome to Medium - Matrix Operations Program!

========================================
     MEDIUM - MATRIX OPERATIONS
========================================
  1. Matrix Addition
  2. Matrix Multiplication
  3. Transpose of Matrix
  4. Exit
========================================
Enter your choice (1-4): 1

--- Matrix Addition ---
Enter rows for Matrix A and B : 2
Enter columns for Matrix A and B : 2

Enter elements of Matrix A (2 x 2):
  A[0][0] : 1
  A[0][1] : 2
  A[1][0] : 3
  A[1][1] : 4

Enter elements of Matrix B (2 x 2):
  B[0][0] : 5
  B[0][1] : 6
  B[1][0] : 7
  B[1][1] : 8

Matrix A (2 x 2):
      1     2
      3     4

Matrix B (2 x 2):
      5     6
      7     8

Result (A + B) (2 x 2):
      6     8
     10    12
```

## Concepts Covered

- 2D Arrays for storing matrices
- Functions: inputMatrix(), displayMatrix(), addMatrices(), multiplyMatrices(), transposeMatrix()
- Nested Loops for matrix traversal
- switch-case for operation selection
- Input Validation and Error Handling

## How to Run

### On Linux / macOS

```bash
gcc matrix_operations.c -o matrix_operations
./matrix_operations
```

### On Windows (MinGW / GCC)

```bash
gcc matrix_operations.c -o matrix_operations.exe
matrix_operations.exe
```

### On Windows (Code::Blocks / Dev-C++ / Turbo C)

1. Open `matrix_operations.c` in your IDE
2. Click Compile & Run (F9 in Code::Blocks)

## License

This project is free to use for learning and educational purposes.
