#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define T int
#define true 1 == 1
#define false 1 != 1

typedef int K;
typedef int htIndex;
typedef int boolean;

typedef struct OneLinkNode {
    int dat;
    struct OneLinkNode *next;
}OneLinkNode;

int htSize;

htIndex hash(T data) {
    return data % htSize;
}
boolean insertNode(OneLinkNode **table, K data) {
    // *p - óêàçàòåëü íà íîâûé óçåë, â êîòîðûé çàïèøåòñÿ ïåðåäàííûé êëþ÷
    // *p0 - óêàçàòåëü íà ñòàðóþ ãîëîâó ñïèñêà, â êîòîðûé áóäåò äîáàâëåí ýòîò íîâûé óçåë
    OneLinkNode *p, *p0;

    //c ïîìîùüþ õåø-ôóíêöèè ïîëó÷èì èíäåêñ õåø-òàáëèöû
    //â ñïèñîê ïî ýòîìó èíäåêñó áóäåò äîáàâëÿòüñÿ íîâûé óçåë
    htIndex bucket = hash(data);
    p = (OneLinkNode*)malloc(sizeof(OneLinkNode));
    if (p == NULL) {
        printf("Out of memory!\n");
        return false;
    }

    //Â ïåðåìåìåííóþ p0 ïîëîæèì óêàçàòåëü íà òåêóùóþ ãîëîâó ñïèñêà, êîòîðûé õðàíèòñÿ â õåø-òàáëèöå
    //ïî èíäåêñó, ðàññ÷èòàííîìó õåø-ôóíêöèåé
    p0 = table[bucket];

    //Â ñàìó òàáëèöó çàïèøåì óêàçàòåëü íà íîâûé óçåë, òåïåðü îí áóäåò ãîëîâîé ñïèñêà
    //åãî óêàçàòåëü next áóäåò ññûëàòüñÿ íà óçåë, êîòîðûé áûë ãîëîâîé äî ýòîãî
    //çàïèøåì êëþ÷ â íîâûé óçåë è âåðíåì èñòèíó
    table[bucket] = p;
    p->next = p0;
    p->dat = data;
    return true;
}

OneLinkNode *findNode(OneLinkNode **table, K data) {
    //îïðåäåëÿåì èíäåêñ õåø-òàáëèöû, â êîòîðîì íåîáõîäèìî èñêàòü.
    //Ïî êëþ÷ó. è ïðèñâàèâàåì óêàçàòåëü ïî ýòîìó èíäåêñó â ïåðåìåííóþ ð
    OneLinkNode *p = table[hash(data)];
    // èäåì ïî ñïèñêó, ãîëîâà êîòîðîãî íàõîäèòñÿ â ïåðåìåííîì ð,
    //è ñðàâíèâàåì ïåðåäàííûé êëþ÷ ñî çíà÷åíèÿìè, õðàíÿùèìèñÿ â óçëàõ ýòîãî ñïèñêà
    // Óñëîâèÿ âûõîäà èç ñïèñêà: ñïèñîê ïóñò (ôóíêöèÿ âîçâðàùàåò NULL) è âòîðîé ñëó÷àé,
    // êîãäà óçåë íàéäåí (òîãäà ôóíêöèÿ âåðíåò óêàçàòåëü íà ýòîò óçåë).
    while (p && !(p->dat == data))
        p = p->next;
    return p;

}

