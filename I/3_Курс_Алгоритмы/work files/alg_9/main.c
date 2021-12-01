#include <stdio.h>
#include <stdlib.h>

#define T int
#define SIZE 1000
#define true 1 == 1
#define false 1 != 1
#define SZ 10

typedef struct {
    int pr;
    int dat;
} Node;

Node* arr[SZ];
int head;
int tail;
int items;

typedef int boolean;

int cursor = -1;
T Stack[SIZE];

T Queue[SIZE];
int first = 0;
int end = -1;
int items = 0;


void init() {
    for (int i = 0; i < SZ; ++i) {
        arr[i] = NULL;
    }
    head = 0;
    tail = 0;
    items = 0;
}

void ins(int pr, int dat) {
    Node *node = (Node*) malloc(sizeof(Node));
    node->dat = dat;
    node->pr = pr;

    if (items == SZ) {
        printf("%s \n", "Queue is full");
        return;
    }
    else {
        arr[tail++] = node;
        items++;
    }
}

void printQueue() {
    printf("[ ");
    for (int i = head; i < tail; ++i) {
        if (arr[i] == NULL)
            printf("[*. *] ");
        else
            printf("[%d, %d] ", arr[i]->pr, arr[i]->dat);
    }
    printf(" ]\n");
}

Node* remPr() {
    if (items == 0) {
        printf("%s \n", "Queue is empty");
        return NULL;
    }
    else {
        int idx = 0;
        int minPr;
        int posMinPr = 0;

        if (arr[head] == NULL) {
            head++;
        }

        minPr = arr[head]->pr;

        for (int i = head + 1; i < tail; ++i) {

            idx = i % SZ;
            if (arr[idx] == NULL) {
                idx++;
            }
            else if (minPr > arr[idx]->pr) {
                minPr = arr[idx]->pr;
                posMinPr = idx;

            }
        }

        Node *tmp = arr[posMinPr];
        arr[posMinPr] = NULL;

        for (int i = posMinPr; i < tail; ++i){
            idx = i % SZ;
            arr[idx] = arr[idx + 1];
            idx++;
        }

        tail--;
        items--;
        return tmp;
    }
}

boolean push(T data){
    if (cursor < SIZE) {
        Stack[++cursor] = data;
        return true;
    }
    else {
        printf("%s \n", "Stack overflow");
        return false;
    }
}

T pop() {
    if  (cursor != -1) {
        return Stack[cursor--];
    }
    else {
        printf("%s \n", "Stack is empty");
        return -1;
    }
}

void convertDecToBin(int n){
    if (n < 0)
        n = -n;
    while (n > 0) {
        push(n % 2);
        n /= 2;
    }
}


int main()
{
//----1---
// Описать очередь с приоритетным исключением.
    init();
    ins(1, 11);
    ins(1, 22);
    ins(1, 33);
    ins(2, 44);
    ins(3, 55);
    ins(1, 55);
    ins(1, 55);
    ins(5, 55);
    ins(0, 55);
    ins(1, 55);
    printQueue();

    for (int i = 0; i < 2; ++i) {
        Node* n = remPr();
        printf("pr=%d, dat=%d \n", n->pr, n->dat);
        printQueue();
    }
//----2----
// Реализовать перевод из десятичной в двоичную систему счисления с использованием стека.
    int a;
    printf("Decimal number: ");
    scanf("%d ",&a);
    convertDecToBin(a);
    printf("Bin number: ");
    while (cursor != -1)
        printf("%d", pop());
    printf("\n");

    return 0;
}
