# High - Student Management System

> A simple, easy and fully working menu-driven program in **C** to manage student records using **struct + file handling** so data is stored permanently.

## Project Description

The **High - Student Management System** is a menu-driven console application that lets you manage student records easily.

You can **Add, Display, Search, Update, and Delete** student records. Each student has a Roll Number, Name, Course, and Marks.

All data is stored in a file (`students.dat`) using **struct + file handling**, so even after you close and reopen the program, your records are still there. This makes it a complete mini-project for learning structs and file handling in C.

This code is kept **easy and simple** - one struct, one function per menu option, and clear comments - so it is easy to understand, explain in viva, and run without errors.

## Features

- Add Student - Save a new student record
- Display All Students - Show all records in a clean table
- Search Student - Find a student by Roll Number
- Update Student - Change Name, Course, Marks by Roll Number
- Delete Student - Remove a student by Roll Number
- Permanent Storage - Data saved in `students.dat` file, not lost after exit
- Easy Code - One struct, one function per feature, fully commented
- Input Validation - Invalid choice and Not Found handling

## Project Structure

```
High-Student-Management-System/
├── student_management.c   # Main source code - Complete system
├── students.dat           # Data file - Created automatically when you add a student
└── README.md              # Project documentation (this file)
```

## Requirements

- Any C Compiler: GCC (Linux / macOS / Windows via MinGW), Clang, Code::Blocks, Dev-C++ / Turbo C
- Terminal / Command Prompt

## How to Use

1. Run the program, the menu will appear.
2. Press 1 to Add a student - Enter Roll, Name, Course, Marks.
3. Press 2 to Display all students.
4. Press 3 to Search a student by Roll Number.
5. Press 4 to Update a student by Roll Number.
6. Press 5 to Delete a student by Roll Number.
7. Press 6 to Exit. Your data stays saved.

## Sample Output

```
Welcome to Student Management System!
Your data is saved permanently in students.dat

========================================
   HIGH - STUDENT MANAGEMENT SYSTEM
========================================
  1. Add Student
  2. Display All Students
  3. Search Student
  4. Update Student
  5. Delete Student
  6. Exit
========================================
Enter your choice (1-6): 1

--- Add Student ---
Enter Roll Number : 101
Enter Name : Rahul Sharma
Enter Course : BCA
Enter Marks : 85.5

[Success] Student added successfully!

--- All Student Records ---

Roll       Name                 Course          Marks
------------------------------------------------------
101        Rahul Sharma         BCA             85.50
------------------------------------------------------
Total Students: 1
```

## Concepts Covered

- struct for storing one student record
- File Handling: fopen, fclose, fread, fwrite, remove, rename
- File Modes: "ab" (append), "rb" (read), "wb" (write)
- Functions: One function per feature for easy understanding
- switch-case for menu selection
- while loop for repeating menu

## How to Run

### On Linux / macOS

```bash
gcc student_management.c -o student_management
./student_management
```

### On Windows (MinGW / GCC)

```bash
gcc student_management.c -o student_management.exe
student_management.exe
```

### On Windows (Code::Blocks / Dev-C++ / Turbo C)

1. Open `student_management.c` in your IDE
2. Click Compile & Run (F9 in Code::Blocks)

## License

This project is free to use for learning and educational purposes.
