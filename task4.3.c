#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define scanf_s scanf

/**
 * @brief Считывает значение введенное с клавиатуры с проверкой ввода
 * @return Считанное значение
 */
int Value();

/**
 * @brief Получение размера массива
 * @param message сообщение пользователю
 * @return Размер массива
 */
size_t getSize(char* message);

/**
 * @brief Заполнение массива с клавиатуры
 * @param arr Указатель на массив
 * @param rows Количество строк массива
 * @param columns Количество столбцов массива
 */
void fillArray(int** arr, const size_t rows, const size_t columns);

/**
 * @brief Вывод массива на экран
 * @param arr Массив
 * @param rows Количество строк массива
 * @param columns Количество столбцов массива
 */
void printArray(int** arr, const size_t rows, const size_t columns);

/**
 * @brief Заполнение массива случайными числами
 * @param arr Массив
 * @param rows Количество строк массива
 * @param columns Количество столбцов массива
 */
void fillRandom(int** arr, const size_t rows, const size_t columns);

/**
 * @brief Создаёт массив по указанным пользователем вводным данным
 * @param rows количество строк массива
 * @param columns количество столбцов массива
 * @return полученный массив
 */
int** getArray(const size_t rows, const size_t columns);

/**
 * @brief Освобождает память, выделенную под массив
 * @param arr массив
 * @param rows количество строк массива
 */
void freeArray(int** arr, const size_t rows);

/**
 * @brief Проверяет корректность диапазона случайных чисел
 * @param start Начало диапазона
 * @param end Конец диапазона
 */
void checkRange(const int start, const int end);

/**
 * @brief Создаёт копию массива
 * @param arr Исходный массив
 * @param rows Количество строк массива
 * @param columns Количество столбцов массива
 * @return Полученный массив
 */
int** copyArray(int** arr, const size_t rows, const size_t columns);

/**
 * @brief Заменяет минимальный по модулю элемент каждого столбца нулём
 * @param arr Массив
 * @param rows Количество строк массива
 * @param columns Количество столбцов массива
 */
void replaceAbs(int** arr, const size_t rows, const size_t columns);

/**
 * @brief Проверяет есть ли в столбце нулевой элемент
 * @param arr Массив
 * @param rows Количество строк массива
 * @param col Индекс столбца
 * @return 1 если в столбце есть нулевой элемент иначе 0
 */
int hasZeroInColumn(int** arr, const size_t rows, const size_t col);

/**
 * @brief Вставляет первый столбец один раз после всех столбцов содержащих нулевой элемент
 * @param arr Исходный массив
 * @param rows Количество строк массива
 * @param columns Количество столбцов исходного массива
 * @param newColumns Указатель на переменную в которую будет записано новое количество столбцов
 * @return Новый массив с выполненной вставкой
 */
int** insertFirstColumnOnceAfterZeroColumns(int** arr, const size_t rows, const size_t columns, size_t* newColumns);

/**
 * @brief RANDOM - заполнение массива случайными числами
 * @brief MANUAL - заполнение массива вручную.
 */
enum {RANDOM = 1, MANUAL};

/**
 * @brief Точка входа в программу
 * @return 0 если программа выполнена корректно
 */
int main()
{
    srand(time(NULL));
    size_t rows = getSize("Enter number of rows: ");
    size_t columns = getSize("Enter number of columns: ");
    int** arr = getArray(rows, columns);
    printf("Choose array filling method:\n"
           "%d - random numbers\n"
           "%d - manual input\n"
           "Enter the required method number: ",
           RANDOM, MANUAL);
    int choice = Value();
    switch (choice)
    {
        case RANDOM:
            fillRandom(arr, rows, columns);
            break;
        case MANUAL:
            fillArray(arr, rows, columns);
            break;
        default:
            printf("Error!\n");
            freeArray(arr, rows);
            return 0;
    }
    printf("Original array:\n");
    printArray(arr, rows, columns);

    // First task: replace minimum absolute values
    int** copyArr1 = copyArray(arr, rows, columns);
    replaceAbs(copyArr1, rows, columns);
    printf("Array after replacing minimum absolute values with zero:\n");
    printArray(copyArr1, rows, columns);
    freeArray(copyArr1, rows);

    // Second task: insert first column once after all columns with zero elements
    size_t newCols;
    int** newArr = insertFirstColumnOnceAfterZeroColumns(arr, rows, columns, &newCols);
    printf("Array after inserting first column once after all columns with zero elements:\n");
    printArray(newArr, rows, newCols);
    freeArray(newArr, rows);

    freeArray(arr, rows);
    return 0;
}

