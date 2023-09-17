#include <stdio.h>
#include <math.h>

int main() {
    int i, i_square, N;
    printf("Введите число N \n");
    scanf("%d", &N);
    i = 1;
    i_square = pow(i, 2);
    while(i_square <= N){
        printf("%d \n", i_square);
        i++;
        i_square = pow(i, 2);
    }
}