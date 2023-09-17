#include <stdio.h>

int main() {
    int x1, y1, x2, y2;
    float c;
	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    c = sqrt(pow(fabs(x1 - x2), 2) + pow(fabs(y1 - y2), 2));
    printf("%f", c);
}