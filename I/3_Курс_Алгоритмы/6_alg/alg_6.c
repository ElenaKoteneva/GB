// Author - Koteneva Elena
// Development Environment - QT Creator
// Algorithms. Task 6.

#include <stdio.h>
#include <stdlib.h>
//#include <math.h>

// 1. Описать в коде улучшенный алгоритм быстрой сортировки
void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}
void bubbleSort(int* arr, int len){
    for (int i = 0; i < len; ++i){
        for (int j = 0; j < len; ++j){
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
        }
    }
}


// 2.Сортировать в массиве целых положительных чисел только чётные числа,
// нечётные оставив на своих местах при помощи алгоритма блочной сортировки,
// то есть массив вида [0 2 8 3 4 6 5 9 8 2 7 3] превратить в [0 2 2 3 4 4 5 9 8 8 7 3]

// Дополнительные функции для работы с массивом

int* initArray(int* array, const int len){
    array = (int*)calloc(sizeof(int*), len);

    return array;
}

void printIntArray(int* array, const int len){
    for (int i = 0; i < len; ++i){
        printf("%3d", *(array + i));
    }
    printf("\n");

}

void fillRandom(int* arr, int len, int border){
    for (int i = 0; i < len; ++i){
        *(arr + i) = rand() % border;
    }
}



int main()
{
//---------1------------
    const int SZ = 30;
    int* arr = initArray(arr, SZ);
    fillRandom2d(arr, LEN, HEI, 10);
    printf("Исходный двумерный массив:\n");
    printIntArray(arr, SZ);


    printf("Отсортированный двумерный массив:\n");
    print2dIntArray(arr, LEN, HEI);
//---------2------------

return 0;
}
