#1
#include <stdio.h>

int main() {
    int a = 5;
    int b = 10;
    int temp;

    printf("�������� ��������: a = %d, b = %d\n", a, b);

    // ���������� ��������� ���������� ��� ������ ����������
    temp = a;
    a = b;
    b = temp;

    printf("����� ������: a = %d, b = %d\n", a, b);

    return 0;
}

#2
#include <stdio.h>
#include <math.h>

int main() {
    double a, b, hypotenuse;

    // ������ �������� �������
    printf("������� ����� ������� ������ (a): ");
    scanf("%lf", &a);

    printf("������� ����� ������� ������ (b): ");
    scanf("%lf", &b);

    // ������� ����������
    hypotenuse = sqrt(a * a + b * b);

    // ������� ���������
    printf("���������� ������������ � �������� a = %lf � b = %lf ����� %lf\n", a, b, hypotenuse);

    return 0;
}


�3
#include <stdio.h>

int main() {
    int number;

    // ������ ����������� �����
    printf("������� ����������� �����: ");
    scanf("%d", &number);

    // ��������� ��������� �����
    int lastDigit = number % 10;

    // ������� ��������� �����
    printf("��������� ����� ���������� �����: %d\n", lastDigit);

    return 0;
}


�4
#include <stdio.h>

int main() {
    int number;

    // ������ ��������������� ����� �����
    printf("������� ��������������� ����� �����: ");
    scanf("%d", &number);

    // ������� ����� ��������
    int tens = (number / 10) % 10;

    // ������� ����� ��������
    printf("����� ��������: %d\n", tens);

    return 0;
}


�5
#include <stdio.h>

int main() {
    int twoDigitNumber;

    // ������ ���������� �����
    printf("������� ���������� �����: ");
    scanf("%d", &twoDigitNumber);

    // ���������, ��� ��������� ����� �������� ����������
    if (twoDigitNumber >= 10 && twoDigitNumber <= 99) {
        // ������� ����� ��������
        int tens = twoDigitNumber / 10;

        // ������� ����� ��������
        printf("����� ��������: %d\n", tens);
    } else {
        printf("������: ������� ���������� �����.\n");
    }

    return 0;
}


�6
#include <stdio.h>

int main() {
    int a, b;
    double average;

    // ������ ��� ������������� ����������
    printf("������� ��� ����� �����: ");
    scanf("%d %d", &a, &b);

    // ������� ������� ��������������
    average = (double)(a + b) / 2.0;

    // ������� ������� ��������������
    printf("������� �������������� ����� %d � %d: %.2lf\n", a, b, average);

    return 0;
}


�7
#include <stdio.h>
#include <math.h>

int main() {
    int a, b;
    double geometric_mean;

    // ������ ��� ������������� ����������
    printf("������� ��� ����� �����: ");
    scanf("%d %d", &a, &b);

    // ������� ������� ��������������
    geometric_mean = sqrt((double)a * b);

    // ������� ������� ��������������
    printf("������� �������������� ����� %d � %d: %.2lf\n", a, b, geometric_mean);

    return 0;
}


�8
#include <stdio.h>
#include <math.h>

int main() {
    double x1, y1, x2, y2;
    double distance;

    // ������ ���������� ������ �����
    printf("������� ���������� ������ ����� (x1 y1): ");
    scanf("%lf %lf", &x1, &y1);

    // ������ ���������� ������ �����
    printf("������� ���������� ������ ����� (x2 y2): ");
    scanf("%lf %lf", &x2, &y2);

    // ������� ���������� ����� �������
    distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

    // ������� ����������
    printf("���������� ����� �������: %.2lf\n", distance);

    return 0;
}


�9
#include <stdio.h>

int main() {
    double num1, num2, num3;
    double middle;

    // ������ ��� ������ �����
    printf("������� ��� ������ �����: ");
    scanf("%lf %lf %lf", &num1, &num2, &num3);

    // ���������, ����� �� ����� �������� �������
    if ((num1 > num2 && num1 < num3) || (num1 < num2 && num1 > num3)) {
        middle = num1;
    } else if ((num2 > num1 && num2 < num3) || (num2 < num1 && num2 > num3)) {
        middle = num2;
    } else {
        middle = num3;
    }

    // ������� ������� �����
    printf("������� �����: %.2lf\n", middle);

    return 0;
}


