#1
#include <stdio.h>

int main() {
    int a = 5;
    int b = 10;
    int temp;

    printf("Исходные значения: a = %d, b = %d\n", a, b);

    // Используем временную переменную для обмена значениями
    temp = a;
    a = b;
    b = temp;

    printf("После обмена: a = %d, b = %d\n", a, b);

    return 0;
}

#2
#include <stdio.h>
#include <math.h>

int main() {
    double a, b, hypotenuse;

    // Вводим значения катетов
    printf("Введите длину первого катета (a): ");
    scanf("%lf", &a);

    printf("Введите длину второго катета (b): ");
    scanf("%lf", &b);

    // Находим гипотенузу
    hypotenuse = sqrt(a * a + b * b);

    // Выводим результат
    printf("Гипотенуза треугольника с катетами a = %lf и b = %lf равна %lf\n", a, b, hypotenuse);

    return 0;
}


№3
#include <stdio.h>

int main() {
    int number;

    // Вводим натуральное число
    printf("Введите натуральное число: ");
    scanf("%d", &number);

    // Вычисляем последнюю цифру
    int lastDigit = number % 10;

    // Выводим последнюю цифру
    printf("Последняя цифра введенного числа: %d\n", lastDigit);

    return 0;
}


№4
#include <stdio.h>

int main() {
    int number;

    // Вводим неотрицательное целое число
    printf("Введите неотрицательное целое число: ");
    scanf("%d", &number);

    // Находим число десятков
    int tens = (number / 10) % 10;

    // Выводим число десятков
    printf("Число десятков: %d\n", tens);

    return 0;
}


№5
#include <stdio.h>

int main() {
    int twoDigitNumber;

    // Вводим двузначное число
    printf("Введите двузначное число: ");
    scanf("%d", &twoDigitNumber);

    // Проверяем, что введенное число является двузначным
    if (twoDigitNumber >= 10 && twoDigitNumber <= 99) {
        // Находим число десятков
        int tens = twoDigitNumber / 10;

        // Выводим число десятков
        printf("Число десятков: %d\n", tens);
    } else {
        printf("Ошибка: Введите двузначное число.\n");
    }

    return 0;
}


№6
#include <stdio.h>

int main() {
    int a, b;
    double average;

    // Вводим две целочисленные переменные
    printf("Введите два целых числа: ");
    scanf("%d %d", &a, &b);

    // Находим среднее арифметическое
    average = (double)(a + b) / 2.0;

    // Выводим среднее арифметическое
    printf("Среднее арифметическое чисел %d и %d: %.2lf\n", a, b, average);

    return 0;
}


№7
#include <stdio.h>
#include <math.h>

int main() {
    int a, b;
    double geometric_mean;

    // Вводим две целочисленные переменные
    printf("Введите два целых числа: ");
    scanf("%d %d", &a, &b);

    // Находим среднее геометрическое
    geometric_mean = sqrt((double)a * b);

    // Выводим среднее геометрическое
    printf("Среднее геометрическое чисел %d и %d: %.2lf\n", a, b, geometric_mean);

    return 0;
}


№8
#include <stdio.h>
#include <math.h>

int main() {
    double x1, y1, x2, y2;
    double distance;

    // Вводим координаты первой точки
    printf("Введите координаты первой точки (x1 y1): ");
    scanf("%lf %lf", &x1, &y1);

    // Вводим координаты второй точки
    printf("Введите координаты второй точки (x2 y2): ");
    scanf("%lf %lf", &x2, &y2);

    // Находим расстояние между точками
    distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

    // Выводим расстояние
    printf("Расстояние между точками: %.2lf\n", distance);

    return 0;
}


№9
#include <stdio.h>

int main() {
    double num1, num2, num3;
    double middle;

    // Вводим три разных числа
    printf("Введите три разных числа: ");
    scanf("%lf %lf %lf", &num1, &num2, &num3);

    // Проверяем, какое из чисел является средним
    if ((num1 > num2 && num1 < num3) || (num1 < num2 && num1 > num3)) {
        middle = num1;
    } else if ((num2 > num1 && num2 < num3) || (num2 < num1 && num2 > num3)) {
        middle = num2;
    } else {
        middle = num3;
    }

    // Выводим среднее число
    printf("Среднее число: %.2lf\n", middle);

    return 0;
}


№10
#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;
    double discriminant, root1, root2;

    // Вводим коэффициенты a, b и c
    printf("Введите коэффициенты a, b и c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    // Вычисляем дискриминант
    discriminant = b * b - 4 * a * c;

    // Проверяем значение дискриминанта
    if (discriminant > 0) {
        // Два действительных корня
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("Уравнение имеет два действительных корня:\n");
        printf("Корень 1: %.2lf\n", root1);
        printf("Корень 2: %.2lf\n", root2);
    } else if (discriminant == 0) {
        // Один действительный корень
        root1 = -b / (2 * a);
        printf("Уравнение имеет один действительный корень:\n");
        printf("Корень: %.2lf\n", root1);
    } else {
        // Нет действительных корней
        printf("Уравнение не имеет действительных корней (корни комплексные).\n");
    }

    return 0;
}


№11
#include <stdio.h>

int main() {
    int num1, num2, num3;

    // Вводим три целых числа
    printf("Введите три целых числа: ");
    scanf("%d %d %d", &num1, &num2, &num3);

    // Проверяем, какое из чисел наибольшее
    if (num1 >= num2 && num1 >= num3) {
        printf("Наибольшее число: %d\n", num1);
    } else if (num2 >= num1 && num2 >= num3) {
        printf("Наибольшее число: %d\n", num2);
    } else {
        printf("Наибольшее число: %d\n", num3);
    }

    return 0;
}


