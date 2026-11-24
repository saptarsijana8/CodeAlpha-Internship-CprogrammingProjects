# CodeAlpha - C Programming Internship Projects

> A complete collection of 3 C programming projects completed during the CodeAlpha internship - from Basic to High level. Each project is menu-driven, well-commented, and built using core C concepts like functions, arrays, structs, and file handling.

## Table of Contents

- [Internship Overview](#internship-overview)
- [Tools Used](#tools-used)
- [C Libraries Used](#c-libraries-used)
- [Project 1 - Basic - Calculator Program](#project-1---basic---calculator-program)
- [Project 2 - Medium - Matrix Operations](#project-2---medium---matrix-operations)
- [Project 3 - High - Student Management System](#project-3---high---student-management-system)
- [Overall Project Structure](#overall-project-structure)
- [How to Run](#how-to-run)
- [Concepts Covered](#concepts-covered)
- [Acknowledgement](#acknowledgement)

## Internship Overview

| Field | Details |
| :--- | :--- |
| **Organization** | CodeAlpha |
| **Domain** | C Programming |
| **Intern** | Saptarsi Jana |
| **Year** | Second-Year Student |
| **Total Projects** | 3 (Basic, Medium, High) |
| **Language** | C (C99 / C11) |

This repository contains all 3 tasks assigned during the internship. The difficulty increases step by step - starting from basic arithmetic with switch-case, moving to 2D arrays and functions for matrices, and finally to a complete file-based management system using structs.

## Tools Used

| Tool | Purpose |
| :--- | :--- |
| **VS Code / Visual Studio** | Main code editor / IDE for writing, editing, and debugging C code. VS Code with C/C++ extension was used for writing clean and organized code. |
| **MinGW / GCC Compiler** | Compiler used to compile C programs on Windows. GCC converts `.c` source files into executable `.exe` files. Command used: `gcc file.c -o file` |
| **Git** | Version control system used to track changes, manage project files, and maintain code history locally. |
| **【entity-GitHub¦canonical_name=GitHub】** | Cloud platform used to store, share, and showcase all 3 projects. Each project is uploaded with its own source code and README file. |
| **Terminal / Command Prompt** | Used to compile and run the programs, and to use Git commands like `git add`, `git commit`, `git push`. |
| **Code::Blocks / Dev-C++ / Turbo C** | Alternative IDEs that can also be used to compile and run these C programs on Windows. |

### Basic Git Commands Used

```bash
git init
git add .
git commit -m "Add C projects"
git push origin main
```

## C Libraries Used

| Library | Used In | Basic Functionality |
| :--- | :--- | :--- |
| `stdio.h` | All 3 Projects | Standard Input / Output. Used for `printf()` to display output and `scanf()` to take input from user. Used in every project for menu, input, and result display. |
| `stdlib.h` | Calculator, Student Management | Standard Library. Used for `exit()`, memory functions, and general utilities. Used for program termination and system functions. |
| `string.h` | Student Management System | String Handling. Used for string operations like `strcpy()`, `strcmp()`, `strlen()` if needed, and for handling names and course strings safely. |

### Libraries Summary by Project

- **Calculator:** `stdio.h`, `stdlib.h`
- **Matrix Operations:** `stdio.h`
- **Student Management System:** `stdio.h`, `stdlib.h`, `string.h`

## Project 1 - Basic - Calculator Program

### Overview

**Project Name:** Basic - Calculator Program
**File:** `calculator.c`
**Level:** Basic

A simple, menu-driven console calculator that performs basic arithmetic operations using `switch-case`.

### Brief Description

The user selects an operation from a menu, enters two numbers, and the program calculates and displays the result. The program repeats until the user chooses Exit.

### Features and Functionalities

- **Addition (+):** Adds two numbers - `add()` function
- **Subtraction (-):** Subtracts second number from first - `subtract()` function
- **Multiplication (*):** Multiplies two numbers - `multiply()` function
- **Division (/):** Divides first number by second - `divide()` function, with division by zero protection
- **Menu-Driven Interface:** Repeats until Exit
- **Input Validation:** Invalid choice and invalid number handling
- **Decimal Support:** Uses `double` for accurate results

### Core Concepts

`switch-case`, Functions, `while` Loop, `if-else`, `scanf` / `printf`

## Project 2 - Medium - Matrix Operations

### Overview

**Project Name:** Medium - Matrix Operations
**File:** `matrix_operations.c`
**Level:** Medium

A menu-driven program to perform Matrix Addition, Matrix Multiplication, and Transpose using **functions and 2D arrays** for better modularity.

### Brief Description

The user selects a matrix operation, enters the order and elements of matrices, and the program displays the result in a neat tabular format. Each operation is a separate function.

### Features and Functionalities

- **Matrix Addition:** Adds two matrices of same order - `addMatrices()` - Formula: `result[i][j] = A[i][j] + B[i][j]`
- **Matrix Multiplication:** Multiplies two matrices - `multiplyMatrices()` - Rule: Columns of A must equal Rows of B - Formula: `result[i][j] = sum(A[i][k] * B[k][j])`
- **Transpose:** Finds transpose of a matrix - `transposeMatrix()` - Formula: `trans[j][i] = mat[i][j]`, rows and columns get swapped
- **Input Function:** `inputMatrix()` - Takes matrix elements from user
- **Display Function:** `displayMatrix()` - Prints matrix in formatted table
- **Validation:** Invalid size, invalid choice, and multiplication rule check
- **Supports up to 10 x 10 matrices** (change `MAX` to increase)

### Core Concepts

2D Arrays, Functions, Nested Loops, `switch-case`, Input Validation

## Project 3 - High - Student Management System

### Overview

**Project Name:** High - Student Management System
**File:** `student_management.c`
**Level:** High

A simple, easy and fully working menu-driven program to manage student records using **struct + file handling** so data is stored permanently.

### Brief Description

You can Add, Display, Search, Update, and Delete student records. Each student has Roll Number, Name, Course, and Marks. All data is saved in `students.dat` file, so records stay saved even after closing and reopening the program.

### Features and Functionalities

- **Add Student:** `addStudent()` - Saves a new student record to file using `fwrite()` in `"ab"` mode
- **Display All Students:** `displayStudents()` - Shows all records in a clean table using `fread()` in `"rb"` mode
- **Search Student:** `searchStudent()` - Finds a student by Roll Number
- **Update Student:** `updateStudent()` - Updates Name, Course, Marks by Roll Number using temp file + `remove()` + `rename()`
- **Delete Student:** `deleteStudent()` - Deletes a student by Roll Number using temp file logic
- **Permanent Storage:** Data saved in `students.dat`, not lost after exit
- **Easy Code:** One struct, one function per feature, fully commented

### Student Record Structure

```c
struct Student
{
    int roll;        // Roll Number - unique ID
    char name[50];   // Student Name
    char course[30]; // Course Name
    float marks;     // Marks / Percentage
};
```

### Core Concepts

`struct`, File Handling (`fopen`, `fclose`, `fread`, `fwrite`, `remove`, `rename`), File Modes (`"ab"`, `"rb"`, `"wb"`), Functions, `switch-case`

## Overall Project Structure

```
CodeAlpha-C-Programming/
├── Task-1-Calculator/
│   ├── calculator.c
│   └── README.md
├── Task-2-Matrix-Operations/
│   ├── matrix_operations.c
│   └── README.md
├── Task-3-Student-Management-System/
│   ├── student_management.c
│   ├── students.dat (created automatically)
│   └── README.md
└── README.md (this file - Overall README)
```

## How to Run

### General Steps for All Projects

1. Open the project folder in VS Code.
2. Open Terminal in VS Code or Command Prompt.
3. Compile the `.c` file with GCC.
4. Run the generated executable.

### On Linux / macOS

```bash
# Task 1 - Calculator
gcc calculator.c -o calculator
./calculator

# Task 2 - Matrix Operations
gcc matrix_operations.c -o matrix_operations
./matrix_operations

# Task 3 - Student Management System
gcc student_management.c -o student_management
./student_management
```

### On Windows (MinGW / GCC)

```bash
gcc calculator.c -o calculator.exe
calculator.exe

gcc matrix_operations.c -o matrix_operations.exe
matrix_operations.exe

gcc student_management.c -o student_management.exe
student_management.exe
```

### On Windows (Code::Blocks / Dev-C++ / Turbo C)

1. Open the `.c` file in your IDE
2. Click Compile & Run (F9 in Code::Blocks)

## Concepts Covered

| Concept | Project 1 - Calculator | Project 2 - Matrix | Project 3 - Student System |
| :--- | :---: | :---: | :---: |
| Functions | Yes | Yes | Yes |
| switch-case | Yes | Yes | Yes |
| Loops | Yes | Yes | Yes |
| 1D / 2D Arrays | No | Yes (2D) | No |
| struct | No | No | Yes |
| File Handling | No | No | Yes |
| Input Validation | Yes | Yes | Yes |

## Acknowledgement

Thank you to CodeAlpha for providing this internship opportunity and assigning these practical projects. Completing these tasks was a valuable step in my Python programming journey.

Intern: Saptarsi Jana\
Year: Second-Year Student\
Domain: C Programming\
Organization: CodeAlpha