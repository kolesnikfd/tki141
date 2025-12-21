#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define scanf_s scanf

/**
 * @brief Выделztn память для массива целых чисел
 * @param size Размер массива
 * @return Указатель на выделенную память
 */
int* createArray(const size_t size);

/**
 * @brief Получение целочисленного значения от пользователя
 * @return Введенное значение
 */
int Value();

/**
 * @brief Получение размера массива
 * @param message сообщение пользователю
 * @return Размер массива
 */
size_t getSize(const char* message);

/**
 * @brief Заполнение массива с клавиатуры
 * @param arr Указатель на массив
 * @param size Размер массива
 */
void fillArray(int* arr,const size_t size);

/**
 * @brief Заполнение массива случайными числами в диапазоне [-100;100]
 * @param arr Указатель на массив
 * @param size Размер массива
 */
void fillRandom(int* arr,const size_t size);

/**
 * @brief Вывод массива на экран
 * @param arr Указатель на массив
 * @param size Размер массива
 */
void printArray(const int* arr,const size_t size);

/**
 * @brief Найти сумму элементов, значения которых состоят из одной цифры
 * @param arr Указатель на массив
 * @param size Размер массива
 * @return Сумма одноразрядных элементов
 */
int sumSingleDigit(const int* arr, const size_t size);

/**
 * @brief Заменить элементы массива между минимальным и максимальным на те же элементы в обратном порядке
 * @param arr Указатель на массив
 * @param size Размер массива
 */
void reverseBetweenMinMax(int* arr, const size_t size);

/**
 * @brief Найти номер последней пары соседних элементов с одинаковыми знаками, произведение которых меньше заданного числа
 * @param arr Указатель на массив
 * @param size Размер массива
 * @param number Заданное число для сравнения
 * @return Номер первого элемента пары или -1 если пара не найдена
 */
int findLastPair(const int* arr, const size_t size, const int number);

/**
 * @brief RANDOM - Заполнение рандомными элементами
 * @brief MANUAL - Заполнение вручную
 */
enum {RANDOM = 1, MANUAL};

/**
 * @brief Точка входа в программу
 * @return Возвращает 0, если программа выполнена корректно, иначе 1
 */
int main()
{
    size_t size = getSize("Enter array size: ");
    int* arr = createArray(size);
    
    printf("Choose array filling method:\n" "%d - random numbers, %d - manually: ", RANDOM, MANUAL);
    int choice = Value();
    switch(choice)
    {
        case RANDOM:
            fillRandom(arr, size);
            break;
        case MANUAL:
            fillArray(arr, size);
            break;
        default:
            printf("Choice error!\n");
            free(arr);
            exit(1);
    }

    printf("Original array: ");
    printArray(arr, size);
    
    int sum = sumSingleDigit(arr, size);
    printf("\n1. Sum of single-digit elements: %d\n", sum);
    
    int* arrCopy = createArray(size);
    for (size_t i = 0; i < size; i++)
    {
        arrCopy[i] = arr[i];
    }
    reverseBetweenMinMax(arr, size);
    printf("2. Array after reversing elements between min and max: ");
    printArray(arr, size);
    
    printf("3. Enter number to compare pair product with: ");
    int number = Value();
    int pairIndex = findLastPair(arrCopy, size, number);
    if (pairIndex != -1)
    {
        printf("Last pair of adjacent elements with same signs, whose product is less than %d: elements [%d] and [%d]\n", number, pairIndex, pairIndex + 1);
        printf("Values: %d and %d, product: %d\n", arrCopy[pairIndex], arrCopy[pairIndex + 1], arrCopy[pairIndex] * arrCopy[pairIndex + 1]);
    }
    else
    {
        printf("Pair of adjacent elements with same signs, whose product is less than %d, was not found.\n", number);
    }
    free(arr);
    free(arrCopy);
    return 0;
}

int Value()
{
    int value = 0;
    if (!scanf_s("%d", &value))
    {
        printf("Input error!\n");
        exit(1);
    }
    return value;
}

size_t getSize(const char* message)
{
    printf("%s", message);
    int value = Value();
    if (value <= 0)
    {
        printf("Error: size must be positive!\n");
        exit(1);
    }
    return value;
}

void fillArray(int* arr,const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("Enter element [%zu]: ", i);
        arr[i] = Value();
    }
}

void fillRandom(int* arr,const size_t size)
{
    srand(time(NULL));
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = (rand() % 201) - 100;
    }
}

void printArray(const int* arr,const size_t size)
{
    printf("[");
    for (size_t i = 0; i < size; i++)
    {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}

int sumSingleDigit(const int* arr, const size_t size)
{
    int sum = 0;
    printf("Single-digit elements: ");
    for (size_t i = 0; i < size; i++)
    {
        int num = arr[i];
        if (abs(num) >= 0 && abs(num) <= 9 && num != 0)
        {
            printf("%d ", num);
            sum += num;
        }
    }
    if (sum == 0)
    {
        printf("no single-digit elements");
    }
    return sum;
}

void reverseBetweenMinMax(int* arr, const size_t size)
{
    if (size < 2) return;
    size_t minIndex = 0;
    size_t maxIndex = 0;
    for (size_t i = 1; i < size; i++)
    {
        if (arr[i] < arr[minIndex])
        {
            minIndex = i;
        }
        if (arr[i] > arr[maxIndex])
        {
            maxIndex = i;
        }
    }
    size_t start = 0; 
    size_t end = 0;
    if (minIndex < maxIndex)
    {
        start = minIndex + 1;
        end = maxIndex - 1;
    }
    else
    {
        start = maxIndex + 1;
        end = minIndex - 1;
    }
    if (start > end)
    {
        printf("No elements between minimum and maximum elements.\n");
        return;
    }
    printf("Minimum element [%zu] = %d\n", minIndex, arr[minIndex]);
    printf("Maximum element [%zu] = %d\n", maxIndex, arr[maxIndex]);
    printf("Reversing elements between indices [%zu] and [%zu]\n", start, end);
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int findLastPair(const int* arr, const size_t size, const int number)
{
    if (size < 2)
    {
        return -1;
    }
    int lastFoundIndex = -1;
    for (size_t i = 0; i < size - 1; i++)
    {
        int current = arr[i];
        int next = arr[i + 1];
        int sameSign = 0;
        if (current > 0 && next > 0)
        {
            sameSign = 1;
        }
        else if (current < 0 && next < 0)
        {
            sameSign = 1;
        }
        if (sameSign)
        {
            int product = current * next;
            if (product < number)
            {
                lastFoundIndex = i;
            }
        }
    }
    return lastFoundIndex;
}

int* createArray(const size_t size)
{
    int* arr = malloc(size * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation error!\n");
        exit(1);
    }
    return arr;
}
