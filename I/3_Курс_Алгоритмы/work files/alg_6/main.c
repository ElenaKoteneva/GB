// Author - Koteneva Elena
// Development Environment - QT Creator
// Algorithms. Task 6.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 1. Реализовать пузырьковую сортировку двумерного массива например, массив
// 1,9,2 5,7,6 4,3,8 должен на выходе стать 1,2,3 4,5,6 7,8,9
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

// 2. Описать подробную блок-схему алгоритма Трабба-Прадо-Кнута 1 - запросить
// у пользователя 11 чисел и записать их в последовательность П 2 - инвертировать
// последовательность П 3 - для каждого элемента последовательности П произвести
// вычисление по формуле sqrt(fabs(Х)) + 5 * pow(Х, 3) и если результат вычислений
// превышает 400 - проинформировать пользователя.
// Реализовать алгоритм Трабба-Прадо-Кнута в коде на языке С

// f (x) = sqrt (| x |) + 5 * x ** 3
double f(double x){
    return (sqrt(fabs(x)) + 5.0 * pow(x, 3.0));
}
void TPK(void){
    double sec[11] = {5,4,4,4,4,14,4,2,2,2,2};

    for (int i = 10; i >= 0; i--){
        if (f(sec[i]) > 400) printf("%d OVERFLOW\n", i + 1);
        else printf("%d %.2f\n",i + 1 ,f(sec[i]));
    }
}

// Дополнительные функции для работы с массивом

int** init2dArray(int** array, const int row, const int col){
    array = (int**)calloc((unsigned long)sizeof(int*), (unsigned long)row);
    for (int i = 0; i < row; ++i){
        *(array + i) = (int*)calloc((unsigned long)sizeof(int), (unsigned long)col);
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
void printIntArray(int* array, const int len){
    for (int i = 0; i < len; ++i){
        printf("%3d", *(array + i));
    }
    printf("\n");

}
void fillRandom2d(int** array, const int row, const int col, int border){
    for (int i = 0; i < row; ++i){
         for (int j = 0; j < col; ++j){
             *((*(array + i)) + j) = rand() % border;
         }
     }
}
void fillRandom(int* arr, int len, int border){
    for (int i = 0; i < len; ++i){
        *(arr + i) = rand() % border;
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
