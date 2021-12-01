#include <stdio.h>

#define T char
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

//int pri = 0;

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

void insPr(int pr, int dat) {
    Node *node = (Node*) malloc(sizeof(Node));
    node->dat = dat;
    node->pr = pr;
    int flag;

    if (items == 0) {
        arr[tail++] = node;
        items++;
    }
    else if (items == SZ) {
        printf("%s \n", "Queue is full");
        return;
    }
    else {
        int i = 0;
        int idx = 0;
        Node *tmp;
        for (i = head; i < tail; ++i) {
            idx = i % SZ;
            if (arr[idx]->pr > pr)
                break;
            else
                idx++;
        }
        flag = idx % SZ;
        i++;
        while (i <= tail) {
            idx = i % SZ;
            tmp = arr[idx];
            arr[idx] = arr[flag];
            arr[flag] = tmp;
            i++;
        }
        arr[flag] = node;
        items++;
        tail++;
    }
}

void printQueue() {
    printf("[ ");
    for (int i = 0; i < SZ; ++i) {
        if (arr[i] == NULL)
            printf("[*. *] ");
        else
            printf("[%d, %d] ", arr[i]->pr, arr[i]->dat);
    }
    printf(" ]\n");
}

Node* rem() {
    if (items == 0) {
        return NULL;
    }
    else {
        int idx = head++ % SZ;
        Node *tmp = arr[idx];
        arr[idx] = NULL;
        items--;
        return tmp;
    }
}

void sortInserts(int* arr, int len){
    int temp, pos;
    for (int i = 1; i < len; ++i){
        temp = arr[i];
        pos = i - 1;
        while (pos >= 0 && arr[pos] > temp){
            arr[pos + 1] = arr[pos];
            pos--;
        }
        arr[pos + 1] = temp;
    }
}

Node* remPr() {
    int flag;
    if (items == 0) {
        printf("%s \n", "Queue is empty");
        return NULL;
    }
    else {
        //int i = 0;
        int idx = 0;
        int minPr = 0; //arr[head]->pr;
        printf("minPr=%d idx=%d flag=%d head=%d\n", minPr, idx, flag, head);
        for (int i = head; i < tail; ++i) {
            idx = i % SZ;
            if (arr[idx]->pr == minPr) {
                 minPr = arr[idx]->pr;
                 break;
            }
            else {

                idx++;
            }
        }

        flag = idx % SZ;
        Node *tmp = arr[flag];
        arr[flag] = NULL;
        items--;
        return tmp;
    }
}

boolean enqueue(T data) {

    if (items == SIZE) {
        printf("%s \n", "Queue is full");
        return false;
    }
    if (end == SIZE - 1)
        end = -1;
    Queue[++end] = data;
    items++;
    return true;
}

T dequeue() {
    if (items == 0) {
        printf("%s \n", "Queue is empty");
        return -1;
    }
    else {
        char tmp = Queue[first++];
        first %= SIZE;  // if (first == SIZE) first = 0;
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

int main()
{
    init();
    ins(1, 11);
    ins(1, 22);
    ins(2, 33);
    ins(2, 44);
    ins(3, 55);
    ins(1, 55);
    ins(1, 55);
    ins(5, 55);
    ins(0, 55);
    ins(1, 55);
    printQueue();

//    for (int i = 0; i < 7; ++i) {
//        Node* n = remPr();
//        printf("pr=%d, dat=%d \n", n->pr, n->dat);
//    }
    remPr();
    printQueue();
    remPr();
    printQueue();
    return 0;
}
