/*
 * ============================================================================
 * Project Name : Medium - Matrix Operations
 * File         : matrix_operations.c
 * Description  : A menu-driven program to implement Matrix Addition,
 *                Matrix Multiplication and Transpose using functions
 *                and 2D arrays for better modularity.
 * Author       : Medium C Programming Project
 * Language     : C (C99 / C11 compatible)
 * ============================================================================
 */

#include <stdio.h>

#define MAX 10  // Maximum size of matrix (10 x 10). Change if needed.

/* [STRIPPED 75 bytes]
 * Function Prototypes
 * Each operation is kept in a separate function for modularity,
 * readability and easy maintenance.
 * [STRIPPED 75 bytes] */
void inputMatrix(int mat[MAX][MAX], int rows, int cols, char name);
void displayMatrix(int mat[MAX][MAX], int rows, int cols, const char *title);
void addMatrices(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int rows, int cols);
void multiplyMatrices(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int r1, int c1, int c2);
void transposeMatrix(int mat[MAX][MAX], int trans[MAX][MAX], int rows, int cols);
void displayMenu();
void clearInputBuffer();

/* [STRIPPED 75 bytes]
 * Function: inputMatrix
 * Purpose : Takes matrix elements from the user.
 * Params  : mat  - 2D array to store values
 *           rows - number of rows
 *           cols - number of columns
 *           name - matrix name to display (e.g. 'A' or 'B')
 * [STRIPPED 75 bytes] */
void inputMatrix(int mat[MAX][MAX], int rows, int cols, char name)
{
    int i, j;
    printf("\nEnter elements of Matrix %c (%d x %d):\n", name, rows, cols);
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("  %c[%d][%d] : ", name, i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}

/* [STRIPPED 75 bytes]
 * Function: displayMatrix
 * Purpose : Prints a matrix in a neat tabular format.
 * Params  : mat   - 2D array to display
 *           rows  - number of rows
 *           cols  - number of columns
 *           title - heading to show above the matrix
 * [STRIPPED 75 bytes] */
void displayMatrix(int mat[MAX][MAX], int rows, int cols, const char *title)
{
    int i, j;
    printf("\n%s (%d x %d):\n", title, rows, cols);
    for (i = 0; i < rows; i++)
    {
        printf("  ");
        for (j = 0; j < cols; j++)
        {
            printf("%5d ", mat[i][j]);
        }
        printf("\n");
    }
}

/* [STRIPPED 75 bytes]
 * Function: addMatrices
 * Purpose : Adds two matrices of same order.
 * Formula : result[i][j] = A[i][j] + B[i][j]
 * [STRIPPED 75 bytes] */
void addMatrices(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int rows, int cols)
{
    int i, j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

/* [STRIPPED 75 bytes]
 * Function: multiplyMatrices
 * Purpose : Multiplies two matrices.
 * Rule    : Columns of A must equal Rows of B.
 * Formula : result[i][j] = sum( A[i][k] * B[k][j] ) for k = 0 to c1-1
 * Params  : r1 = rows of A, c1 = cols of A (= rows of B), c2 = cols of B
 * [STRIPPED 75 bytes] */
void multiplyMatrices(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int r1, int c1, int c2)
{
    int i, j, k;
    // Initialize result matrix to 0 before accumulation
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c2; j++)
        {
            result[i][j] = 0;
        }
    }

    // Standard triple-loop multiplication
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c2; j++)
        {
            for (k = 0; k < c1; k++)
            {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

/* [STRIPPED 75 bytes]
 * Function: transposeMatrix
 * Purpose : Finds transpose of a matrix.
 * Formula : trans[j][i] = mat[i][j]
 * Note    : Rows and Columns get swapped in the result.
 * [STRIPPED 75 bytes] */
void transposeMatrix(int mat[MAX][MAX], int trans[MAX][MAX], int rows, int cols)
{
    int i, j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            trans[j][i] = mat[i][j];
        }
    }
}

/* [STRIPPED 75 bytes]
 * Function: displayMenu
 * Purpose : Displays the list of available matrix operations.
 * [STRIPPED 75 bytes] */
void displayMenu()
{
    printf("\n========================================\n");
    printf("     MEDIUM - MATRIX OPERATIONS        \n");
    printf("========================================\n");
    printf("  1. Matrix Addition\n");
    printf("  2. Matrix Multiplication\n");
    printf("  3. Transpose of Matrix\n");
    printf("  4. Exit\n");
    printf("========================================\n");
    printf("Enter your choice (1-4): ");
}

