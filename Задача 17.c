#include <stdio.h>

int main() {
    int number, summa;
    printf("Введите первое число последовательности \n");
    scanf("%d", &number);
    while(number != -9999){
        summa += number;
        printf("%d \n", number);
        printf("Введите следующее число последовательности \n");
        scanf("%d", &number);
    }
    summa += -9999;
    printf("Сумма чисел последовательности: %d", summa);
}