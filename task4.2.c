#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define scanf_s scanf

/**
 * @brief Считывает значение введенное с клавиатуры с проверкой ввода
 * @return Считанное значение
 */
int Value(void);

/**
 * @brief Получение размера массива
 * @param message сообщение пользователю
 * @return Размер массива
 */
size_t getSize(char* message);

/**
 * @brief Заполнение массива с клавиатуры
 * @param arr Указатель на массив
 * @param size Размер массива
 */
void fillArray(int* arr, const size_t size);

/**
 * @brief Вывод массива на экран
 * @param arr Указатель на массив
 * @param size Размер массива
 */
void printArray(const int* arr, const size_t size);

/**
 * @brief Проверяет корректность диапазона случайных чисел
 * @param start Начало диапазона
 * @param end Конец диапазона
 */
void checkRange(const int start, const int end);

/**
 * @brief Заполнение массива случайными числами
 * @param arr Указатель на массив
 * @param size Размер массива
 */
void fillRandom(int* arr, const size_t size);

/**
 * @brief Создаёт копию массива
 * @param arr Исходный массив
 * @param size Размер массива
 * @return Полученный массив
 */
int* copyArray(const int* arr, const size_t size);

/**
 * @brief Заменяет последний элемент массива кратный 3 нулем
 * @param copyArr Массив в котором выполняется замена
 * @param size Размер массива
 * @return 1 если замена выполнена успешно иначе 0
 */
int replaceLastMultipleOfThree(int* copyArr, const size_t size);

/**
 * @brief Вставляет число К после всех четных элементов
 * @param arr Указатель на исходный массив
 * @param size Размер массива
 * @return Указатель на новый массив и его размер через параметры
 */
int* insertKAfterEvenSimple(const int* arr, const size_t size, size_t* newSize);

/**
 * @brief Формирует новый массив М из массива Р по правилу
 * @param P Исходный массив Р
 * @param size Размер массива
 * @return Указатель на новый массив М
 */
int* createMFromP(const int* P, const size_t size);

/**
 * @brief RANDOM - заполнение массива случайными числами
 * @brief MANUAL - заполнение массива вручную
 */
enum {RANDOM = 1, MANUAL};

/**
 * @brief Точка входа в программу
 * @return 0 если программа выполнена корректно
 */
int main(void)
{
    srand(time(NULL));
    size_t size = getSize("Enter array size: ");
    int* arr = malloc(size * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation error!\n");
        exit(1);
    }
    printf("Select the method for filling the array:\n"
           "%d - random numbers\n"
           "%d - manually\n"
           "Enter the required filling number: ",
           RANDOM, MANUAL);

    int choice = Value();
    switch (choice)
    {
        case RANDOM:
            fillRandom(arr, size);
            break;
        case MANUAL:
            fillArray(arr, size);
            break;
        default:
            printf("Error! Wrong choice.\n");
            free(arr);
            exit(1);
    }
    printf("\nSource array:\n");
    printArray(arr, size);
    int* copyArr1 = copyArray(arr, size);
    printf("\n1.Replacing the last element that is a multiple of 3 with 0:\n");
    if (replaceLastMultipleOfThree(copyArr1, size))
    {
        printf("Result: ");
        printArray(copyArr1, size);
    }
    else
    {
        printf("No elements multiple of 3 found.\n");
    }
    free(copyArr1);
    
    printf("\n2.Inserting a number K after all even elements:\n");
    size_t newSize;
    int* arr2 = insertKAfterEvenSimple(arr, size, &newSize);
    if (arr2 != NULL)
    {
        printf("Result (new size: %zu): ", newSize);
        printArray(arr2, newSize);
        free(arr2);
    }
    
    printf("\n3. Formation of array M from array P according to the rule:\n");
    int* M = createMFromP(arr, size);
    printf("Array M: ");
    printArray(M, size);
    free(M);
    
    free(arr);
    return 0;
}

int Value(void)
{
    int value = 0;
    if (!scanf_s("%d", &value))
    {
        printf("Error, invalid value entered!\n");
        abort();        
    }
    return value;
}

size_t getSize(char* message)
{
    printf("%s", message);
    int value = Value();
    if (value <= 0)
    {
        printf("Error! Size must be a positive number..\n");
        abort();
    }
    return (size_t)value;
}

void fillArray(int* arr, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("Enter a[%zu] = ", i);
        arr[i] = Value();
    }
}

void printArray(const int* arr, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf(" %d ", arr[i]);
    }
    printf("\n");
}

void checkRange(const int start, const int end)
{
    if(start > end)
    {
        printf("Error! Range start must be less than or equal to end.\n");
        exit(1);
    }
}

void fillRandom(int* arr, const size_t size)
{
    printf("Enter the start of the random number range: ");
    int start = Value();
    printf("Enter the end of the random number range: ");
    int end = Value();
    checkRange(start, end);
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = (rand() % (end - start + 1)) + start;
    }
}

int* copyArray(const int* arr, const size_t size)
{
    int* copyArr = malloc(sizeof(int) * size);
    if (copyArr == NULL)
    {
        printf("Memory allocation error!\n");
        exit(1);
    }
    for (size_t i = 0; i < size; i++)
    {
        copyArr[i] = arr[i];
    }
    return copyArr;
}

int replaceLastMultipleOfThree(int* copyArr, const size_t size)
{
    int found = 0;
    size_t lastIndex = -1;

    for (size_t i = 0; i < size; i++)
    {
        if (copyArr[i] != 0 && copyArr[i] % 3 == 0)
        {
            lastIndex = i;
            found = 1;
        }
    }
    
    if (found)
    {
        copyArr[lastIndex] = 0;
        return 1;
    }
    
    return 0;
}

int* insertKAfterEvenSimple(const int* arr, const size_t size, size_t* newSize)
{
    printf("Enter value K: ");
    int K = Value();
    
    // Считаем количество четных элементов
    size_t evenCount = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] % 2 == 0)
        {
            evenCount++;
        }
    }
    
    // Создаем новый массив
    *newSize = size + evenCount;
    int* newArr = malloc(*newSize * sizeof(int));
    if (newArr == NULL)
    {
        printf("Memory allocation error!\n");
        return NULL;
    }
    
    // Заполняем новый массив
    size_t j = 0;
    for (size_t i = 0; i < size; i++)
    {
        newArr[j++] = arr[i];
        if (arr[i] % 2 == 0)
        {
            newArr[j++] = K;
        }
    }
    
    return newArr;
}

int* createMFromP(const int* P, const size_t size)
{
    int* M = malloc(size * sizeof(int));
    if (M == NULL)
    {
        printf("Memory allocation error!\n");
        exit(1);
    }
    
    for (size_t i = 0; i < size; i++)
    {
        if (i == 0 || i == size - 1)
        {
            M[i] = 0;
        }
        else if ((i + 1) % 4 == 0)
        {
            M[i] = 4 * abs(P[i]);
        }
        else
        {
            M[i] = -P[i] * (int)(i + 1);
        }
    }
    
    return M;
}