#include <stdio.h>
#include <math.h>

int main() {
    int i, n, result;
    scanf("%d", &n);
    result = 0;
    i = 0;
    while(result != 1){
        if(pow(22, i) == n){
            result++;
            printf("Да, является (%d степень)", i);
        } else if(pow(22, i) > n){
            result++;
            printf("Не является степенью числа 22");
        } else if(pow(22, i) < n){
            i++;
        }
    }
}