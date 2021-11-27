//Author - Koteneva Elena
//Development Environment - Terminal Linux Mint

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
// основание, а показатель уменьшается на единицу) 

int recPowerFast(int n, int ex){
    if (ex <= 0) return 1;
    if (ex % 2 == 0) return recPowerFast(n * n, ex / 2);
    else return n * recPowerFast(n, ex - 1); 
}

int main()
{
//---------1------------   
    int n;
    printf("n -> ");
    scanf("%d", &n);
    printf("Bin = ");
    dectobin(n);
//---------2------------
    int a, b;    
    putc("a = ");
    scanf("%d", &a);
    putc("b = ");
    scanf("%d", &b);
    putc("a ^ b = ");
    printf("%d",recPower(a, b));


return 0;
}
