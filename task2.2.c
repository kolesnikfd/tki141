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
double getValue();

/**
 * @brief точка входа в программу
 * @return 0, если программа выполнена корректно 
 */
int main(void)
{
    double a;
    double x;
    a=1.36;
    x=getValue();
    printf("y = %.7f", getY(x,a));
    return 0;
}

double getY (const double x, const double a)
{
    if  (x<0.5)
    {
        return (M_PI_2 + x*a - exp(a*x));
    }
    else
    {
        return (pow(x, 3)*a + 28);
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