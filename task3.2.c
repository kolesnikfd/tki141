#include <stdio.h>
#include <math.h>

/**
 * @brief считывает целое значение с клавиатуры в проверкой ввода
 * @return возвращает считанное значение
 */
int getValue();

/**
 * @brief считывает вещественное значение с клавиатуры в проверкой ввода
 * @return возвращает считанное значение
 */
double getDouble();

/**
 * @brief рассчитывает сумму n членов последовательности
 * @param n - заданное число членов
 * @return рассчитанное значение
 */
double getSumN(const int n);

/**
 * @brief рассчитывает сумму членов последовательности,
 * с точностью e
 * @param e - заданная точность
 * @return рассчитанное значение
 */
double getSumE(const double e);

/** 
 * @brief проверяет, что число положительное
 * @param value - проверяемое значение
 */
void checkPositive(const double value);

/**
 * @brief ищет количество делителей числа n, которые больше k
 * @param n число
 * @param k число-сравнение для делителей
 * @return количество найденных делителей
 */
int countDivK(int n, const int k);

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно, иначе 1
 */
int main()
{
    printf("Enter n: ");
    int n = getValue();
    checkPositive(n);
    printf("Sum of %d in the sequence = %.20lf\n", n, getSumN(n));

    printf("Enter e: ");
    double e = getDouble();
    checkPositive(e);
    printf("Sum of numbers of the sequence with precision %lf = %.20lf\n", e, getSumE(e));

    printf("Enter x:");
    int x = getValue();
    checkPositive(x);
    printf("Enter k:");
    int k = getValue();
    checkPositive(k);
    printf("The number of divisors of the number %d that are greater than %d = %d", x, k, countDivK(x,k));
    return 0;
}

int getValue()
{
    int value = 0;
    if (!scanf("%d", &value))
    {
        printf("Error\n");
        exit(1);
    }
    return value;
}

double getDouble()
{
    double value = 0;
    if (!scanf("%lf", &value))
    {
        printf("Error\n");
        exit(1);
    }
    return value;
}

void checkPositive(const double value)
{
    if (!value > __DBL_EPSILON__)
    {
        printf("Error\n");
        exit(1);
    }
}

int countDivK(int n, const int k)
{
    int count = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (i > k)
            {
                count++;
            }
            if (i != n / i && n / i > k)
            {
                count++;
            }
        }
    }
    return count;
}

double getSumE(const double e)
{
    double current = 1;
    double result = 0.0;
    double fact_part = 1;
    double k = 0;
    while ( fabs(current) > e )
    {
        result = result + current;
        k++;
        fact_part = fact_part * k;
        current = (pow(-1, k) * (1 + k)) / fact_part;
    }
    return result;
}

double getSumN(const int n)
{
    double current = 1;
    double result = 1.0;
    double fact_part = 1;
    for (int k = 1; k < n; k++)
    {
        fact_part = fact_part * k;
        current = (pow(-1, k) * (1 + k)) / fact_part;
        result = result + current;
    }
    return result;
}