//Ôóíêöèÿ áóäåò óäàëÿòü óçëû èç ñïèñêîâ ïî êëþ÷ó data
void deleteNode(OneLinkNode **table, K data) {
    //÷òîáû óäàëèòü óçåë èç îäíîñâÿçíîãî ñïèñêà, íóæíû óêàçàòåëü íà 2 óçëà -
    // óçåë, êîòîðûé óäàëÿåì è óçåë, êîòîðûé ïåðåä íèì, äëÿ òîãî ÷òîáû
    //ïåðåïðèñâîèòü ññûëêè
    OneLinkNode *parent, *current;
    parent = NULL; // íóæíî, ÷òîáû â íåé ãàðàíòèðîâàíî íå áûëî íèêàêèõ çíà÷åíèé, íàõîäÿùèõñÿ â ïàìÿòè
    //èñïîëüçóÿ õåø-ôóíêöèþ, îïðåäåëèì èíäåêñ òàáëèöû ïî êëþ÷ó è çàïèøåì â ïåðåìåííóþ
    // current óêàçàòåëü íà ñïèñîê , õðàíÿùèéñÿ â òàáëèöå ïî ýòîìó èíäåêñó
    htIndex bucket = hash(data);
    current = table[bucket];
    // áåæèì ïî ñïèñêó èùåì óçåë, çíà÷åíèå â êîòîðîì ñîâïàäåò ñ ïåðåäàííûì êëþ÷îì
    // è çàîäíî â ïåðåìåííîé parent ïîëó÷èì óêàçàòåëü íà óçåë ïåðåä óäàëÿåìûì
    // current áóäåò óäàëåí
    while (current && !(current->dat == data)) {
        parent = current;
        current = current->next;
    }
    //åñëè ìû âûøëè èç ñïèñêà, ïîòîìó ÷òî ñïèñîê çàêîí÷èëñÿ, current = NULL, òî
    //íàì íåîáõîäèìî âûéòè èç ôóíêöèè
    if (!current) {
        printf("Value not found.\n");
        return;
    }
    // åñëè óçåë íàéäåí, òî îí ìîæåò ÿâëÿòüñÿ ãîëîâîé ñïèñêà èëè íå ÿâëÿòüñÿ
    if (parent)
        parent->next = current->next;  // â óêàçàòåëü íåêñ çàïèøåì íåêñò óäàëÿåìîãî óçëà
    else
        // åñëè parent - ãîëîâà ñïèñêà, òî â parent õðàíèòñÿ NULL
        //â óêàçàòåëü íà ãîëîâó ñïèñêà çàïèøåòñÿ next óäàëÿåìîãî óçëà
        table[bucket] = current->next;
    free(current); // íå ñòàíåì îñòàâëÿòü â ïàìÿòè áîëòàþùèéñÿ óçåë. Óäàëèì è åãî
}
void printTable(OneLinkNode **table, int size) {
    OneLinkNode *p;
    for (int i = 0; i < size; ++i) {
        p = table[i];
        while (p) {
            printf("%5d", p->dat);
            p = p->next;
        }
        printf("\n");
    }
    printf("\n");
}
void fillIntRandom(int *arr, int size,int border) {
    for (int i = 0; i < size; ++i) {
        *(arr + i) = rand() % border;
    }
}
void printOneLinkIntNode(OneLinkNode *n) {
    if (n == NULL) {
        printf("[]");
        return;
    }
    printf("[%d]", n->dat);
}
htIndex hashS(char* word) {
    int sum = 0;
    for (int i = 0; i < strlen(word); ++i) {
        printf("%d ", word[i]);
        sum += word[i];
    }
    return sum;
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
void clearIntArray(int* arr, const int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = 0;
    }
}
int profitCalculation(int *deadline, int *task, const int TASKS, const int DAYS) {
    int used[DAYS];
    int arr[DAYS];

    clearIntArray(used, DAYS);
    clearIntArray(arr, DAYS);

    int sum = 0;
    for (int i = 0; i < TASKS; ++i) {
        int k = deadline[i];
        while (k >= 1 && used[k] == 1) {
            k--;
        }
        if (k == 0) continue;

        used[k] = 1;
        arr[k] = task[i];
        sum += task[i];
    }
    printIntArray(arr, DAYS, 0);
    return sum;
}
void sortIntInserts(int* array, int size) {
    int temp, pos;
    for (int i = 1; i < size; ++i) {
        temp = array[i];
        pos = i - 1;
        while (pos >= 0 && array[pos] < temp) {
            array[pos + 1] = array[pos];
            pos--;
        }
        array[pos + 1] = temp;
    }
}

int profitCalculationCoin(int *coin, const int SUM) {

    int* arr = (int)malloc(sizeof (int));
    int s = 0;
    int i = 0;
    int n = 0;
    sortIntInserts(coin, 5);
    printIntArray(coin, 5, 2);
    while (s <= SUM && i < 5) {
        s += coin[i];
        printf("%d ",s);
        n++;
        if ((s + coin[i]) > SUM)
            i++;
    }
    return n;
}
int main()
{
//    htSize = 8;
//    int *arr;
//    //çàïîëíèì õåø-òàáëèöó
//    const int SZ = 20;
//    arr = (int*)malloc(sizeof (int) * SZ);
//    fillIntRandom(arr, SZ, 100);

//    // ñîçäàäèì õåø-òàáëèöó, âûäåëèâ ó÷àñòîê ïàìÿòè è ïðèñâîèâ óêàçàòåëü íà íåå ïåðåìåííîé hashTable
//    OneLinkNode **hashTable = (OneLinkNode*)calloc(htSize, sizeof(OneLinkNode*));
//    //çàïîëíèì çíà÷åíèÿìè èç ìàñèâà arr
//    for (int i = 0; i < SZ; ++i) {
//        insertNode(hashTable, arr[i]);
//    }
//    printTable(hashTable, htSize);

//    printOneLinkIntNode(findNode(hashTable, 40));
//    printOneLinkIntNode(findNode(hashTable, 41));

//    for (int i = 0; i < SZ / 2; ++i) {
//        deleteNode(hashTable, arr[i]);
//    }
//    printTable(hashTable, htSize);

    //--1--

    //char w[20] = "hello";
    //printf("%d \n", hashS(w));

    //--2--
    const int SUM = 98;
    int coin[] = {50, 10, 5, 2, 1};

    printf("\n%d\n", profitCalculationCoin(coin, SUM));

    return 0;
}
