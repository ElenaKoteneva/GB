#include <stdio.h>
#include <stdlib.h>

#define T int
#define N 6
#define true 1 == 1
#define false 1 != 1
#define WIDTH 10
#define HEIGHT 8
#define SZ 6
typedef int boolean;

typedef struct {
    int node;
    int edges;
} NodeEdges;

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


int matrix[N][N] = {
        {0, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 1, 1},
        {0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0},
};

int visited[N] = {0};
int traversLinks[N] = {0};
int adjacencyLink[SZ] = {0};

const int OBSTACLE = -1;
const int BLANK = -2;

int pointX[HEIGHT * WIDTH];
int pointY[HEIGHT * WIDTH];

int len;

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
        printf("%d ", index);
        for (int i = 0; i < size; ++i) {
            if (get2dInt(matrix, index, i) == 1 && visited[i] == 0)
                TwoLinkEnqueue(queue, i);
        }
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
int lee(int **grid, int sx, int sy, int ex, int ey) {
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    int x;
    int y;
    int vector;
    int distance = 0;
    int stop;

    if (grid[sy][sx] == OBSTACLE || grid[ey][ex] == OBSTACLE)
        return 0;
    grid[sy][sx] = 0;
    do {
        stop = true;
        for (y = 0; y < HEIGHT; ++y) {
            for (x = 0; x < WIDTH; ++x) {
                if (grid[y][x] == distance) {
                    for (vector = 0; vector < 4; ++vector) {
                        int nextX = x + dx[vector];
                        int nextY = y + dy[vector];
                        if (nextX >= 0 && nextX < WIDTH &&
                            nextY >=0 && nextY < HEIGHT &&
                            grid[nextY][nextX] == BLANK) {
                                stop = false;
                                grid[nextY][nextX] = distance + 1;
                        }
                    }
                }
            }
        }
        distance++;
    } while (!stop && grid[ey][ex] == BLANK);

    if (grid[ey][ex] == BLANK) return 0;

    len = grid[ey][ex];
    x = ex;
    y = ey;
    while (distance > 0) {
        pointX[distance] = x;
        pointY[distance] = y;
        distance--;
        for (vector = 0; vector < 4; ++vector) {
            int nextX = x + dx[vector];
            int nextY = y + dx[vector];
            if (nextX >= 0 && nextX < WIDTH &&
                nextY >=0 && nextY < HEIGHT &&
                grid[nextY][nextX] == distance) {
                x = nextX;
                y = nextY;
            }
        }
    }

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
        for (int i = 0; i < size; i++) {
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
void traversCount(int **matrix, int start, const int size) {
    TwoLinkList *queue = (TwoLinkList*)malloc(sizeof (TwoLinkList));
    initTwoLinkList(queue);
    clearVisited(visited, N);
    TwoLinkEnqueue(queue, start);
    while (queue->size > 0) {
        int indx = TwoLinkDequeue(queue);
        if (visited[indx] == 1) continue;
        visited[indx] = 1;
        for (int i = 0; i < size; ++i) {
            if (get2dInt(matrix, indx, i) == 1)
                if (i != indx)
                    traversLinks[i]++;
                if (!visited[i])
                    TwoLinkEnqueue(queue, i);
        }
    }
    clearVisited(visited, size);
}
void widthTraversRec(int **matrix, TwoLinkList *queue,
                     int *visit, int edges, int start, const int size) {
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
void composeTraversResult(int *array, const int nodes) {
    NodeEdges *result = (NodeEdges*)calloc(nodes, sizeof (NodeEdges));
    for (int i = 0; i < nodes; ++i) {
        result[i].node = i;
        result[i].edges = array[i];
        sortInsert(result, nodes);
        printResult(result, nodes);
        printf("\n");
        free(result);
    }
}
void traversCountRec(int **graph, int start, const int nodes) {
    int *visit = (int*)calloc(nodes, sizeof (int));
    //массив для подсчета полустепеней захода
    int *recEdges = (int*)calloc(nodes, sizeof (int));
    //
    TwoLinkList *queue = (TwoLinkList*)malloc(sizeof (TwoLinkList));
    initTwoLinkList(queue);
    visit[start] = 1;
    widthTraversRec(graph, queue, visit, recEdges, start, nodes);
    composeTraverResult(recEdges, nodes);
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
    adjacencyCount(adjacency, N);
    printIntArray(adjacencyLink, N, 2);

    traversCountRec(adjacency, 0, N);
    printIntArray(adjacencyLink, N, 2);

//    widthTravers(adjacency, 0, SZ);
//    printf("\n");
//    widthTravers(adjacency, 3, SZ);
//    printf("\n");
//    widthTravers(adjacency, 1, SZ);
//    printf("\n");

//    int **matrix = init2dIntArray(matrix, HEIGHT, WIDTH);
//    for(int i = 0; i < HEIGHT; ++i)
//        for (int j = 0; j < WIDTH; ++j)
//            set2dInt(matrix, i, j, BLANK);

//    set2dInt(matrix, 4, 3, OBSTACLE);
//    set2dInt(matrix, 4, 4, OBSTACLE);
//    set2dInt(matrix, 4, 5, OBSTACLE);
//    set2dInt(matrix, 4, 6, OBSTACLE);

//    print2dIntArray(matrix, HEIGHT, WIDTH, 3);
//    printf("\n");

//    int length = lee(matrix, 2, 2, 7, 5);
//    print2dIntArray(matrix, HEIGHT, WIDTH, 3);
//    printf("\n");
//    printIntArray(pointX, length, 0);
//    printIntArray(pointY, length, 0);
    return 0;
}
