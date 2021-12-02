//Написать функцию проверки, является ли число простым
//Author - Koteneva Elena
//Development Environment - Terminal Linux Mint

#include <stdio.h>

int main()
{
   // в данной переменной будем хранить число, которое необходимо проверить на простоту
    int n;
    int c = 0; 
 
    // вывод текста в консоль
    printf("Input a number: ");
 
    // читаем число n
    scanf("%d", &n);
 
    if (n > 1)
    {
               
        // в цикле перебираем числа от 2 до n - 1
        for (int i = 2; i < n; i++){
            if ((n % i) == 0) c++;
            }
    }
    else  printf("Not simple number\n");

    // выводим информацию о том, простое ли число n: 1 - да, 0 - нет
    if (c == 0) printf("Simple number\n");
    else printf("Not simple number\n");

return 0;
}
