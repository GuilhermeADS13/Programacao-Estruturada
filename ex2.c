#include <stdio.h>
#include <stdlib.h>

float vector_dot(float* values1, float* values2, unsigned int n);
float* vector_read(unsigned int n);

int main(){
    unsigned int n;
    scanf("%u", &n);
    float* vetor1 = vector_read(n);
    float* vetor2 = vector_read(n);

    float dot = vector_dot(vetor1, vetor2, n);

    printf("%f", dot);
    
    if ((dot!=0)) {
        printf("Os vetores nao sao ortogonais\n");
    } else {
        printf("Os vetores  sao ortogonais\n");
    }

    free(vetor1);
    free(vetor2);

    return 0;
}

float* vector_read(unsigned int n){
    float* values = malloc(sizeof(float) * n);
    for(unsigned int i = 0; i < n; i++){
        scanf("%f", values + i);
    }
    return values;
}

float vector_dot(float* values1, float* values2, unsigned int n){
    float dot = 0;
    for(unsigned int i = 0; i < n; i++){
        dot += values1[i] * values2[i];
    }
    return dot;
}