�10
#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;
    double discriminant, root1, root2;

    // ������ ������������ a, b � c
    printf("������� ������������ a, b � c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    // ��������� ������������
    discriminant = b * b - 4 * a * c;

    // ��������� �������� �������������
    if (discriminant > 0) {
        // ��� �������������� �����
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("��������� ����� ��� �������������� �����:\n");
        printf("������ 1: %.2lf\n", root1);
        printf("������ 2: %.2lf\n", root2);
    } else if (discriminant == 0) {
        // ���� �������������� ������
        root1 = -b / (2 * a);
        printf("��������� ����� ���� �������������� ������:\n");
        printf("������: %.2lf\n", root1);
    } else {
        // ��� �������������� ������
        printf("��������� �� ����� �������������� ������ (����� �����������).\n");
    }

    return 0;
}


�11
#include <stdio.h>

int main() {
    int num1, num2, num3;

    // ������ ��� ����� �����
    printf("������� ��� ����� �����: ");
    scanf("%d %d %d", &num1, &num2, &num3);

    // ���������, ����� �� ����� ����������
    if (num1 >= num2 && num1 >= num3) {
        printf("���������� �����: %d\n", num1);
    } else if (num2 >= num1 && num2 >= num3) {
        printf("���������� �����: %d\n", num2);
    } else {
        printf("���������� �����: %d\n", num3);
    }

    return 0;
}


�12
#include <stdio.h>

