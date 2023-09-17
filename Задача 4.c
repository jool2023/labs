#include <stdio.h>

int main() {
    int a, b;
    scanf("%d", &a);
    if (a >= 10){
        b = a % 100;
        b = b / 10;
        printf("Вторая цифра справа: %d", b);
    }else {
        printf("В числе нет двух цифр или оно отрицательное");
    }
}