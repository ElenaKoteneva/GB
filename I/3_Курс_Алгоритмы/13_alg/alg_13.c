#include <stdio.h>
#include <stdlib.h>

#define T int
#define true 1 == 1
#define false 1 != 1
#define SZ 6

typedef int boolean;

typedef struct OneLinkNode {
    int dat;
    struct OneLinkNode *next;
} OneLinkNode;

typedef struct {
    OneLinkNode *head;
    int size;
} OneLinkList;

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

typedef struct {
    int node;
    int edges;
} NodeEdges;


int matrix[SZ][SZ] = {
        {0, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 1, 1},
        {0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0},
};

int visited[SZ] = {0};
int traversLinks[SZ] = {0};
int adjacencyLink[SZ] = {0};

void initOneLinkList(OneLinkList *lst) {
    lst->head = NULL;
    lst->size = 0;
}
boolean pushOneLinkStack(OneLinkList *stack, T value) {
    OneLinkNode *tmp = (OneLinkNode*) malloc(sizeof(OneLinkNode));
    if (tmp == NULL) {
        printf("Stack overflow \n");
        return false;
    }
    tmp->dat = value;
    tmp->next = stack->head;

    stack->head = tmp;
    stack->size++;
    return true;
}
T popOneLinkStack(OneLinkList *stack) {
    if (stack->size == 0) {
        printf("Stack is empty \n");
        return -1;
    }
    OneLinkNode *tmp = stack->head;
    T data = stack->head->dat;
    stack->head = stack->head->next;
    free(tmp);
    stack->size--;
    return data;
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
void print2dIntArray(int** array, const int row, const int col, int offset) {
    char format[7];
    sprintf(format, "%%%dd", offset);
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            printf(format, get2dInt(array, i, j));
        }
        printf("\n");
    }
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
void depthStackTravers(int **matrix, int size) {
    OneLinkList* stack = (OneLinkList*) malloc(sizeof (OneLinkList));
    initOneLinkList(stack);
    int visited[size];
    clearVisited(visited, size);
    pushOneLinkStack(stack, visited[0]);
    while (stack->size > 0) {
        int index = popOneLinkStack(stack);
        if (visited[index] == 1) continue;
        visited[index] = 1;
        printf("%c ", index + 65);
        for (int i = size - 1; i >= 0; i--) {
            if (get2dInt(matrix, index, i) == 1 && visited[i] == 0)
                pushOneLinkStack(stack, i);
        }
    }
}
void adjacencyCount(int **matrix, const int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (matrix[i][j] == 1)
                if (i != j)
                    adjacencyLink[i]++;
        }
    }
}
void sortInserts(int* arr, int len){
    int temp, pos;
    for (int i = 1; i < len; ++i){
        temp = arr[i];
        pos = i - 1;
        while (pos >= 0 && arr[pos] < temp){
            arr[pos + 1] = arr[pos];
            pos--;
        }
        arr[pos + 1] = temp;
    }
}
void widthTraversRec(int **matrix, TwoLinkList *queue,
                     int *visit, int *edges, int start, const int size) {
    //ищем смежные вершины, считаем их и ставим в очередь для подсчета их ребер
    for (int next = 0; next < size; ++next) {
        if (get2dInt(matrix, start, next) == 1) {
            ++edges[start];
            if (!visit[next]) {
                visit[next] = 1;
                TwoLinkEnqueue(queue, next);
            }
        }
        //переходим к следующей вершине в очереди
        if (queue->size > 0) {
            widthTraversRec(matrix, queue, visit,
                            edges, TwoLinkDequeue(queue), size);
        }
    }
}
void traversCountRec(int **graph, int start, const int nodes) {
    //
    int *visit = (int*)calloc(nodes, sizeof (int));
    //массив для подсчета полустепеней захода
    int *recEdges = (int*)calloc(nodes, sizeof (int));
    //
    TwoLinkList *queue = (TwoLinkList*)malloc(sizeof (TwoLinkList));
    initTwoLinkList(queue);
    visit[start] = 1;
    widthTraversRec(graph, queue, visit, recEdges, start, nodes);
    for (int i = 0; i < nodes; ++i) {
        sortInserts(recEdges, nodes);
        printf("%d, ", recEdges[i]);
    }

}

int main()
{
//-----1-----

    int** adjacency = init2dIntArray(adjacency, SZ, SZ);
    set2dInt(adjacency, 0, 1, 1);
    set2dInt(adjacency, 0, 2, 1);
    set2dInt(adjacency, 1, 3, 1);
    set2dInt(adjacency, 1, 4, 1);
    set2dInt(adjacency, 1, 5, 1);
    set2dInt(adjacency, 2, 5, 1);
    set2dInt(adjacency, 3, 0, 1);
    set2dInt(adjacency, 5, 4, 1);

    depthStackTravers(adjacency, SZ);
    printf("\n");

//-----2-----
    adjacencyCount(adjacency, SZ);
    sortInserts(adjacencyLink, SZ);
    printIntArray(adjacencyLink, SZ, 2);
    traversCountRec(adjacency, 6, SZ);

    return 0;
}
