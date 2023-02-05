#include <stdio.h>

#define MAXDATA 10

typedef struct {
  int data[MAXDATA][MAXDATA];
  int row;
  int col;
} Matrix;

void printmat(Matrix M);
Matrix matrixmult(Matrix A, Matrix B);

int main(void)
{
  Matrix A = { {{2, 3},{4, 5},{6, 7}}, 3, 2};
  Matrix B = { {{5, 6, 7},{2, 1, 3}}, 2, 3}; 
  
  printmat(A);
  printf("\n");
  printmat(B);

  Matrix C = matrixmult(A, B);
  printmat(C);

  return 0;
}

void printmat(Matrix M)
{
    for (int i = 0; i < M.row; i++)
    {
        for (int j = 0; j < M.col; j++)
        {
            printf("%i ", M.data[i][j]);
        }
        printf("\n");
    }
}

Matrix matrixmult(Matrix A, Matrix B)
{
    if (A.row != B.col)
    {
        printf("not multiplyable Matrices ");
    }

    Matrix C;
    C.row = C.col = A.row;

        for (int i = 0; i < A.row; i++)
        {
            for (int k = 0; k < B.col; k++)
            {   
                int mult = 0;
                for (int j = 0; j < A.col; j++)
                {
                    mult += A.data[i][j]*B.data[j][k];
                }
                C.data[i][k] = mult;
            }
        }
    return C;    
}