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
 * @brief Точка входа в программу
 * @return Возвращает 0, если программа выполнена корректно
 */
int main(void)
{
    double speedShip;
    double speedFlow;
    double Time;
    printf("Print ship speed(km/h) flow speed(km/h) and time(h) separated by space\n");
    scanf("%lf %lf %lf", &speedShip, &speedFlow, &Time);
    printf("Path = %.10f m", getPath(speedShip, speedFlow, Time));
    return 0;
}

double getPath(const double speedShip, const double speedFlow, const double Time)
{
    return ((speedShip + speedFlow)*Time);
}
