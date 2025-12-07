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
 * @brief рассчитывает коэффициент рекуррентного выражения
 * @param i текущий индекс
 * @return рассчитанное значение коэффициента
 */
double getRecurent(const int i);

/** 
 * @brief проверяет, что число положительное
 * @param value - проверяемое значение
 */
void checkPositive(const int value);

/**
 * @brief ищет количество делителей числа n, которые больше k
 * @param n число
 * @param k число-сравнение для делителей
 * @return количество найденных делителей
 */
int countDivK(const int n, const int k);

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно, иначе 1
 */
int main()
{
    printf("Enter n: ");
    int n = getValue();
    printf("Sum of first %d terms = %.40lf\n", n, getSumN(n));
    
    printf("Enter e: ");
    double e = getDouble();
    checkNonNegative(e);
    printf("Sum of terms with absolute value >= %.20lf = %.40lf\n", e, getSumE(e));
    
    printf("Enter x: ");
    int x = getValue();
    checkPositive(x);
    printf("Enter k: ");
    int k = getValue();
    checkNonNegative(k);
    printf("The number of divisors of %d that are greater than %d = %d\n", x, k, countDivK(x, k));
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

double getSumN(const int n)
{
    if (n <= 0) return 0;
    double result = 0;
    double current = 0;
    double factorial_part = 1.0;
    for (int k = 0; k < n; k++)
    {
        if (k == 0)
        {
            current = 1.0;
        }
        else
        {
            current *= (-1.0) * (1 + k) / (k * k);
        }
        result += current;
    }
    return result;
}

void checkPositive(const int value)
{
    if (value <= 0)
    {
        printf("Error: value must be positive\n");
        exit(1);
    }
}

void checkNonNegative(const double value)
{
    if (value < 0)
    {
        printf("Error: value must be non-negative\n");
        exit(1);
    }
}

double getSumE(const double e)
{
    double result = 0;
    double current = 0;
    double factorial_part = 1.0;
    int k = 0;
    current = 1.0;
    
    while (fabs(current) >= e)
    {
        result += current;
        k++;
        current *= (-1.0) * (1 + k) / (k * k);
        if (k > 1000) break;
    }
    return result;
}

int countDivK(const int n, const int k)
{
    int count = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (i > k) count++;
            if (i != n / i && n / i > k) count++;
        }
    }
    return count;
}

