// Online C compiler to run C program online
#include <stdio.h>

int main() {
    int a, b, c, sum;
    scanf("%d %d", &a, &b);
    
    if (b > a){
        c = a;
        a = b;
        b = c;
    }else if( a == b){
        printf("Ошибка: значение конца и начала отрезка совпадают");
    }
    for(int i = a; i <= b; i++){
        sum = 0;
        for(int j = 1; j <= i; i++){
            if(i%j == 0){
                  sum += 1;
            }
        if(sum == 2){
            printf("%d", i);
        }
        }
    }
}