/* [STRIPPED 75 bytes]
 * Function: clearInputBuffer
 * Purpose : Clears invalid leftover input to prevent infinite loops.
 * [STRIPPED 75 bytes] */
void clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/* [STRIPPED 75 bytes]
 * Function: main
 * Purpose : Entry point. Shows menu, takes choice, calls the
 *           correct function using switch-case.
 * [STRIPPED 75 bytes] */
int main()
{
    int choice;

    // Matrices and their dimensions
    int A[MAX][MAX], B[MAX][MAX], result[MAX][MAX], trans[MAX][MAX];
    int r1, c1, r2, c2; // r = rows, c = columns

    printf("Welcome to Medium - Matrix Operations Program!\n");

    // Loop until user chooses Exit
    while (1)
    {
        displayMenu();

        // Validate menu choice input
        if (scanf("%d", &choice) != 1)
        {
            printf("\n[Error] Invalid input! Please enter a number between 1 and 4.\n");
            clearInputBuffer();
            continue;
        }

        // Exit condition - checked before asking for matrix data
        if (choice == 4)
        {
            printf("\nThank you for using Matrix Operations Program. Goodbye!\n");
            break;
        }

        // Operation selection using SWITCH-CASE
        switch (choice)
        {
            case 1: // ---------- MATRIX ADDITION ----------
            {
                printf("\n--- Matrix Addition ---\n");
                printf("Note: Both matrices must have the SAME order.\n");

                printf("Enter rows for Matrix A and B : ");
                scanf("%d", &r1);
                printf("Enter columns for Matrix A and B : ");
                scanf("%d", &c1);

                // Validation: size must be within limit and positive
                if (r1 <= 0 || c1 <= 0 || r1 > MAX || c1 > MAX)
                {
                    printf("[Error] Invalid size! Use values between 1 and %d.\n", MAX);
                    break;
                }

                inputMatrix(A, r1, c1, 'A');
                inputMatrix(B, r1, c1, 'B');

                addMatrices(A, B, result, r1, c1);

                displayMatrix(A, r1, c1, "Matrix A");
                displayMatrix(B, r1, c1, "Matrix B");
                displayMatrix(result, r1, c1, "Result (A + B)");
                break;
            }

            case 2: // ---------- MATRIX MULTIPLICATION ----------
            {
                printf("\n--- Matrix Multiplication ---\n");
                printf("Rule: Columns of A must equal Rows of B.\n");

                printf("Enter rows and columns for Matrix A (r c) : ");
                scanf("%d %d", &r1, &c1);
                printf("Enter rows and columns for Matrix B (r c) : ");
                scanf("%d %d", &r2, &c2);

                // Validation: size check
                if (r1 <= 0 || c1 <= 0 || r2 <= 0 || c2 <= 0 ||
                    r1 > MAX || c1 > MAX || r2 > MAX || c2 > MAX)
                {
                    printf("[Error] Invalid size! Use values between 1 and %d.\n", MAX);
                    break;
                }

                // Validation: multiplication rule
                if (c1 != r2)
                {
                    printf("\n[Error] Multiplication NOT possible!\n");
                    printf("Columns of A (%d) must equal Rows of B (%d).\n", c1, r2);
                    break;
                }

                inputMatrix(A, r1, c1, 'A');
                inputMatrix(B, r2, c2, 'B');

                multiplyMatrices(A, B, result, r1, c1, c2);

                displayMatrix(A, r1, c1, "Matrix A");
                displayMatrix(B, r2, c2, "Matrix B");
                displayMatrix(result, r1, c2, "Result (A x B)");
                break;
            }

            case 3: // ---------- TRANSPOSE ----------
            {
                printf("\n--- Transpose of Matrix ---\n");

                printf("Enter rows for Matrix : ");
                scanf("%d", &r1);
                printf("Enter columns for Matrix : ");
                scanf("%d", &c1);

                if (r1 <= 0 || c1 <= 0 || r1 > MAX || c1 > MAX)
                {
                    printf("[Error] Invalid size! Use values between 1 and %d.\n", MAX);
                    break;
                }

                inputMatrix(A, r1, c1, 'A');

                transposeMatrix(A, trans, r1, c1);

                displayMatrix(A, r1, c1, "Original Matrix");
                // Note: rows and cols are swapped for transpose
                displayMatrix(trans, c1, r1, "Transpose Matrix");
                break;
            }

            default: // Invalid menu choice
                printf("\n[Error] Invalid choice! Please select between 1 and 4.\n");
                break;
        }
    }

    return 0; // Successful termination
}
