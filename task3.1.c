#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <stdbool.h>
#include <math.h>

/**
 * @brief считывает значение, введенное с клавиатуры с проверкой ввода
 * @return считанное значение
 */
double getValue();

/**
 * @brief проверяет,что переменная положительная
 * @param step значение проверяемой переменной
 */
void checkStep(const double step);

/**
 * @brief проверяет, принадлежит ли значение аргумента функции её области определения
 * @param x - аргумент функции
 * @return true, если аргумент принадлежит ООФ, иначе false
 */
bool defineOOF(const double x);

/**
 * @brief рассчитывает значение функции y по заданной формуле
 * @param x значение 
 * @return значение y
 */
double getY(const double x);

/**
 * @brief считает сумму чисел кратных 3 от 3 до 99
 * @return сумму этих чисел
 */
int getSum3();

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
	for (double x = start; x < end; x = x + step)
	{
		if (defineOOF(x))
		{
			printf("x = %.2lf, y = %.4lf\n", x, getY(x));
		}
		else
		{
			printf("x = %.2lf doesn't belong to the domain of the function\n", x);
		}
	}
	printf("answer to the additional task = %d", getSum3());
	return 0;
}

double getValue()
{
	double value = 0;
	if (!scanf_s("%lf", &value))
	{
		printf("Error\n");
		abort();
	}
	return value;
}

void checkStep(const double step)
{
	if (step <= DBL_EPSILON)
	{
		printf("Error, step must be positive\n");
		abort();
	}
}

bool defineOOF(const double x)
{
	return x <= 1;
}

double getY(const double x)
{
	return sqrt(1-x)-tan(x);
}

int getSum3()
{
	int sum=0;
	for (int i=3; i<=99; i=i+3 )
	{
		sum=sum+i;
	}
	return sum;
}

