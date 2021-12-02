#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Написать программу, которая определяет, является ли введенная скобочная последовательность правильной.
// Примеры правильных скобочных выражений: (), ([])(), {}(), ([{}]), неправильных — )(, ())({), (, ])}),
// ([(]) для скобок [,(,{. Например: (2+(2*2)) или [2/{5*(4+7)}]

#define T char
#define true 1 == 1
#define false 1 != 1

typedef int bool;

typedef struct Node
{
    T dat;
    struct Node *next;
} Node;

typedef struct
{
    Node *head;
    int size;
} Stack;

void init(Stack *stack)
{
    stack->head = NULL;
    stack->size = 0;
}

bool push(Stack *stack, T value)
{
    Node *tmp = (Node *)malloc(sizeof(Node));
    if (tmp == NULL)
    {
        printf("Stack overflow\n");
        return false;
    }
    tmp->dat = value;
    tmp->next = stack->head;

    stack->head = tmp;
    stack->size++;
    return true;
}

T pop(Stack *stack)
{
    if (stack->size == 0)
    {
        //printf("Stack is empty\n");
        return -1;
    }
    Node *tmp = stack->head;
    T data = stack->head->dat;
    stack->head = stack->head->next;
    stack->size--;
    free(tmp);
    return data;
}

void printNode(Node *n)
{
    if (n == NULL)
    {
        printf("[]");
        return;
    }
    printf("[%c] ", n->dat);
}

void printStack(Stack *stack)
{
    Node *current = stack->head;
    if (current == NULL)
        printNode(current);
    else
    {
        do
        {
            printNode(current);
            current = current->next;
        } while (current != NULL);
    }
    printf(" Size: %d\n", stack->size);
}

int checkBrackerSeq (char *array) {

}

typedef struct OneLinkNode
{
    int dat;
    struct OneLinkNode *next;
} OneLinkNode;

typedef struct
{
    OneLinkNode *head;
    int size;
} OneLinkList;

void initOneLinkList(OneLinkList *lst)
{
    lst->head = NULL;
    lst->size = 0;
}

int main(const int arc, const char **argv)
{
    Stack *st1 = (Stack *)malloc(sizeof(Stack));
    Stack *st2 = (Stack *)malloc(sizeof(Stack));
    Stack *st3 = (Stack *)malloc(sizeof(Stack));

    init(st1);
    init(st2);
    init(st3);

    char array[1000] = "[{2-1*(2+2)*4}]";

    for (int i = 0; i < (int)strlen(array); ++i) {
        if (array[i] == '(') {
            push(st1,'(');
        }
        else if (array[i] == ')') {
            pop(st1);
        }
        else if (array[i] == '[') {
            push(st2, '[');
        }
        else if (array[i] == ']') {
            pop(st2);
        }
        else if (array[i] == '{') {
            push(st3, '{');
        }
        else if (array[i] == '}') {
            pop(st3);
        }
    }
    if ((st1->size == 0) && (st2->size == 0) && (st3->size == 0)) {
        printf("True sequence\n");
    }
    else
        printf("Wrong sequence\n");

    return 0;
}
