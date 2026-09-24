#include <stdio.h>
#include <stdlib.h>


int** Matrix_Create(int rows, int columns);
void Matrix_Destroy(int** A, int rows);
void Matrix_Print(int** A, int rows, int columns);
int** Matrix_Transposta(int** A, int rows, int columns);

int main(){

    int rows;
    int columns;

    scanf("%d %d", &rows, &columns);

    int** A = Matrix_Create(rows, columns);

    Matrix_Print(A, rows, columns);

    int** T = Matrix_Transposta(A, rows, columns);

    Matrix_Print(T, columns, rows);

    Matrix_Destroy(A, rows);
    Matrix_Destroy(T, columns);

    return 0;
}


int** Matrix_Create(int rows, int columns){
    int** A = malloc(sizeof(int*) * rows);

    for(int i = 0; i < rows; i++){
        *(A + i) = malloc(sizeof(int) * columns);
        for(int j = 0; j < columns; j++){
            int Aij;
            scanf("%d", &Aij);
            *(*(A + i) + j) = Aij; 
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


int** Matrix_Transposta(int** A, int rows, int columns){
    int** T = malloc(sizeof(int*) * columns);

    for(int i = 0; i < columns; i++){
        *(T + i) = malloc(sizeof(int) * rows);
        for(int j = 0; j < rows; j++){
            *(*(T + i) + j) = *(*(A + j) + i); 
        }
    }

    return T;
    printf("Transposta\n"); 
}


