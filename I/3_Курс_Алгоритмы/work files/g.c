#include <stdio.h>
#include <stdlib.h>

#define T int
#define N 6
#define true 1 == 1
#define false 1 != 1

typedef int boolean;

typedef struct TwoLinkNode {
    int dat;
    struct TwoLinkNode *next;
    struct TwoLinkNode *prev;
} TwoLinkNode;

typedef struct {
    struct TwoLinkNode *head;
    struct TwoLinkNode *tail;
    int size;
} TwoLinkList;

//const int n = 6;
int matrix[N][N] = {
        {0, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 1, 1},
        {0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0},
};
int visited[N] = {0};

void depthTravers(int st) {
    int r;
    printf("%d ", st);

    visited[st] = 1;
    for (r = 0; r < N; ++r) {
        if (matrix[st][r] == 1 && !visited[r]) {
            depthTravers(r);
        }
    }
}
int get2dInt(int** array, const int row, const int col) {
    return *((*(array + row)) + col);
}
void set2dInt(int** array, const int row, const int col, int value) {
        *((*(array + row)) + col) = value;
    }
int** init2dIntArray(int** array, const int row, const int col) {
        array = (int**) calloc(sizeof(int*), row);
        for (int i = 0; i < row; ++i) {
            *(array + i) = (int*) calloc(sizeof(int), col);
        }
        return array;
    }
void resetArray() {
    for (int i = 0; i < N; ++i) {
        visited[i] = 0;
    }
}
void initTwoLinkList(TwoLinkList *lst) {
    lst->head = NULL;
    lst->tail = NULL;
    lst->size = 0;
}
boolean TwoLinkEnqueue(TwoLinkList *queue, T value) {
    TwoLinkNode *tmp = (TwoLinkNode*) malloc(sizeof(TwoLinkNode));
    if (tmp == NULL) {
        printf("Out of memory! \n");
        return false;
    }
    tmp->dat = value;
    tmp->next = NULL;
    tmp->prev = queue->tail;

    if (queue->tail != NULL) {
        queue->tail->next = tmp;
    }
    if (queue->head == NULL) {
        queue->head = tmp;
    }

    queue->tail = tmp;
    queue->size++;
    return true;
}
T TwoLinkDequeue(TwoLinkList *queue) {
    if (queue->size == 0) {
        printf("Queue is empty \n");
        return -1;
    }
    TwoLinkNode *tmp = queue->head;
    T data = queue->head->dat;

    queue->head = queue->head->next;

    if (queue->head != NULL) {
        queue->head->prev = NULL;
    }
    if (tmp == queue->tail) {
        queue->tail = NULL;
    }

    free(tmp);
    queue->size--;
    return data;
}
void clearVisited(int *arr, int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = 0;
    }
}
void widthTravers(int** matrix, int start, const int size) {
    TwoLinkList* queue = (TwoLinkList*) malloc(sizeof (TwoLinkList));
    initTwoLinkList(queue);
    int visited[size];
    clearVisited(visited, size);
    TwoLinkEnqueue(queue, start);
    while (queue->size > 0) {
        int index = TwoLinkDequeue(queue);
        if (visited[index] == 1) continue;
        visited[index] = 1;
        for (int i = 0; i < size; ++i) {
            if (get2dInt(matrix, index, i) == 1 && visited[i] == 0)
                TwoLinkEnqueue(queue, i);
        }
    }
}

int main()
{
//    depthTravers(0);
//    resetArray();
//    printf("\n");
//    depthTravers(2);
//    resetArray();
//    printf("\n");
//    depthTravers(1);
//    resetArray();
//    printf("\n");

    const int SZ = 6;
    int** adjacency = init2dIntArray(adjacency, SZ, SZ);
    set2dInt(adjacency, 0, 1, 1);
    set2dInt(adjacency, 0, 2, 1);
    set2dInt(adjacency, 1, 3, 1);
    set2dInt(adjacency, 1, 4, 1);
    set2dInt(adjacency, 1, 5, 1);
    set2dInt(adjacency, 2, 5, 1);
    set2dInt(adjacency, 3, 0, 1);
    set2dInt(adjacency, 5, 4, 1);

    widthTravers(adjacency, 0, SZ);
    printf("\n");
    widthTravers(adjacency, 3, SZ);
    printf("\n");
    widthTravers(adjacency, 1, SZ);
    printf("\n");

    return 0;
}
