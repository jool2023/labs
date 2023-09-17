#include <stdio.h>

int main() {
    int a, b, c, dis;
    float x1, x2;
	scanf("%d %d %d", &a, &b, &c);
	dis = pow(b, 2) - 4 * a *c;
    if (dis < 0){
        printf("Нет корней в множестве действительных чисел");
    } else if(dis == 0){
        x1 = (float)(b * -1)/(2 * a);
        printf("Единственный корень уравнения: %f", x1);
    } else{
        x1 = (float)(b * (-1) - sqrt(dis))/(2 * a);
        x2 = (float)(b * (-1) + sqrt(dis))/(2 * a);
        printf("Корни уравнения: %f %f", x1, x2);
    }
}