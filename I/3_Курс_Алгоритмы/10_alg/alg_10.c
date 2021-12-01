#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define T char
#define SIZE 1000
#define true 1 == 1
#define false 1 != 1

typedef int bool;

int cursor = -1;

typedef struct Node
{
    int dat;
    struct Node *next;
} Node;

typedef struct
{
    Node *head;
    int size;
} List;

typedef struct
{
    Node *head;
    int size;
} Stack;

void initStack(Stack *stack)
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

void printNodeStack(Node *n)
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
        printNodeStack(current);
    else
    {
        do
        {
            printNodeStack(current);
            current = current->next;
        } while (current != NULL);
    }
    printf(" Size: %d\n", stack->size);
}

void checkBrackerSeq(char *array) {
    Stack *st1 = (Stack *)malloc(sizeof(Stack));
    Stack *st2 = (Stack *)malloc(sizeof(Stack));
    Stack *st3 = (Stack *)malloc(sizeof(Stack));

    initStack(st1);
    initStack(st2);
    initStack(st3);

    if (strlen(array) == 0) {
        printf("String is empty\n");
        return;
    }
    else {
        for (int i = 0; i < (int)strlen(array); ++i) {
            if (array[i] == '(') {
                push(st1,'(');
                if ((array[i + 1] == ']') || (array[i + 1] == '}')) {
                    printf("Wrong bracker sequence\n");
                    return;
                }

            }
            else if (array[i] == ')') {
                pop(st1);
            }
            else if (array[i] == '[') {
                push(st2, '[');
                if ((array[i + 1] == ')') || (array[i + 1] == '}')) {
                    printf("Wrong bracker sequence\n");
                    return;
                }
            }
            else if (array[i] == ']') {
                pop(st2);
            }
            else if (array[i] == '{') {
                push(st3, '{');
                if ((array[i + 1] == ')') || (array[i + 1] == ']')) {
                    printf("Wrong bracker sequence\n");
                    return;
                }
            }
            else if (array[i] == '}') {
                pop(st3);
            }

        }
    }

    if ((st1->size == 0) && (st2->size == 0) && (st3->size == 0)) {
        printf("True bracker sequence\n");
    }
    else
        printf("Wrong bracker sequence\n");
}

void initList(List *lst)
{
    lst->head = NULL;
    lst->size = 0;
}

void ins(List *lst, int data)
{
    Node *new = (Node *)malloc(sizeof(Node));
    new->dat = data;
    new->next = NULL;

    Node *current = lst->head;
    if (current == NULL)
    {
        lst->head = new;
        lst->size++;
        return;
    }
    else
    {
        while (current->next != NULL)
            current = current->next;
        current->next = new;
        lst->size++;
    }
}

Node *rm(List *lst, int data)
{
    Node *current = lst->head;
    Node *parent = NULL;
    if (current == NULL)
        return NULL;

    while (current->next != NULL && current->dat != data)
    {
        parent = current;
        current = current->next;
    }
    if (current->dat != data)
        return NULL;
    if (current == lst->head)
    {
        lst->head = current->next;
        lst->size--;
        return current;
    }
    parent->next = current->next;
    lst->size--;
    return current;
}

void printNodeList(Node *n)
{
    if (n == NULL)
    {
        printf("[]");
        return;
    }
    printf("[%d] ", n->dat);
}

void printList(List *lst)
{
    Node *current = lst->head;
    if (current == NULL)
        printNodeList(current);
    else
    {
        do
        {
            printNodeList(current);
            current = current->next;
        } while (current != NULL);
    }
    printf(" Size: %d\n", lst->size);
}

void copyList(List *lst, List *newlst) {

    Node *new = NULL;
    Node *current = lst->head;

    if (newlst == NULL) {
        return;
    }

    if (current == NULL) {
        return;
    }
    else {
        newlst->head = (Node*)malloc(sizeof (Node));
        newlst->head->next = NULL;
        new = newlst->head;
        new->dat = current->dat;

        while (current->next != NULL) {
            new->next = (Node*)malloc(sizeof (Node));
            new->next->dat = current->next->dat;
            current = current->next;
            new = new->next;
            new->next = 0;

        }
        newlst->size = lst->size;
    }
}

void freeList(List *lst) {
    Node *tmp;

    while (lst->size != 0) {
        tmp = lst->head;
        lst->head = lst->head->next;
        free(tmp);
        lst->size--;
    }
}

void initOneLinkList(List *lst)
{
    lst->head = NULL;
    lst->size = 0;
}

void printOneLinkNode(Node *n)
{
    if (n == NULL)
    {
        printf("[]");
        return;
    }
    printf("[%d] ", n->dat);
}

void printOneLinkList(List *lst)
{
    Node *current = lst->head;
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

void insertCyclic(List *lst, int data)
{
    Node *new = (Node *)malloc(sizeof(Node));
    new->dat = data;
    new->next = lst->head;

    Node *current = lst->head;
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

Node *removeCyclic(List *lst, int data)
{
    Node *current = lst->head;
    Node *parent = NULL;
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
            Node *tmp = current;
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

int checkSortList(List *lst)
{
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
        Node *current = lst->head->next;
        Node *parent = lst->head;
        int temp = 0;
        while (temp < lst->size-1) {
            if (parent->dat <= current->dat) {
                k++;
            }
            else {
                k--;
            }
            current = current->next;
            parent = parent->next;
            temp++;
        }
        if (k == lst->size-1)
            return 1;
        else
            return 0;
        }
}


int main(const int arc, const char **argv)
{
//-----1-----

    char arr[1000] = "([])";
    printf("%s ", arr);
    checkBrackerSeq(arr);

//-----2-----

    List lst;
    initList(&lst);
    List newlst;
    initList(&newlst);

    ins(&lst, 1);
    ins(&lst, 10);
    ins(&lst, 5);
    printf("First sequence:\n");
    printList(&lst);
    copyList(&lst,&newlst);
    rm(&lst, 1);
    printf("New sequence:\n");
    printList(&newlst);

//    freeList(&lst);
//    freeList(&newlst);
//    printList(&lst);
//    printList(&newlst);

//-----3-----

    List *l = (List*)malloc(sizeof (List));
    initOneLinkList(l);
    insertCyclic(l, 2);
    insertCyclic(l, 5);
    insertCyclic(l, 2);
    insertCyclic(l, 2);
    printOneLinkList(l);

    if (checkSortList(l) == 1)
        printf("List is sorted\n");
    else if (checkSortList(l) == 0)
        printf("List is not sorted\n");

    return 0;
}
