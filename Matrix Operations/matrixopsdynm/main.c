#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int **alloc_matrix(int rows, int columns); //Allocate memory for matrix of size rows*columns
void read_matrix(int **Matrix_Pointer, int rows, int columns); // Reads matrix after memory allocation
void display_matrix(int **Matrix_Pointer, int rows, int columns); //Print the matrix of given size
int **matrix_multiply(int **Matrix_A, int rows_A, int columns_A,int **Matrix_B, int rows_B, int columns_B,int *result_rows, int *result_col); //Multiplies A,B and returns the resultant pointer
int **matrix_transpose(int **Matrix, int rows, int columns,int *result_rows, int *result_col); //return transpose of given matrix
int **matrix_add(int **Matrix_A, int rows_A, int columns_A,int **Matrix_B, int rows_B, int columns_B,int *result_rows, int *result_col); //Adds two matrices and returns a pointer to the result
void make_null(int **Matrix, int rows, int columns); //Initializes all elements to 0
int make_menu(void); //Creates defualt menu

int main()
{
    int **Matrix_PointerA, **Matrix_PointerB, **Result_Matrix;
    int rows_A, columns_A, rows_B, columns_B,final_rows, final_col, answer;

    do
    {
        switch(make_menu())
        {
        case 1: //Transpose
            printf("Enter # of rows and columns of matrix: ");
            scanf("%d %d",&rows_A,&columns_A);
            Matrix_PointerA = alloc_matrix(rows_A,columns_A);
            read_matrix(Matrix_PointerA,rows_A,columns_A);
            Result_Matrix = matrix_transpose(Matrix_PointerA,rows_A,columns_A,&final_rows,&final_col);
            break;

        case 2: //Multiplication
            printf("Enter # of rows and columns of matrix A: ");
            scanf("%d %d",&rows_A,&columns_A);
            Matrix_PointerA = alloc_matrix(rows_A,columns_A);
            read_matrix(Matrix_PointerA,rows_A,columns_A);
            printf("Enter # of rows and columns of matrix B: ");
            scanf("%d %d",&rows_B,&columns_B);
            Matrix_PointerB = alloc_matrix(rows_B,columns_B);
            read_matrix(Matrix_PointerB,rows_B,columns_B);
            Result_Matrix = matrix_multiply(Matrix_PointerA, rows_A, columns_A, Matrix_PointerB, rows_B, columns_B, &final_rows, &final_col);
            break;

        case 3: //Addition
            printf("Enter # of rows and columns of matrix A: ");
            scanf("%d %d",&rows_A,&columns_A);
            Matrix_PointerA = alloc_matrix(rows_A,columns_A);
            read_matrix(Matrix_PointerA,rows_A,columns_A);
            printf("Enter # of rows and columns of matrix B: ");
            scanf("%d %d",&rows_B,&columns_B);
            Matrix_PointerB = alloc_matrix(rows_B,columns_B);
            read_matrix(Matrix_PointerB,rows_B,columns_B);
            Result_Matrix = matrix_add(Matrix_PointerA, rows_A, columns_A, Matrix_PointerB, rows_B, columns_B, &final_rows, &final_col);
            break;

        default: //Wrong choice
            printf("\nWrong choice entered!\n");

        }
        if(Result_Matrix != NULL) //NULL implies error in a prior operation
            display_matrix(Result_Matrix,final_rows,final_col);
        printf("\n\nPress 1 to re-run the program: ");
        scanf("%d",&answer);
    }
    while(answer == 1);
    return 0;
}

// Interface creation
int make_menu(void)
{
    void make_heading(char s[]); //makes centered heading
    char heading[20] = "MATRIX OPERATIONS";
    int choice,i,j;
    //printf("Enter name of program: ");
    //gets(heading);
    make_heading(heading);
    printf("1.Transpose\t2.Multiplication\t3.Addition\n\nChoose required operation: ");
    scanf("%d",&choice);
    return choice;
}

void make_heading(char s[])
{
    int i, j, tabs_to_center=3;
    system("clear");
    i = strlen(s);
    for(j=0; j<tabs_to_center; j++)
        putchar('\t');
    for(j=0; j<= (i+1); j++)
        putchar('#');
    putchar('\n');
    for(j=0; j<tabs_to_center; j++)
        putchar('\t');
    putchar(' ');
    for(j=0; j<i; j++)
        putchar(s[j]);
    putchar(' ');
    putchar('\n');
    for(j=0; j<tabs_to_center; j++)
        putchar('\t');
    for(j=0; j<= (i+1); j++)
        putchar('#');
    printf("\n\n");
}
//End of interface module


int **alloc_matrix(int rows, int columns)
{
    int i, j;
    int **Matrix_Pointer;
    Matrix_Pointer = (int **)malloc(rows * sizeof(int *));
    for(i=0; i<rows; i++)
        for(j=0; j<columns; j++)
            Matrix_Pointer[i] = (int *)malloc(columns * sizeof(int));

    return Matrix_Pointer;
}

