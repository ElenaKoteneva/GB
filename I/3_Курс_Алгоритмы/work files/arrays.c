// Author - Koteneva Elena
// Algorithms. Task 6.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 1. Реализовать пузырьковую сортировку двумерного массива например, массив
// 1,9,2 5,7,6 4,3,8 должен на выходе стать 1,2,3 4,5,6 7,8,9
void bubbleSort(int* arr, int len){
    for (int i = 0; i < len; ++i){
        for (int j = 0; j < len; ++j){
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
        }
    }
}
void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

// 2. Описать подробную блок-схему алгоритма Трабба-Прадо-Кнута 1 - запросить
// у пользователя 11 чисел и записать их в последовательность П 2 - инвертировать
// последовательность П 3 - для каждого элемента последовательности П произвести
// вычисление по формуле sqrt(fabs(Х)) + 5 * pow(Х, 3) и если результат вычислений
// превышает 400 - проинформировать пользователя.
// Реализовать алгоритм Трабба-Прадо-Кнута в коде на языке С
double f(double x){
    return sqrt(fabs(x)) + 5.0 * pow(x, 3.0);
}
void TPK(void){
    double A[11] = {7.9, 7.3, 20.9, 112.0, 5.0, 3.0, 2.9, 9.0, 21.7, 31.2, 4.1};
    for (int i = 10; i > 0; --i){
        if (f(A[i]) > 400) printf("%d Overflow\n", i);
        else printf("%d %f\n", i, f(A[i]))
    }
}
// Функции для работы с массивом

int** init2dArray(int** array, const int row, const int col){
    array = (int**)calloc(sizeof(int*), row);
    for (int i = 0; i < row; ++i){
        *(array + i) = (int*)calloc(sizeof(int), col);
    }
    return array;
}
int* initArray(int* array, const int len){
    array = (int*)calloc(sizeof(int*), len);

    return array;
}
void print2dIntArray(int** array, const int row, const int col){
    for (int i = 0; i < row; ++i){
        for (int j = 0; j < col; ++j){
            printf("%4d", *((*(array + i)) + j));
        }
        printf("\n");
    }
}
void fillRandom2d(int** array, const int row, const int col, int border){
    for (int i = 0; i < row; ++i){
         for (int j = 0; j < col; ++j){
             *((*(array + i)) + j) = rand() % border;
         }
     }
}

int main()
{
//---------1------------
    const int LEN = 2;
    const int HEI = 10;
    int** arr = init2dArray(arr, LEN, HEI);
    int* temp = initArray(temp, LEN * HEI);
    int k = 0;                                  //вспомогательная переменная

    fillRandom2d(arr, LEN, HEI, 10);
    printf("Исходный двумерный массив:\n");
    print2dIntArray(arr, LEN, HEI);


    for (int i = 0; i < LEN; ++i){
         for (int j = 0; j < HEI; ++j){
             *(temp + k) = *((*(arr + i)) + j);
             k++;
         }
    }
    bubbleSort(temp, LEN * HEI);

    k = 0;
    for (int i = 0; i < LEN; ++i){
         for (int j = 0; j < HEI; ++j){
             *((*(arr + i)) + j) = *(temp + k);
             k++;
         }
    }
    printf("Отсортированный двумерный массив:\n");
    print2dIntArray(arr, LEN, HEI);
//---------2------------
    TPK();
return 0;
}
