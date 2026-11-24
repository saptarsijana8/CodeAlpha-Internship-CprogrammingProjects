/*
 * ============================================================================
 * Project Name : Basic - Calculator Program
 * File         : calculator.c
 * Description  : A simple console-based calculator that performs basic
 *                arithmetic operations - Addition, Subtraction,
 *                Multiplication and Division using switch-case.
 * Author       : Basic C Programming Project
 * Language     : C (C99 / C11 compatible)
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>  // For exit() and system clear (optional)

/* ---------------------------------------------------------------------------
 * Function Prototypes
 * Each operation is kept in a separate function for readability,
 * reusability and easy maintenance.
 * --------------------------------------------------------------------------- */
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
void displayMenu();
void clearInputBuffer();

/* ---------------------------------------------------------------------------
 * Function: add
 * Purpose : Returns the sum of two numbers.
 * --------------------------------------------------------------------------- */
double add(double a, double b)
{
    return a + b;
}

/* ---------------------------------------------------------------------------
 * Function: subtract
 * Purpose : Returns the difference of two numbers (a - b).
 * --------------------------------------------------------------------------- */
double subtract(double a, double b)
{
    return a - b;
}

/* ---------------------------------------------------------------------------
 * Function: multiply
 * Purpose : Returns the product of two numbers.
 * --------------------------------------------------------------------------- */
double multiply(double a, double b)
{
    return a * b;
}

/* ---------------------------------------------------------------------------
 * Function: divide
 * Purpose : Returns the quotient of two numbers (a / b).
 * Note    : Division by zero is checked in main() before calling this.
 * --------------------------------------------------------------------------- */
double divide(double a, double b)
{
    return a / b;
}

/* ---------------------------------------------------------------------------
 * Function: displayMenu
 * Purpose : Displays the list of available operations to the user.
 * --------------------------------------------------------------------------- */
void displayMenu()
{
    printf("\n========================================\n");
    printf("      BASIC - CALCULATOR PROGRAM       \n");
    printf("========================================\n");
    printf("  1. Addition       (+) \n");
    printf("  2. Subtraction    (-) \n");
    printf("  3. Multiplication (*) \n");
    printf("  4. Division       (/) \n");
    printf("  5. Exit \n");
    printf("========================================\n");
    printf("Enter your choice (1-5): ");
}

/* ---------------------------------------------------------------------------
 * Function: clearInputBuffer
 * Purpose : Clears invalid leftover input from stdin to prevent
 *           infinite loops when user enters non-numeric data.
 * --------------------------------------------------------------------------- */
void clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/* ---------------------------------------------------------------------------
 * Function: main
 * Purpose : Entry point of the program.
 * Logic   : 1. Show menu in a loop
 *           2. Take user's choice
 *           3. Take two numbers (if choice is 1-4)
 *           4. Use switch-case to call the correct operation
 *           5. Display result
 *           6. Repeat until user chooses Exit
 * --------------------------------------------------------------------------- */
int main()
{
    int choice;          // Stores user's menu choice
    double num1, num2;   // Stores the two operands
    double result;       // Stores the calculation result
    char continueChoice; // For asking user if they want to continue (optional)

    printf("Welcome to Basic Calculator Program!\n");

    // Infinite loop - exits only when user selects option 5
    while (1)
    {
        // Step 1: Display menu and get choice
        displayMenu();

        // Validate choice input - must be an integer
        if (scanf("%d", &choice) != 1)
        {
            printf("\n[Error] Invalid input! Please enter a number between 1 and 5.\n");
            clearInputBuffer();
            continue;
        }

        // Step 2: Handle Exit choice before asking for numbers
        if (choice == 5)
        {
            printf("\nThank you for using Basic Calculator. Goodbye!\n");
            break; // Exit the loop and end program
        }

        // Step 3: Validate choice range (1-4 are valid operations)
        if (choice < 1 || choice > 5)
        {
            printf("\n[Error] Invalid choice! Please select a number between 1 and 5.\n");
            continue;
        }

        // Step 4: Take two numbers from user
        printf("Enter first number  : ");
        if (scanf("%lf", &num1) != 1)
        {
            printf("\n[Error] Invalid number! Please try again.\n");
            clearInputBuffer();
            continue;
        }

        printf("Enter second number : ");
        if (scanf("%lf", &num2) != 1)
        {
            printf("\n[Error] Invalid number! Please try again.\n");
            clearInputBuffer();
            continue;
        }

        // Step 5: Perform operation using SWITCH-CASE
        // This is the core requirement of the project.
        printf("\n----------------------------------------\n");
        printf("Result: ");

        switch (choice)
        {
            case 1: // Addition
                result = add(num1, num2);
                printf("%.2lf + %.2lf = %.2lf\n", num1, num2, result);
                break;

            case 2: // Subtraction
                result = subtract(num1, num2);
                printf("%.2lf - %.2lf = %.2lf\n", num1, num2, result);
                break;

            case 3: // Multiplication
                result = multiply(num1, num2);
                printf("%.2lf * %.2lf = %.2lf\n", num1, num2, result);
                break;

            case 4: // Division
                // Special check: Division by zero is not allowed
                if (num2 == 0)
                {
                    printf("\n[Error] Division by zero is not allowed!\n");
                }
                else
                {
                    result = divide(num1, num2);
                    printf("%.2lf / %.2lf = %.2lf\n", num1, num2, result);
                }
                break;

            default: // This will never run because of earlier validation,
                     // but kept for completeness and safety.
                printf("\n[Error] Invalid choice!\n");
                break;
        }
        printf("----------------------------------------\n");

        // Optional: Ask user if they want to continue (press Enter to continue)
        // The loop will show menu again automatically.
    }

    return 0; // Successful program termination
}