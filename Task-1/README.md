# Basic - Calculator Program

> A simple, clean and beginner-friendly console-based calculator written in C that performs basic arithmetic operations using switch-case.

## Project Description

The **Basic - Calculator Program** is a menu-driven console application that allows users to perform four fundamental arithmetic operations - Addition, Subtraction, Multiplication, and Division.

The user selects an operation from a menu, enters two numbers, and the program calculates and displays the result. The program uses a `switch-case` statement for operation selection, separate functions for each operation, and handles errors like invalid input and division by zero.

This project is ideal for beginners learning C programming concepts like functions, control flow, and user input handling.

## Features

- 4 Basic Operations: Addition (+), Subtraction (-), Multiplication (*), Division (/)
- Switch-Case Based operation selection
- Menu-Driven Interface, repeats until user chooses Exit
- Modular Code: Each operation is a separate function
- Error Handling: Invalid choice, invalid number, division by zero protection
- Decimal Support: Works with integers and floating-point numbers (double)
- Well Commented: Every function and logic block is explained

## Project Structure

```
Basic-Calculator-Program/
├── calculator.c    # Main source code - Complete calculator logic
└── README.md       # Project documentation (this file)
```

## Requirements

- Any C Compiler: GCC (Linux / macOS / Windows via MinGW), Clang, Code::Blocks, Dev-C++ / Turbo C
- Terminal / Command Prompt

## How to Use

1. Run the program, the menu will appear.
2. Enter your choice 1 to 5.
3. If you chose 1-4, enter two numbers when asked.
4. The result will be displayed.
5. The menu will appear again. Choose 5 to exit.

## Sample Output

```
Welcome to Basic Calculator Program!

========================================
      BASIC - CALCULATOR PROGRAM
========================================
  1. Addition       (+)
  2. Subtraction    (-)
  3. Multiplication (*)
  4. Division       (/)
  5. Exit
========================================
Enter your choice (1-5): 1
Enter first number  : 15
Enter second number : 5

----------------------------------------
Result: 15.00 + 5.00 = 20.00
----------------------------------------
```

## How to Run

### On Linux / macOS

```bash
gcc calculator.c -o calculator
./calculator
```

### On Windows (MinGW / GCC)

```bash
gcc calculator.c -o calculator.exe
calculator.exe
```

### On Windows (Code::Blocks / Dev-C++ / Turbo C)

1. Open `calculator.c` in your IDE
2. Click Compile & Run (F9 in Code::Blocks)

## License

This project is free to use for learning and educational purposes.
