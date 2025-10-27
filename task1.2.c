#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/**
 * @brief Рассчитывает значение пути по скорости судна, скорости течения и времени
 * @param speedShip - значение скорости судна
 * @param speedFlow - значение скорости течения
 * @param Time - значение времени
 * @return рассчитанное значение Пути
 */
double getPath(const double speedShip, const double speedFlow, const double Time);

/**
 * @brief сичтывает значение, введенное с клавиатуры с проверкой ввода
 * @return считанное значение
 */
double getValue();

/**
 * @brief Точка входа в программу
 * @return Возвращает 0, если программа выполнена корректно
 */
int main(void)
{
    printf("Enter ship speed(km/h):\n");
    double speedShip = getValue();
    printf("Enter flow speed(km/h):\n");
    double speedFlow = getValue();
    printf("Enter time(h):\n");
    double Time = getValue();
    printf("Path = %.10f m", getPath(speedShip, speedFlow, Time));
    return 0;
}

double getPath(const double speedShip, const double speedFlow, const double Time)
{
    return ((speedShip + speedFlow)*Time);
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