void read_matrix(int **Matrix_Pointer, int rows, int columns)
{
    int i, j;
    printf("Enter space seperated elements, and proceed to the next row by pressing enter:\n");
    for(i=0; i<rows; i++)
    {
        for(j=0; j<columns; j++)
        {
            scanf("%d",(*(Matrix_Pointer + i) + j));
        }
    }
}

void make_null(int **Matrix, int rows, int columns)
{
    int i, j;
    for(i=0; i < rows; i++)
        for(j=0; j < columns; j++)
            *(*(Matrix + i) + j) = 0;
}

int **matrix_multiply(int **Matrix_A, int rows_A, int columns_A,int **Matrix_B, int rows_B, int columns_B,int *result_rows, int *result_col)
{
    int **Resultant_Matrix, i, j, k;
    //Check if the matrices are compatible for multiplication:
    //Columns A = Rows B
    if(columns_A != rows_B)
    {
        printf("\nThe matrices are of incompatible sizes and hence cannot be multiplied!\n");
        return NULL; //Error
    }
    //Else proceed for multiplication
    //Allocate memory for new matrix of size  Rows_A*Columns_B and initialize to 0
    Resultant_Matrix = alloc_matrix(rows_A,columns_B);
    make_null(Resultant_Matrix, rows_A, columns_B);
    *result_col = columns_B;
    *result_rows = rows_A;
    //Start muliplication
    for(i=0; i < rows_A; i++)
        for(j=0; j < columns_B; j++)
            for(k=0; k < rows_B; k++)
                //Resultant[i][j] = MatrixA[i][k] * MatrixB[k][j]
                *(*(Resultant_Matrix + i) + j) += (*(*(Matrix_A + i) + k) * *(*(Matrix_B + k) + j));

    return Resultant_Matrix;
}

int **matrix_add(int **Matrix_A, int rows_A, int columns_A,int **Matrix_B, int rows_B, int columns_B,int *result_rows, int *result_col)
{
    int **Resultant_Matrix, i, j;
    *result_col = columns_A;
    *result_rows = rows_A;
    if((rows_A != rows_B) && (columns_A != columns_B))
    {
        printf("\nThe matrices are of incompatible sizes and hence cannot be added!\n");
        return NULL; //Error
    }
    //Else proceed for addition
    //Allocate memory for new matrix of size  Rows_(AorB)*Columns_(AorB) and initialize to 0
    Resultant_Matrix = alloc_matrix(rows_A,columns_A);
    for(i = 0; i < rows_A; i++)
        for(j = 0; j < columns_A; j++)
            *(*(Resultant_Matrix + i) + j) = *(*(Matrix_A + i) + j) + *(*(Matrix_B + i) + j);

    return Resultant_Matrix;
}

int **matrix_transpose(int **Matrix, int rows, int columns,int *result_rows, int *result_col)
{
    void swap_2D(int *element1, int *element2); //swap elements of 2d array
    int **Resultant_Matrix, i, j, temp;
    *result_rows = columns;
    *result_col = rows;
    printf("Do you want to swap the elements of this matrix, or create a new matrix for storing transpose?\n1.Swap   2.Create new\n");
    scanf("%d",&temp);
    if(temp == 2) //New Matrix
    {
        //Allocate memory for resultant matrix. As its a transpose dimensions will be interchanged.
        Resultant_Matrix = alloc_matrix(columns,rows);
        //Copy original matrix here
        for(i = 0; i < rows; i++)
            for(j = 0; j < columns; j++)
                *(*(Resultant_Matrix + i) + j) = *(*(Matrix + i) + j) ;
    }
    //Swap elements
    for(i = 0; i < rows; i++)
    {
        for(j = (i + 1); j < columns; j++)
        {
            if(temp == 2)
                swap_2D(*(Resultant_Matrix + i) + j, *(Resultant_Matrix + j) + i); //swap copied matrix
            else
                swap_2D(*(Matrix + i) + j, *(Matrix + j) + i); //swap M[i][j] , M[j][i]
        }
    }


    if(temp == 2)
        return Resultant_Matrix; //return new matrix
    else
        return Matrix;  //return the same matrix

}

void swap_2D(int *element1, int *element2)
{
    int temp;
    temp = *element1;
    *element1 = *element2;
    *element2 = temp;
}
void display_matrix(int **Matrix_Pointer, int rows, int columns)
{
    int i, j;
    printf("\n\nThe resultant matrix is: \n");
    for(i=0; i<rows; i++)
    {
        for(j=0; j<columns; j++)
        {
            printf("%d ",*(*(Matrix_Pointer + i) + j));
        }
        putchar('\n');
    }
}
