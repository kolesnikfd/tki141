#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * @brief считает количество отрицательных чисел среди переменных
 * @param a первое число
 * @param b второе число
 * @param c третье число
 * @return значение количества отрицательных чисел
 */
double countNegative (const double a, const double b, const double c);

/**
 * @brief считает абсолютную сумму значений переменных
 * @param a первое число
 * @param b второе число
 * @param c третье число
 * @return значение абсолютной суммы
 */
double getAbsSum (const double a, const double b, const double c);

/**
 * @brief сичтывает значение, введенное с клавиатуры с проверкой ввода
 * @return считанное значение
 */
double getValue();

/**
@brief CountNegatives - количество отрицательных
@brief AbsoluteSum - абсолютная сумма
*/
enum {CountNegatives, AbsoluteSum};

/**
 * @brief точка входа в программу
 * @return 0, если программа выполнена корректно 
 */
int main(void)
{
    double a = getValue();
    double b = getValue();
    double c = getValue();

    printf("select the required calculation: %d - count of negative, %d - absolute sum\n", CountNegatives, AbsoluteSum);
    int choice = (int) getValue();
    switch (choice) 
    {
    case CountNegatives:
        printf("Negatives = %.0f\n", countNegative(a, b, c));
        break;
    case AbsoluteSum: 
        printf("Absolute sum = %f", getAbsSum(a, b, c));
        break;
    default:
        printf("wrong choice");
        abort();
    }

    return 0;
}

double countNegative (const double a, const double b, const double c)
{
    double count = 0;
    if (a < 0)
    {
        count=count+1;
    }
    if (b < 0)
    {
        count=count+1;
    }
    if (c < 0)
    {
        count=count+1;
    }
    return count;
}

double getAbsSum (const double a, const double b, const double c)
{
    return fabs(a)+fabs(b)+fabs(c);
}

double getValue()
{
    double value=0;
    if (!scanf("%lf", &value))
    {
        printf("Error\n");
        abort();
    }
    return value;
}
