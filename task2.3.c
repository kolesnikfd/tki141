#include <stdio.h>
#include <math.h>

/**
 * @brief выводит надписть с информацией о том, возможно ли разместить дома на участке
 * @param sizeA длина участка
 * @param sizeB ширина участка
 * @param size11 длина первого дома
 * @param size12 ширина первого дома
 * @param size21 длина второго дома
 * @param size22 ширина второго дома 
 */
void getAccess (const double sizeA, const double sizeB, const double size11, const double size12, const double size21, const double size22);

/**
 * @brief проверяет,что переменная положительная
 * @param value значение проверяемой переменной
 */
void checkValue(const double value);

/**
 * @brief считывает значение, введенное с клавиатуры с проверкой ввода
 * @return считанное значение
 */
double getValue();

/**
 * @brief проверяет, что дом помещается на участок
 * @param size1 длина дома
 * @param size2 ширина дома
 * @param sizeA длина участка
 * @param sizeB ширина участка
 */
void checkSize(const double size1, const double size2, const double sizeA, const double sizeB);

/**
 * @brief точка входа в программу
 * @return 0, если программа выполнена корректно 
 */
int main(void)
{
    printf("enter lenth of plot: ");
    double a = getValue();
    checkValue(a);
    printf("enter width of plot: ");
    double b = getValue();
    checkValue(b);
    printf("enter lenth of house 1: ");
    double r = getValue();
    printf("enter width of house 1: ");
    double s = getValue();
    checkSize(r, s, a, b);
    printf("enter lenth of house 2: ");
    double p = getValue();
    printf("enter width of house 2: ");
    double q = getValue();
    checkSize(p, q, a, b);
    getAccess(a, b, r, s, p, q);
    return 0;
}

void getAccess (const double sizeA, const double sizeB, const double size11, const double size12, const double size21, const double size22)
{
    if ( (size11+size21 <= sizeA) && (size12 <= sizeB) && (size22 <=sizeB) )
    {
        printf("Yes, you can");
    }
    else if ( (size11+size22 <= sizeA) && (size12 <= sizeB) && (size21 <=sizeB) )
    {
        printf("Yes, you can");
    }
    else if ( (size12+size21 <= sizeA) && (size11 <= sizeB) && (size22 <=sizeB) )
    {
        printf("Yes, you can");
    }
    else if ( (size12+size22 <= sizeA) && (size11 <= sizeB) && (size21 <=sizeB) )
    {
        printf("Yes, you can");
    }
    else
    {
        printf("No, you can't");
    }
}

void checkValue(const double value)
{
    if (value <= 0 )
    {
        printf("Value have to be positive\n");
        abort();
    }
}

double getValue()
{
    double value = 0;
    if (!scanf("%lf",&value))
    {
        printf("Error\n");
        abort();
    }
    return value;
}

void checkSize(const double size1, const double size2, const double sizeA, const double sizeB)
{
    if (!(((size1 < sizeA) && (size2 < sizeB)) || ((size2 < sizeA) && (size1 < sizeB))))
    {
        printf("This house doesn't fit on this plot \n");
        abort();
    }
}