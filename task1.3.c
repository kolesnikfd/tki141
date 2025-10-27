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
 * @brief сичтывает значение, введенное с клавиатуры с проверкой ввода
 * @return считанное значение
 */
double getValue();

/**
 * @brief точка входа в программу
 * @return возвращает 0, если программа выполнена корректно
 */
int main(void)
{
    printf("Enter m(kg):\n");
    double m = getValue();
    printf("Enter t0(sec):\n");
    double t0 = getValue();
    printf("Enter t(sec):\n");
    double t = getValue();
    printf("Q = %.10f J", getHeat(m, t0, t));
    return 0;
}

double getHeat(const double m, const double t0, const double t)
{
    return (500*m*(t-t0));
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
