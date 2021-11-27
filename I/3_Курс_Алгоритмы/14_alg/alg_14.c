#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int htIndex;

int htSize;

htIndex hashS(char* word) {
    int sum = 0;
    for (int i = 0; i < strlen(word); ++i) {
        sum += word[i];
    }
    return sum;
}
void printIntArray(int* array, int size, int offset) {
    char format[7];
    sprintf(format, "%%%dd", offset);
    for (int i = 0; i < size; ++i) {
        printf(format, array[i]);
        if (i != size - 1)
            printf(",");
    }
    printf("\n");
}
void clearIntArray(int* arr, const int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = 0;
    }
}
void sortIntInserts(int* array, int size) {
    int temp, pos;
    for (int i = 1; i < size; ++i) {
        temp = array[i];
        pos = i - 1;
        while (pos >= 0 && array[pos] < temp) {
            array[pos + 1] = array[pos];
            pos--;
        }
        array[pos + 1] = temp;
    }
}
int profitCalculationCoin(int *coin, const int SUM) {

    int* arr = (int)malloc(sizeof (int));

    int s = 0;
    int i = 0;
    int n = 0;

    sortIntInserts(coin, 5);
    while (s <= SUM && i < 5) {
        s += coin[i];
        printf("%d ", coin[i]);
        n++;
        if ((s + coin[i]) > SUM)
            i++;
    }

    return n;
}
int main()
{
    //--1--

    char w[20] = "hello";
    printf("%d \n", hashS(w));

    //--2--

    const int SUM = 98;
    int coin[] = {50, 10, 5, 2, 1};

    printf("\n%d\n", profitCalculationCoin(coin, SUM));

    return 0;
}