int main() {
    double a, b, c;

    // ������ ����� ���� ��������
    printf("������� ����� ���� ��������: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    // ��������� ������� ������������� ������������
    if (a + b > c && a + c > b && b + c > a) {
        if (a == b && b == c) {
            printf("����������� ��������������.\n");
        } else if (a == b || a == c || b == c) {
            printf("����������� ��������������.\n");
        } else {
            printf("����������� ��������������.\n");
        }
    } else {
        printf("����������� � ������ ������� ������ �� ����������.\n");
    }

    return 0;
}


�13
#include <stdio.h>

int main() {
    double x, y;

    // ������ ���������� �����
    printf("������� ���������� ����� (x, y): ");
    scanf("%lf %lf", &x, &y);

    if (x > 0 && y > 0) {
        printf("����� ��������� � ������ ��������.\n");
    } else if (x < 0 && y > 0) {
        printf("����� ��������� �� ������ ��������.\n");
    } else if (x < 0 && y < 0) {
        printf("����� ��������� � ������� ��������.\n");
    } else if (x > 0 && y < 0) {
        printf("����� ��������� � �������� ��������.\n");
    } else if (x == 0 && y != 0) {
        printf("����� ��������� �� ��� y.\n");
    } else if (x != 0 && y == 0) {
        printf("����� ��������� �� ��� x.\n");
    } else {
        printf("����� ��������� � ������ ���������.\n");
    }

    return 0;
}


�14
#include <stdio.h>

int main() {
    int n;
    long long double_factorial = 1;  // ���������� long long ��� �������� ������� ��������

    // ������ ����� n
    printf("������� ����� ����� n: ");
    scanf("%d", &n);

    // ���������, ��� n >= 2, ��� ��� ������� ��������� ��������� ������ ��� n >= 2
    if (n >= 2) {
        // ������������ ������� ���������
        while (n >= 2) {
            double_factorial *= n;
            n -= 2;  // ��������� n �� 2
        }

        printf("������� ���������: %lld\n", double_factorial);
    } else if (n == 0) {
        // ������� ��������� ��� n = 0 ����� 1
        printf("������� ���������: 1\n");
    } else {
        printf("������� ��������� �� ��������� ��� ������������� �����.\n");
    }

    return 0;
}


�15
#include <stdio.h>

int main() {
    int n;
    long long double_factorial = 1;  // ���������� long long ��� �������� ������� ��������

    // ������ ����� n
    printf("������� ����� ����� n: ");
    scanf("%d", &n);

    // ���������, ��� n >= 2, ��� ��� ������� ��������� ��������� ������ ��� n >= 2
    if (n >= 2) {
        // ������������ ������� ���������
        for (; n >= 2; n -= 2) {
            double_factorial *= n;
        }

        printf("������� ���������: %lld\n", double_factorial);
    } else if (n == 0) {
        // ������� ��������� ��� n = 0 ����� 1
        printf("������� ���������: 1\n");
    } else {
        printf("������� ��������� �� ��������� ��� ������������� �����.\n");
    }

    return 0;
}


�16
#include <stdio.h>

int main() {
    int a, b, c, sum;
    scanf("%d %d", &a, &b);

    if (b > a){
        c = a;
        a = b;
        b = c;
    }else if( a == b){
        printf("������: �������� ����� � ������ ������� ���������");
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


�17
#include <stdio.h>

int main() {
    int number, summa;
    printf("������� ������ ����� ������������������ \n");
    scanf("%d", &number);
    while(number != -9999){
        summa += number;
        printf("%d \n", number);
        printf("������� ��������� ����� ������������������ \n");
        scanf("%d", &number);
    }
    summa += -9999;
    printf("����� ����� ������������������: %d", summa);
}

�18

#include <stdio.h>

int main() {
    int min, max, number;
    printf("������� ������ ����� ������������������ \n");
    scanf("%d", &number);
    min = number;
    max = number;
    while(number != 0){
        if(number > max){
            max = number;
            printf("������� ��������� ����� ������������������ \n");
            scanf("%d", &number);
        } else if(number < min){
            min = number;
            printf("������� ��������� ����� ������������������ \n");
            scanf("%d", &number);
        } else{
        printf("������� ��������� ����� ������������������ \n");
        scanf("%d", &number);
        }
    }
    printf("����������� ����� � ������������������: %d \n", min);
    printf("������������ ����� � ������������������: %d \n", max);
}


�19
#include <stdio.h>
#include <math.h>

int main() {
    int N;

    // ������ ����� N
    printf("������� ����� N: ");
    scanf("%d", &N);

    printf("������ �������� ����������� �����, �� ������������� %d:\n", N);

    int i = 1;
    while (i * i <= N) {
        printf("%d\n", i * i);
        i++;
    }

    return 0;
}


�20
#include <stdio.h>

int main() {
    int N;

    // ������ ����� N
    printf("������� ����� N: ");
    scanf("%d", &N);

    int power_of_22 = 1; // �������� � 22^0 = 1

    while (power_of_22 < N) {
        power_of_22 *= 22; // �������� �� 22
    }

    if (power_of_22 == N) {
        printf("%d �������� �������� ����� 22.\n", N);
    } else {
        printf("%d �� �������� �������� ����� 22.\n", N);
    }

    return 0;
}


�21
#include <stdio.h>

void printDigitsInReverse(int N) {
    if (N > 0) {
        // ��������� ��������� ����� � ������� �
        int lastDigit = N % 10;
        printf("%d", lastDigit);

        // ���������� �������� ������� ��� ���������� ����� ����� ��� ��������� �����
        printDigitsInReverse(N / 10);
    }
}

int main() {
    int N;

    // ������ ����������� ����� N
    printf("������� ����������� ����� N: ");
    scanf("%d", &N);

    if (N < 0) {
        printf("����� �� �������� �����������.\n");
    } else {
        printf("����� ����� %d � �������� �������: ", N);
        printDigitsInReverse(N);
        printf("\n");
    }

    return 0;
}


�22
#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int num1, num2;

    // ������ ��� ������������� ����� �����
    printf("������� ��� ������������� ����� �����: ");
    scanf("%d %d", &num1, &num2);

    if (num1 <= 0 || num2 <= 0) {
        printf("����� ������ ���� �������������� ������.\n");
    } else {
        int result = gcd(num1, num2);
        printf("���������� ����� ��������: %d\n", result);
    }

    return 0;
}


�23
#include <stdio.h>

int main() {
    char *grades[] = {"�����", "�������������������", "�����������������", "������", "�������"};
    int grade;

    // ������ ������ �� 1 �� 5
    printf("������� ������ �� 1 �� 5: ");
    scanf("%d", &grade);

    if (grade >= 1 && grade <= 5) {
        printf("��������� �������� ������: %s\n", grades[grade - 1]);
    } else {
        printf("������������ ������. ������� ������ �� 1 �� 5.\n");
    }

    return 0;
}
