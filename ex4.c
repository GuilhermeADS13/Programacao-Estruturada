#include <stdio.h>
#include <stdlib.h>


int** Matrix_Create(int rows, int columns);
void Matrix_Destroy(int** A, int rows);
void Matrix_Print(int** A, int rows, int columns);
int** Matrix_Transpose(int** A, int* rows, int* columns);
int** Matrix_Multiply(int** A, int rowsA, int columnsA, int** B, int rowsB, int columnsB);
double** Matrix_MultiplyDouble(int** A, int rowsA, int columnsA, double** B, int rowsB, int columnsB);
double** Matrix_Inversa(int** A);
void Matrix_PrintDouble(double** A, int rows, int columns);
void Matrix_DestroyDouble(double** A, int rows);

int main(){

    int rowsA;
    int columnsA;

    printf("Enter Matrix A:\n");
    scanf("%d %d", &rowsA, &columnsA);
    int** A = Matrix_Create(rowsA, columnsA);
    Matrix_Print(A, rowsA, columnsA);


    // int rowsB;
    // int columnsB;
    // printf("Enter Matrix B:\n");
    // scanf("%d %d", &rowsB, &columnsB);
    // int** B = Matrix_Create(rowsB, columnsB);
    // Matrix_Print(B, rowsB, columnsB);


    // int** C = Matrix_Multiply(A, rowsA, columnsA, B, rowsB, columnsB);
    // printf("Matrix C = AB:\n");
    // Matrix_Print(C, rowsA, columnsB);


    if(rowsA == 2 && columnsA == 2){
        int calc = *(*(A+0)+0) * *(*(A+1)+1) - *(*(A+0)+1) * *(*(A+1)+0);

        double** Ainversa = Matrix_Inversa(A);
        printf("Matrix A = (1/%d) *\n", calc);
        Matrix_PrintDouble(Ainversa, 2, 2);

        double** I = Matrix_MultiplyDouble(A, 2, 2, Ainversa, 2, 2);
        printf("Matrix A^-1 A = %d * I:\n", calc);
        }

    Matrix_Destroy(A, rowsA);
    // Matrix_Destroy(B, rowsB);
    // Matrix_Destroy(C, rowsA);

    return 0;
}


int** Matrix_Create(int rows, int columns){
    int** A = malloc(sizeof(int*) * rows);

    for(int i = 0; i < rows; i++){
        *(A + i) = malloc(sizeof(int) * columns);
        for(int j = 0; j < columns; j++){
            int Aij;
            scanf("%d", &Aij);
            *(*(A + i) + j) = Aij; //A[i,j]
        }
    }

    return A;
}

void Matrix_Destroy(int** A, int rows){
    for(int i = 0; i < rows; i++){
        free(*(A + i));
    }
    free(A);
}


void Matrix_Print(int** A, int rows, int columns){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            printf("%d", *(*(A+i) + j) );
            printf(" ");
        }
        printf("\n");
    }
}


int** Matrix_Transpose(int** A, int* rows, int* columns){
    int** At = malloc(sizeof(int*) * (*columns));

    for(int i = 0; i < *columns; i++){
        *(At + i) = malloc(sizeof(int) * (*rows));
        for(int j = 0; j < *rows; j++){
            *(*(At + i) + j) = *(*(A + j) + i);
        }

    }
    return At;
}


int** Matrix_Multiply(int** A, int rowsA, int columnsA, int** B, int rowsB, int columnsB){
  

    int** C = malloc(sizeof(int*) * rowsA);

    for(int i = 0; i < rowsA; i++){
        *(C + i) = malloc(sizeof(int) * columnsB);
        for(int j = 0; j < columnsB; j++){
            int Cij = 0;
            for(int k = 0; k < columnsA; k++){ //k < rowsB also
                int Aik = *(*(A+i)+k);
                int Bkj = *(*(B+k)+j);
                Cij += Aik * Bkj;
            }
            *(*(C+i)+j)  = Cij;
        }
    }

    return C;

}


double** Matrix_MultiplyDouble(int** A, int rowsA, int columnsA, double** B, int rowsB, int columnsB){
    double** C = malloc(sizeof(double*) * rowsA);

    for(int i = 0; i < rowsA; i++){
        *(C + i) = malloc(sizeof(double) * columnsB);
        for(int j = 0; j < columnsB; j++){
            double Cij = 0.0;
            for(int k = 0; k < columnsA; k++){
                double Aik = (double) *(*(A+i)+k);
                double Bkj = *(*(B+k)+j);
                Cij += Aik * Bkj;
            }
            *(*(C+i)+j) = Cij;
        }
    }

    return C;
}


double** Matrix_Inversa(int** A){
    double a = *(*(A + 0) + 0);
    double b = *(*(A + 0) + 1);
    double c = *(*(A + 1) + 0);
    double d = *(*(A + 1) + 1);

    double** Ainversa = malloc(sizeof(double*) * 2);
    *(Ainversa + 0) = malloc(sizeof(double) * 2);
    *(Ainversa + 1) = malloc(sizeof(double) * 2);

    *(*(Ainversa + 0) + 0) =  d;
    *(*(Ainversa + 0) + 1) = -b;
    *(*(Ainversa + 1) + 0) = -c;
    *(*(Ainversa + 1) + 1) =  a;

    return Ainversa;
}


