#include <stdio.h>

int main() {
    int a, b;
    scanf("%d", &a);
    a = fabs(a);
    if (a >= 10 && a<=99){
        b = a / 10;
        printf("Число десятков: %d", b);
    }else {
        printf("В числе нет двух цифр");
    }
}