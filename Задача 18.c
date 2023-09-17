#include <stdio.h>

int main() {
    int min, max, number;
    printf("Введите первое число последовательности \n");
    scanf("%d", &number);
    min = number;
    max = number;
    while(number != 0){
        if(number > max){
            max = number;
            printf("Введите следующее число последовательности \n");
            scanf("%d", &number);
        } else if(number < min){
            min = number;
            printf("Введите следующее число последовательности \n");
            scanf("%d", &number);
        } else{
        printf("Введите следующее число последовательности \n");
        scanf("%d", &number);
        }
    }
    printf("Минимальное число в последовательности: %d \n", min);
    printf("Максимальное число в последовательности: %d \n", max);
}