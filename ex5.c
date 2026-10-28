#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef unsigned int ui;
typedef struct array Array;

struct array{
    float* values;
    ui size;
};

Array* Array_Read(ui N);
void Array_Destroy(Array* array);
void Array_Print(Array* array);
int Array_Search(Array* array, float value);
void Array_Print_Duplicates(Array* array, float value);

int main(){
    printf("Enter Array Size: \n");
    ui size;
    scanf("%u", &size);

    printf("Enter %u Array Values\n", size);
    Array* array = Array_Read(size);
    Array_Print(array);

    printf("Enter value to be found\n");
    float value;
    scanf("%f", &value);
    
    printf("Searching for value: %f\n", value);
    
   
    Array_Print_Duplicates(array, value);

    Array_Destroy(array);
    return 0;
}

void Array_Print_Duplicates(Array* array, float value){
    int key = Array_Search(array, value);

    if(key < 0){
        printf("Value not found!\n");
    } else {
        int duplicado = key;
        
        while(duplicado >= 0 && *(array->values + duplicado) == value){
            duplicado--;
        }
        duplicado++;

        printf("indices duplicados: ");
        for(int i = duplicado; i <= key; i++){
            printf("%d ", i);
        }
        printf("\n");

        printf("valores duplicado: ");
    for(int i = duplicado; i <= key; i++){
        printf("%f ", *(array->values + i));
    }
    printf("\n");
        
    }
    
}

int Array_Search(Array* array, float value){
    ui i = 0;
    bool found = false;

    while(i < array->size && *(array->values + i) <= value){
        if(*(array->values + i) == value){
            found = true;
        }
        i = i + 1;
    }
    
    if(!found){
        return -1;
    }
    
    return i - 1; 
}

Array* Array_Read(ui size){
    Array* array = malloc(sizeof(Array));
    array->size = size;
    array->values = malloc(sizeof(float) * size);
    for(ui i = 0; i < size; i++){
        scanf("%f", array->values + i);
    }
    return array;
}

void Array_Destroy(Array* array){
    free(array->values);
    free(array);
}

void Array_Print(Array* array){
    printf("[");
    for(ui i = 0; i < array->size; i++){
        printf("%f", *(array->values + i));
        if(i < array->size - 1){
            printf(", ");
        }
    }
    printf("]\n");
}