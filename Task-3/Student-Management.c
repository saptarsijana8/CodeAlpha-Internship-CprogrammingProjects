/*
 * ============================================================================
 * Project Name : High - Student Management System
 * File         : student_management.c
 * Description  : A simple menu-driven C program to manage student records.
 *                Features: Add, Display, Search, Update, Delete.
 *                Uses struct + file handling to store data permanently.
 * Language     : C (C99 / C11 compatible)
 * Data File    : students.dat (created automatically)
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "students.dat"  // File where all records are stored permanently

/* [STRIPPED 75 bytes]
 * Structure: Student
 * Purpose : Holds one student record.
 * This single struct is used for all operations.
 * [STRIPPED 75 bytes] */
struct Student
{
    int roll;          // Roll Number - unique ID for search / update / delete
    char name[50];     // Student Name
    char course[30];   // Course Name (e.g. BCA, B.Tech)
    float marks;       // Marks / Percentage
};

/* [STRIPPED 75 bytes]
 * Function Prototypes - One function for each menu option.
 * Keeping them separate makes the code easy to read and understand.
 * [STRIPPED 75 bytes] */
void addStudent();
void displayStudents();
void searchStudent();
void updateStudent();
void deleteStudent();
void displayMenu();
void clearInputBuffer();

/* [STRIPPED 75 bytes]
 * Function: displayMenu
 * Purpose : Shows the main menu to the user.
 * [STRIPPED 75 bytes] */
void displayMenu()
{
    printf("\n========================================\n");
    printf("   HIGH - STUDENT MANAGEMENT SYSTEM    \n");
    printf("========================================\n");
    printf("  1. Add Student\n");
    printf("  2. Display All Students\n");
    printf("  3. Search Student\n");
    printf("  4. Update Student\n");
    printf("  5. Delete Student\n");
    printf("  6. Exit\n");
    printf("========================================\n");
    printf("Enter your choice (1-6): ");
}

/* [STRIPPED 75 bytes]
 * Function: clearInputBuffer
 * Purpose : Clears leftover input so next input works correctly.
 * [STRIPPED 75 bytes] */
void clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/* [STRIPPED 75 bytes]
 * Function: addStudent
 * Purpose : Adds a new student record to the file.
 * File Mode : "ab" = append binary, creates file if not exists.
 * [STRIPPED 75 bytes] */
void addStudent()
{
    struct Student s;
    FILE *fp;

    printf("\n--- Add Student ---\n");

    // Take input from user
    printf("Enter Roll Number : ");
    scanf("%d", &s.roll);
    clearInputBuffer(); // Clear newline before reading string

    printf("Enter Name : ");
    scanf("%[^\n]", s.name); // Reads full name with spaces
    clearInputBuffer();

    printf("Enter Course : ");
    scanf("%[^\n]", s.course);
    clearInputBuffer();

    printf("Enter Marks : ");
    scanf("%f", &s.marks);

    // Open file in append mode and save the record
    fp = fopen(FILE_NAME, "ab");
    if (fp == NULL)
    {
        printf("[Error] Could not open file!\n");
        return;
    }

    fwrite(&s, sizeof(s), 1, fp); // Write one struct to file
    fclose(fp);

    printf("\n[Success] Student added successfully!\n");
}

/* [STRIPPED 75 bytes]
 * Function: displayStudents
 * Purpose : Shows all student records stored in the file.
 * File Mode : "rb" = read binary
 * [STRIPPED 75 bytes] */
void displayStudents()
{
    struct Student s;
    FILE *fp;
    int count = 0;

    printf("\n--- All Student Records ---\n");

    fp = fopen(FILE_NAME, "rb");
    if (fp == NULL)
    {
        printf("No records found! Add a student first.\n");
        return;
    }

    // Print table header
    printf("\n%-10s %-20s %-15s %-10s\n", "Roll", "Name", "Course", "Marks");
    printf("------------------------------------------------------\n");

    // Read one record at a time until end of file
    while (fread(&s, sizeof(s), 1, fp) == 1)
    {
        printf("%-10d %-20s %-15s %-10.2f\n", s.roll, s.name, s.course, s.marks);
        count++;
    }

    if (count == 0)
    {
        printf("No records found!\n");
    }
    else
    {
        printf("------------------------------------------------------\n");
        printf("Total Students: %d\n", count);
    }

    fclose(fp);
}

/* [STRIPPED 75 bytes]
 * Function: searchStudent
 * Purpose : Finds a student by Roll Number and shows details.
 * [STRIPPED 75 bytes] */