int Value()
{
    int value = 0;
    if (!scanf_s("%d", &value))
    {
        printf("Error!\n");
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
        printf("Error!");
        abort();
    }
    return (size_t)value;
}

void fillArray(int** arr, const size_t rows, const size_t columns)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            printf("Enter a[%zu,%zu] = ", i, j);
            arr[i][j] = Value();
        }
    }
}

void printArray(int** arr, const size_t rows, const size_t columns)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            printf("%5d", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void fillRandom(int** arr, const size_t rows, const size_t columns)
{
    printf("Enter start of random numbers range: ");
    int start = Value();
    printf("Enter end of random numbers range: ");
    int end = Value();
    checkRange(start, end);
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            arr[i][j] = (rand() % (end - start + 1)) + start;
        }
    }
}

int** getArray(const size_t rows, const size_t columns)
{
    int** arr = malloc(rows * sizeof(int*));
    if (arr == NULL)
    {
        printf("Memory allocation error.\n");
        exit(1);
    }
    for (size_t i = 0; i < rows; i++)
    {
        arr[i] = malloc(columns * sizeof(int));
        if (arr[i] == NULL)
        {
            printf("Memory allocation error.\n");
            for (size_t j = 0; j < i; j++)
            {
                free(arr[j]);
            }
            free(arr);
            exit(1);
        }
    }
    return arr;
}

void freeArray(int** arr, const size_t rows)
{
    for (size_t i = 0; i < rows; i++)
    {
        free(arr[i]);
    }
    free(arr);
}

void checkRange(const int start, const int end)
{
    if (start > end)
    {
        printf("Error: end must be greater than start!\n");
        exit(1);
    }
}

int** copyArray(int** arr, const size_t rows, const size_t columns)
{
    int** copyArr = getArray(rows, columns);
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            copyArr[i][j] = arr[i][j];
        }
    }
    return copyArr;
}

void replaceAbs(int** arr, const size_t rows, const size_t columns)
{
    for (size_t j = 0; j < columns; j++)
    {
        size_t minIndex = 0;
        int minAbs = abs(arr[0][j]);
        for (size_t i = 1; i < rows; i++)
        {
            int curAbs = abs(arr[i][j]);
            if (curAbs < minAbs)
            {
                minAbs = curAbs;
                minIndex = i;
            }
        }
        arr[minIndex][j] = 0;
    }
}

int hasZeroInColumn(int** arr, const size_t rows, const size_t col) {
    for (size_t i = 0; i < rows; i++) {
        if (arr[i][col] == 0) {
            return 1;
        }
    }
    return 0;
}

int** insertFirstColumnOnceAfterZeroColumns(int** arr, const size_t rows, const size_t columns, size_t* newColumns) {
    // Check if there is at least one column with zero element
    int hasZeroColumn = 0;
    for (size_t j = 0; j < columns; j++) {
        if (hasZeroInColumn(arr, rows, j)) {
            hasZeroColumn = 1;
            break;
        }
    }

    // Calculate new size: if there are columns with zeros, add one column
    *newColumns = columns + (hasZeroColumn ? 1 : 0);
    int** newArr = getArray(rows, *newColumns);

    // Copy all columns of the original array
    for (size_t j = 0; j < columns; j++) {
        for (size_t i = 0; i < rows; i++) {
            newArr[i][j] = arr[i][j];
        }
    }

    // If there are columns with zeros, add first column at the end
    if (hasZeroColumn) {
        for (size_t i = 0; i < rows; i++) {
            newArr[i][columns] = arr[i][0];
        }
    }

    return newArr;
}