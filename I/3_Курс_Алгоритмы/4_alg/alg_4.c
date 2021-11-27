// Author - Koteneva Elena
// Development Environment - QT Creator
// Algorithms. Task 4.

#include <stdio.h>

// 1. Реализовать функцию перевода чисел из десятичной системы в двоичную, используя рекурсию.

void dectobin(int n){
  if (n >= 2)
    dectobin(n / 2);
  printf("%d",n % 2);
}

// Реализовать функцию возведения числа [a] в степень [b]:
// 2. Рекурсивно.

int recPower(int n, int ex){
    if (ex <= 0) return 1;
    return n * recPower(n, ex - 1);
}

//3. Рекурсивно, используя свойство чётности степени (то есть, если степень,
// в которую нужно возвести число, чётная, основание возводится в квадрат,
// а показатель делится на два, а если степень нечётная - результат умножается на
// основание, а показатель уменьшается на единицу).

int recPowerFast(int n, int ex){
    if (ex <= 0) return 1;
    if (ex % 2 == 0) return recPowerFast(n * n, ex / 2);
    else return n * recPowerFast(n, ex - 1);
}

// 4 Реализовать нахождение количества маршрутов шахматного короля с препятствиями
// (где единица - это наличие препятствия, а ноль - свободная для хода клетка).

int kingRoutes(int x, int y, int ** avail){
    if (avail[x][y] == 1) return 0;
    if (x == 0 && y == 0){
        return 0;
    }
    else if (x == 0){
        if (kingRoutes(x, y - 1, avail) == 0 && y != 1){
            return 0;
        }
        return 1;
    }
    else if (y == 0){
       if (kingRoutes(x - 1, y, avail) == 0 && x != 1){
           return 0;
       }
       return 1;
    }

    return kingRoutes(x, y - 1, avail) + kingRoutes(x - 1, y, avail);
}

// Дополнительные функции для работы с массивом

int** init2dArray(int** array, const int row, const int col){
    array = (int**)calloc(sizeof(int*), row);
    for (int i = 0; i < row; ++i){
        *(array + i) = (int*)calloc(sizeof(int), col);
    }
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

void set2dInt(int** array, int x, int y, int val){
    *((*(array + x)) + y) = val;
}
int main()
{
////---------1------------
//    int n;
//    printf("n -> ");
//    scanf("%d", &n);
//    printf("Bin = ");
//    dectobin(n);
////---------2------------
//    int a, b;
//    printf("\na = ");
//    scanf("%d", &a);
//    printf("\nb = ");
//    scanf("%d", &b);
//    printf("\na ^ b = ");
//    printf("%d\n",recPower(a, b));
////---------3------------
//    printf("\na = ");
//    scanf("%d", &a);
//    printf("\nb = ");
//    scanf("%d", &b);
//    printf("\na ^ b = ");
//    printf("%d\n",recPowerFast(a, b));
//---------4------------
    const int SZ = 6;
    int** desk = init2dArray(desk, SZ, SZ);

    set2dInt(desk, 0, 2, 1);
    set2dInt(desk, 2, 1, 1);
    set2dInt(desk, 2, 2, 1);
    print2dIntArray(desk, SZ, SZ);

    for (int y = 0; y < SZ; ++y){
        for (int x = 0; x < SZ; ++x){
            printf("%5d", kingRoutes(x, y, desk));
        }
        printf("\n");
    }


return 0;
}
