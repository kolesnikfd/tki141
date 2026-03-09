#define _USE_MATH_DEFINES // for C
#include <stdio.h>
#include <math.h>

/**
 * @brief высчитывает значение y по формуле от значения x
 * @param x значение x
 * @param a заданная константа
 * @return значение y от x
 */
double getY (const double x, const double a);

/**
 * @brief сичтывает значение, введенное с клавиатуры с проверкой ввода
 * @return считанное значение
 */
double getValue(void);

/**
 * @brief точка входа в программу
 * @return 0, если программа выполнена корректно 
 */
int main()
{
    const double a = 1.36;
    double x = getValue();
    printf("y = %.7g", getY(x,a));
    return 0;
}

double getY (const double x, const double a)
{
    if  (0.5 - x > __DBL_EPSILON__)
    {
        return (M_PI_2 + x * a - exp(a*x));
    }
    else
    {
        return (pow(x, 3) * a + 28);
    }
}

double getValue(void)
{
    double value = 0;
    if (!scanf("%lg", &value))
    {
        printf("Error\n");
        exit(0);
    }
    return value;
}

