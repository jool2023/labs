#include <stdio.h>

int main() {
    int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
    if (a == b || a == c || b == c){
        printf("Ошибка: есть равные числа");
    } else if((a > b && c < b) || (c > b && a < b)){
        printf("На числовой прямой средним будет число: %d", b);
    } else if((a > c && b < c) || (b > c && a < c)){
        printf("На числовой прямой средним будет число: %d", c);
    } else if ((c > a && b < a) || (b > a && c < a)){
        printf("На числовой прямой средним будет число: %d", a);
    }
}