void searchStudent()
{
    struct Student s;
    FILE *fp;
    int searchRoll, found = 0;

    printf("\n--- Search Student ---\n");
    printf("Enter Roll Number to search : ");
    scanf("%d", &searchRoll);

    fp = fopen(FILE_NAME, "rb");
    if (fp == NULL)
    {
        printf("No records found!\n");
        return;
    }

    // Check each record
    while (fread(&s, sizeof(s), 1, fp) == 1)
    {
        if (s.roll == searchRoll)
        {
            printf("\n[Found] Student Details:\n");
            printf("Roll   : %d\n", s.roll);
            printf("Name   : %s\n", s.name);
            printf("Course : %s\n", s.course);
            printf("Marks  : %.2f\n", s.marks);
            found = 1;
            break; // Stop after finding, roll is unique
        }
    }

    if (!found)
    {
        printf("[Not Found] No student with Roll %d.\n", searchRoll);
    }

    fclose(fp);
}

/* [STRIPPED 75 bytes]
 * Function: updateStudent
 * Purpose : Updates details of a student using Roll Number.
 * Logic   : Copy all records to a temp file, update the matching
 *           one, then replace original file with temp file.
 * [STRIPPED 75 bytes] */
void updateStudent()
{
    struct Student s;
    FILE *fp, *temp;
    int updateRoll, found = 0;

    printf("\n--- Update Student ---\n");
    printf("Enter Roll Number to update : ");
    scanf("%d", &updateRoll);

    fp = fopen(FILE_NAME, "rb");
    if (fp == NULL)
    {
        printf("No records found!\n");
        return;
    }

    temp = fopen("temp.dat", "wb"); // Temporary file
    if (temp == NULL)
    {
        printf("[Error] Could not create temp file!\n");
        fclose(fp);
        return;
    }

    // Copy records one by one, updating the matching one
    while (fread(&s, sizeof(s), 1, fp) == 1)
    {
        if (s.roll == updateRoll)
        {
            printf("\nCurrent Details: %s, %s, %.2f\n", s.name, s.course, s.marks);
            printf("Enter New Details:\n");

            clearInputBuffer();
            printf("Enter New Name : ");
            scanf("%[^\n]", s.name);
            clearInputBuffer();

            printf("Enter New Course : ");
            scanf("%[^\n]", s.course);
            clearInputBuffer();

            printf("Enter New Marks : ");
            scanf("%f", &s.marks);

            found = 1;
            printf("\n[Success] Student updated!\n");
        }
        fwrite(&s, sizeof(s), 1, temp); // Write (updated or same) to temp
    }

    fclose(fp);
    fclose(temp);

    // Replace old file with new file
    remove(FILE_NAME);
    rename("temp.dat", FILE_NAME);

    if (!found)
    {
        printf("[Not Found] No student with Roll %d.\n", updateRoll);
    }
}

/* [STRIPPED 75 bytes]
 * Function: deleteStudent
 * Purpose : Deletes a student record using Roll Number.
 * Logic   : Copy all records EXCEPT the one to delete to temp file,
 *           then replace original file with temp file.
 * [STRIPPED 75 bytes] */
void deleteStudent()
{
    struct Student s;
    FILE *fp, *temp;
    int deleteRoll, found = 0;

    printf("\n--- Delete Student ---\n");
    printf("Enter Roll Number to delete : ");
    scanf("%d", &deleteRoll);

    fp = fopen(FILE_NAME, "rb");
    if (fp == NULL)
    {
        printf("No records found!\n");
        return;
    }

    temp = fopen("temp.dat", "wb");
    if (temp == NULL)
    {
        printf("[Error] Could not create temp file!\n");
        fclose(fp);
        return;
    }

    while (fread(&s, sizeof(s), 1, fp) == 1)
    {
        if (s.roll == deleteRoll)
        {
            found = 1;
            printf("[Success] Student %s (Roll %d) deleted!\n", s.name, s.roll);
            continue; // Skip writing this record = delete it
        }
        fwrite(&s, sizeof(s), 1, temp); // Keep all other records
    }

    fclose(fp);
    fclose(temp);

    remove(FILE_NAME);
    rename("temp.dat", FILE_NAME);

    if (!found)
    {
        printf("[Not Found] No student with Roll %d.\n", deleteRoll);
    }
}

/* [STRIPPED 75 bytes]
 * Function: main
 * Purpose : Entry point. Shows menu and calls correct function
 *           using switch-case. Runs until user chooses Exit.
 * [STRIPPED 75 bytes] */
int main()
{
    int choice;

    printf("Welcome to Student Management System!\n");
    printf("Your data is saved permanently in %s\n", FILE_NAME);

    // Loop until Exit
    while (1)
    {
        displayMenu();

        if (scanf("%d", &choice) != 1)
        {
            printf("\n[Error] Please enter a number between 1 and 6.\n");
            clearInputBuffer();
            continue;
        }

        // Operation selection using SWITCH-CASE
        switch (choice)
        {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                updateStudent();
                break;
            case 5:
                deleteStudent();
                break;
            case 6:
                printf("\nThank you for using Student Management System. Goodbye!\n");
                return 0; // End program
            default:
                printf("\n[Error] Invalid choice! Please select 1 to 6.\n");
                break;
        }
    }
}
