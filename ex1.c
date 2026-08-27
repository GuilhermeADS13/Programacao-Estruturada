#include <stdio.h>

int is_number_character(int c){
    return (c >= '0' && c <= '9');
}

int main()
{
    int numbers_total = 0;
    int within = 0;

    int c;

    while(1){
        c = getchar();

        if(c == EOF){
            break;
        }

        if(!within && is_number_character(c)){
            within = 1;
            numbers_total++;
        }else if(within && !is_number_character(c) && c != '.'){
            within = 0;
        }
    }

    printf("Total de numeros: %d\n", numbers_total);

    return 0;
}
