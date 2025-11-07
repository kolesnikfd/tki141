#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <stdbool.h>
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
void checkStep(const double step);

/**
 * @brief рассчитывает значение функции y по заданной формуле
 * @param x значение 
 * @return значение y
 */
double getY(const double x);

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
	checkStep(step);
	for (double x = start; end - x > DBL_EPSILON; x = x + step)
	{
		printf("x = %.2lg, y = %.4lg\n", x, getY(x));
	}
	return 0;
}

double getValue(void)
{
	double value = 0;
	if (!scanf_s("%lf", &value))
	{
		printf("Error\n");
		exit(0);
	}
	return value;
}

void checkStep(const double step)
{
	if (step <= DBL_EPSILON)
	{
		printf("Error, step must be positive\n");
		exit(0);
	}
}

double getY(const double x)
{
	return pow(3,x);
}
