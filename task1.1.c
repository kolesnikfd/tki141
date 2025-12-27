#define _USE_MATH_DEFINES // for C
#include <math.h>
#include <stdio.h>

/**
 * @brief Рассчитывает функцию A по заданной формуле
 * @param x - значение параметра x
 * @param y - значение параметра y
 * @param z - значение параметра z
 * @return рассчитанное значение
 */
double getA(const double x, const double y, const double z);

/**
 * @brief Рассчитывает функцию B по заданной формуле
 * @param x - значение параметра x
 * @param y - значение параметра y
 * @param z - значение параметра z
 * @return рассчитанное значение
 */
double getB(const double x, const double y, const double z);

/**
 * @brief Точка входа в программу
 * @return Возвращает 0, если программа выполнена корректно
 */
int main()
{
    const double x = 0.3;
    const double y = 3.1;
    const double z = 0.5;
    printf("A = %lf \n", getA(x, y, z));
    printf("B = %lf", getB(x, y, z));
    return 0;
}

double getA(const double x, const double y, const double z)
{
    return (pow(z, 2) * x + exp(-x) * cos(y * x)) / (y * x - exp(-x) * sin(y * x) + 1);
}

double getB(const double x, const double y, const double z)
{
    return exp(2.0 * x) * log(z + x) - pow(y, 3 * x) * log(y - x);

}

