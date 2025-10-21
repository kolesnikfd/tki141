#include <stdio.h>
/**
 * @brief Рассчитывает количество теплоты, необходиоме для нагрева стали массой m c температуры t0  до температуры t
 * @param m - значение массы
 * @param t0 - значение начальной температуры
 * @param t - значение конечной иемпературы
 * @return рассчитание знасчение количества теплоты
 */
double getHeat(const double m, const double t0, const double t);

/**
 * @brief точка входа в программу
 * @return возвращает 0, если программа выполнена корректно
 */
int main(void)
{
    double m;
    double t0;
    double t;
    printf("Print m(kg), t0 and t separated by space\n");
    scanf("%lf %lf %lf", &m, &t0, &t);
    printf("Q = %.10f J", getHeat(m, t0, t));
    return 0;
}

double getHeat(const double m, const double t0, const double t)
{
    return (500*m*(t-t0));
}