№12
#include <stdio.h>

int main() {
    double a, b, c;

    // Вводим длины трех отрезков
    printf("Введите длины трех отрезков: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    // Проверяем условия существования треугольника
    if (a + b > c && a + c > b && b + c > a) {
        if (a == b && b == c) {
            printf("Треугольник равносторонний.\n");
        } else if (a == b || a == c || b == c) {
            printf("Треугольник равнобедренный.\n");
        } else {
            printf("Треугольник разносторонний.\n");
        }
    } else {
        printf("Треугольник с такими длинами сторон не существует.\n");
    }

    return 0;
}


№13
#include <stdio.h>

int main() {
    double x, y;

    // Вводим координаты точки
    printf("Введите координаты точки (x, y): ");
    scanf("%lf %lf", &x, &y);

    if (x > 0 && y > 0) {
        printf("Точка находится в первой четверти.\n");
    } else if (x < 0 && y > 0) {
        printf("Точка находится во второй четверти.\n");
    } else if (x < 0 && y < 0) {
        printf("Точка находится в третьей четверти.\n");
    } else if (x > 0 && y < 0) {
        printf("Точка находится в четвёртой четверти.\n");
    } else if (x == 0 && y != 0) {
        printf("Точка находится на оси y.\n");
    } else if (x != 0 && y == 0) {
        printf("Точка находится на оси x.\n");
    } else {
        printf("Точка находится в начале координат.\n");
    }

    return 0;
}


№14
#include <stdio.h>

int main() {
    int n;
    long long double_factorial = 1;  // Используем long long для хранения больших значений

    // Вводим число n
    printf("Введите целое число n: ");
    scanf("%d", &n);

    // Проверяем, что n >= 2, так как двойной факториал определен только для n >= 2
    if (n >= 2) {
        // Рассчитываем двойной факториал
        while (n >= 2) {
            double_factorial *= n;
            n -= 2;  // Уменьшаем n на 2
        }

        printf("Двойной факториал: %lld\n", double_factorial);
    } else if (n == 0) {
        // Двойной факториал для n = 0 равен 1
        printf("Двойной факториал: 1\n");
    } else {
        printf("Двойной факториал не определен для отрицательных чисел.\n");
    }

    return 0;
}


№15
#include <stdio.h>

int main() {
    int n;
    long long double_factorial = 1;  // Используем long long для хранения больших значений

    // Вводим число n
    printf("Введите целое число n: ");
    scanf("%d", &n);

    // Проверяем, что n >= 2, так как двойной факториал определен только для n >= 2
    if (n >= 2) {
        // Рассчитываем двойной факториал
        for (; n >= 2; n -= 2) {
            double_factorial *= n;
        }

        printf("Двойной факториал: %lld\n", double_factorial);
    } else if (n == 0) {
        // Двойной факториал для n = 0 равен 1
        printf("Двойной факториал: 1\n");
    } else {
        printf("Двойной факториал не определен для отрицательных чисел.\n");
    }

    return 0;
}


№16
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


№17
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

№18

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


№19
#include <stdio.h>
#include <math.h>

int main() {
    int N;

    // Вводим число N
    printf("Введите число N: ");
    scanf("%d", &N);

    printf("Точные квадраты натуральных чисел, не превосходящие %d:\n", N);

    int i = 1;
    while (i * i <= N) {
        printf("%d\n", i * i);
        i++;
    }

    return 0;
}


№20
#include <stdio.h>

int main() {
    int N;

    // Вводим число N
    printf("Введите число N: ");
    scanf("%d", &N);

    int power_of_22 = 1; // Начинаем с 22^0 = 1

    while (power_of_22 < N) {
        power_of_22 *= 22; // Умножаем на 22
    }

    if (power_of_22 == N) {
        printf("%d является степенью числа 22.\n", N);
    } else {
        printf("%d не является степенью числа 22.\n", N);
    }

    return 0;
}


№21
#include <stdio.h>

void printDigitsInReverse(int N) {
    if (N > 0) {
        // Извлекаем последнюю цифру и выводим её
        int lastDigit = N % 10;
        printf("%d", lastDigit);

        // Рекурсивно вызываем функцию для оставшейся части числа без последней цифры
        printDigitsInReverse(N / 10);
    }
}

int main() {
    int N;

    // Вводим натуральное число N
    printf("Введите натуральное число N: ");
    scanf("%d", &N);

    if (N < 0) {
        printf("Число не является натуральным.\n");
    } else {
        printf("Цифры числа %d в обратном порядке: ", N);
        printDigitsInReverse(N);
        printf("\n");
    }

    return 0;
}


№22
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

    // Вводим два положительных целых числа
    printf("Введите два положительных целых числа: ");
    scanf("%d %d", &num1, &num2);

    if (num1 <= 0 || num2 <= 0) {
        printf("Числа должны быть положительными целыми.\n");
    } else {
        int result = gcd(num1, num2);
        printf("Наибольший общий делитель: %d\n", result);
    }

    return 0;
}


№23
#include <stdio.h>

int main() {
    char *grades[] = {"плохо", "неудовлетворительно", "удовлетворительно", "хорошо", "отлично"};
    int grade;

    // Вводим оценку от 1 до 5
    printf("Введите оценку от 1 до 5: ");
    scanf("%d", &grade);

    if (grade >= 1 && grade <= 5) {
        printf("Словесное описание оценки: %s\n", grades[grade - 1]);
    } else {
        printf("Некорректная оценка. Введите оценку от 1 до 5.\n");
    }

    return 0;
}
