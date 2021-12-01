#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void checkBrackerSeq(char *array) {
    Stack *st1 = (Stack *)malloc(sizeof(Stack));
    Stack *st2 = (Stack *)malloc(sizeof(Stack));
    Stack *st3 = (Stack *)malloc(sizeof(Stack));

    init(st1);
    init(st2);
    init(st3);

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
}

void initOneLinkList(OneLinkList *lst)
{
    lst->head = NULL;
    lst->size = 0;
}

void printOneLinkNode(OneLinkNode *n)
{
    if (n == NULL)
    {
        printf("[]");
        return;
    }
    printf("[%d] ", n->dat);
}

void printOneLinkList(OneLinkList *lst)
{
    OneLinkNode *current = lst->head;
    if (current == NULL)
        printOneLinkNode(current);
    else
    {
        do
        {
            printOneLinkNode(current);
            current = current->next;
        } while (current != lst->head);
    }
    printf(" Size: %d\n", lst->size);
}

void insertCyclic(OneLinkList *lst, int data)
{
    OneLinkNode *new = (OneLinkNode *)malloc(sizeof(OneLinkNode));
    new->dat = data;
    new->next = lst->head;

    OneLinkNode *current = lst->head;
    if (current == NULL)
    {
        lst->head = new;
        new->next = lst->head;
        lst->size++;
        return;
    }
    else
    {
        while (current->next != lst->head)
            current = current->next;
        current->next = new;
        lst->size++;
    }
}

OneLinkNode *removeCyclic(OneLinkList *lst, int data)
{
    OneLinkNode *current = lst->head;
    OneLinkNode *parent = NULL;
    if (current == NULL)
        return NULL;

    while (current->next != lst->head && current->dat != data)
    {
        parent = current;
        current = current->next;
    }
    if (current->dat != data)
        return NULL;
    if (current == lst->head)
    {
        if (current->next == lst->head)
        {
            lst->head = NULL;
            lst->size--;
            return current;
        }
        else
        {
            OneLinkNode *tmp = current;
            while (current->next != lst->head)
                current = current->next;
            lst->head = tmp->next;
            current->next = lst->head;
            lst->size--;
            return tmp;
        }
    }
    parent->next = current->next;
    lst->size--;
    return current;
}

int checkSortList(OneLinkList *lst) {
    if (lst->head == NULL) {
        printf("List is empty\n");
        return -1;
    }
    else if (lst->size <= 2) {
        printf("List too short\n");
        return 2;
    }
    else {
        int k = 0;
        Node *current = (Node*)malloc(sizeof(Node));
        Node *temp = (Node*)malloc(sizeof(Node));
        current = lst->head;
        temp = lst->head->next;
        while (current->next != NULL) {
            if (current->dat <= temp->dat) {
                k++;

            }
            else {
                k--;

            }
            current = current->next;
            temp = temp->next;
        }
        if (k == lst->size)
            return 1;
        else
            return 0;
    }
}

int main(const int arc, const char **argv)
{

//    char arr[1000] = "[{2-1*(2+2)*4}]";
//    checkBrackerSeq(arr);

    OneLinkList *l = (OneLinkList*)malloc(sizeof (OneLinkList));
    initOneLinkList(l);
    insertCyclic(l, 1);
    insertCyclic(l, 2);
    insertCyclic(l, 3);
    insertCyclic(l, 4);
    printOneLinkList(l);
    if (checkSortList(l) == 1)
        printf("List is sorted\n");
    else if (checkSortList(l) == 0)
        printf("List is not sorted\n");



    return 0;
}

