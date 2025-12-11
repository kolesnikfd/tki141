#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

/**
 * @brief считывает значение, введенное с клавиатуры с проверкой ввода
 * @return считанное значение
 */
double getValue(void);

/**
 * @brief проверяет,что переменная положительная
 * @param step значение проверяемой переменной
 */
void checkPositive(const double step);

/**
 * @brief рассчитывает значение функции y по заданной формуле
 * @param x значение 
 * @return значение y
 */
double getY(const double x);

/**
 * @brief рассчитывает коэффициент рекуррентного выражения
 * @param n текущий индекс
 * @param x текущее значение x
 * @return рассчитанное значение коэффициента
 */
double getRecurent(const int n, const double x);

/**
 * @brief рассчитывает сумму членов последовательности с точностью eps
 * @param параметр x
 * @param eps - заданная точность
 * @return рассчитанное значение
 */
double getSumE(const double eps, const double x);

/**
 * @brief точка входа в программу
 * @return 0, если программа выполнена корректно
 */
int main()
{
	printf("Enter starting value: ");
	double start = getValue();
	printf("Enter final value: ");
	double end = getValue();
	printf("Enter step: ");
	double step = getValue();
	checkPositive(step);
    printf("Enter eps: ");
	double eps = getValue();
	checkPositive(eps);
	for (double x = start; end - x > DBL_EPSILON; x = x + step)
	{
		printf("x = %.10lf, y = %.10lf, Sum of numbers of the sequence with precision %.10lf = %.10lf\n", x, getY(x), eps, getSumE(eps,x));
	}
	return 0;
}

double getValue(void)
{
	double value = 0;
	if (!scanf_s("%lf", &value))
	{
		printf("Error\n");
		exit(1);
	}
	return value;
}

void checkPositive(const double step)
{
	if (step <= DBL_EPSILON)
	{
		printf("Error, must be positive\n");
		exit(1);
	}
}

double getY(const double x)
{
	return ( (exp(x)-exp(-x))/2 );
}

double getRecurent(const int n, const double x)
{
    return ( pow(x, 2) / (4 * pow(n, 2) + 2 * n) );
}

double getSumE(const double eps, const double x)
{
    double current = x;
    double result = 0;
    for (int n = 1; fabs(getY(x) - result) > eps; n++)
    {
        result += current;
        current *= getRecurent(n, x);
    }
    return result;
}




