#include <stdio.h>
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
void checkStep(const double step);

/**
 * @brief рассчитывает значение функции y по заданной формуле
 * @param x значение 
 * @return значение y
 */
double getY(const double x);

/**
 * @brief рассчитывает сумму членов последовательности с точностью eps
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
	checkStep(step);
	const double eps = pow(20, -4);
	for (double x = start; end - x + step> DBL_EPSILON; x = x + step)
	{
		printf("x = %lf, y = %.10lf, Sum of numbers of the sequence with precision %.8lf = %.8lf\n", x, getY(x), eps, getSumE(eps,x));
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

void checkStep(const double step)
{
	if (step <= DBL_EPSILON)
	{
		printf("Error, step must be positive\n");
		exit(1);
	}
}

double getY(const double x)
{
	return ( (exp(x) - exp(-x)) / 2.0 );
}

double getSumE(const double eps, const double x)
{
    double current = x;
    double result = 0.0;
    double fact_part = 1;
    double k = 0;
    while ( fabs(current) > eps )
    {
        result = result + current;
        k++;
        fact_part = fact_part * 2 * k * ( 2 * k + 1);
        current = (pow(x, 2 * k + 1)) / fact_part;
    }
    return result;
}



