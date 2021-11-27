#include <stdio.h>
#include <stdlib.h>
//#include <math.h>

#define true 1 == 1
#define false 1 != 1
typedef int boolean;

typedef struct Node {
    int key;
    struct Node *left;
    struct Node *right;
} BinTreeIntNode;

BinTreeIntNode* treeInsert(BinTreeIntNode *t, int data) {
    BinTreeIntNode *newNode;
    newNode = (BinTreeIntNode*) malloc(sizeof(BinTreeIntNode));
    newNode->key = data;
    newNode->left = NULL;
    newNode->right = NULL;
    BinTreeIntNode *current = t;
    BinTreeIntNode *parent = t;
    if (t == NULL) {
        t = newNode;
    } else {
        while (current->key != data) {
            parent = current;
            if (current->key > data) {
                current = current->left;
                if (current == NULL) {
                    parent->left = newNode;
                    return t;
                }
            } else {
                current = current->right;
                if (current == NULL) {
                    parent->right = newNode;
                    return t;
                }
            }
        }
    }
    return t;
}

BinTreeIntNode* treeInsertNew(BinTreeIntNode *t, int data) {
    BinTreeIntNode *newNode;
    newNode = (BinTreeIntNode*) malloc(sizeof(BinTreeIntNode));
    newNode->key = data;
    newNode->left = NULL;
    newNode->right = NULL;
    BinTreeIntNode *current = t;
    BinTreeIntNode *parent = t;
    if (t == NULL) {
        t = newNode;
    } else {
        while (current->key != data) {
            parent = current;
            if (current->key > data) {
                current = current->left;
                if (current == NULL) {
                    parent->left = newNode;
                    return t;
                }
            } else {
                current = current->right;
                if (current == NULL) {
                    parent->right = newNode;
                    return t;
                }
            }
        }
    }
    return t;
}

void printBinTree(BinTreeIntNode *root) {
    if (root) {
        printf("%d", root->key);
        if (root->left || root->right) {
            printf("(");
            if (root->left)
                printBinTree(root->left);
            else
                printf("NULL");
            printf(",");
            if (root->right)
                printBinTree(root->right);
            else
                printf("NULL");
            printf(")");
        }
    }
}
BinTreeIntNode* getSuccessor(BinTreeIntNode *node) {
    BinTreeIntNode *current = node->right;
    BinTreeIntNode *parent = node;
    BinTreeIntNode *s = node;

    while (current != NULL) {
        parent = s;
        s = current;
        current = current->left;
    }
    if (s != node->right) {
        parent->left = s->right;
        s->right = node->right;
    }
    return s;
}
boolean treeNodeDelete(BinTreeIntNode *root, int key) {
    BinTreeIntNode *current = root;
    BinTreeIntNode *parent = root;
    boolean isLeftChild = true;

    while (current->key != key) {
        parent = current;
        if (key < current->key) {
            current = current->left;
            isLeftChild = true;
        } else {
            current = current->right;
            isLeftChild = false;
        }
        if (current == NULL)
            return false;
    }

    if (current->left == NULL && current->right == NULL) {
        if (current == root)
            root = NULL;
        else if (isLeftChild)
            parent->left = NULL;
        else
            parent->right = NULL;
    }
    else if (current->right == NULL) {
        if (isLeftChild)
            parent->left = current->left;
        else
            parent->right = current->left;
    }
    else if (current->left == NULL) {
        if (isLeftChild)
            parent->left = current->right;
        else
            parent->right = current->right;
    }
    else {
        BinTreeIntNode *successor = getSuccessor(current);
        if (current == root)
            root = successor;
        else if (isLeftChild)
            parent->left = successor;
        else
            parent->right = successor;
        successor->left = current->left;
    }
    return true;
}
int max(int a, int b)
{
    return (a >= b) ? a : b;
}
int height(BinTreeIntNode* t)
{
    if (t == NULL)
        return 0;
    return 1 + max(height(t->left), height(t->right));

}
boolean checkTreeBalance(BinTreeIntNode *root) {
    int lh;
    int rh;

    if (root == NULL) {
        return true;
    }

    lh = height(root->left);
    rh = height(root->right);

    BinTreeIntNode *current = root;

    if (abs(lh - rh) <= 1 && checkTreeBalance(root->left)
            && checkTreeBalance(root->right)) {
        return 1;
    }

    return 0;
}
boolean binSearch(BinTreeIntNode *root, int value) {
    if (root == NULL)
        return false;
    if (root->key == value)
        return true;

    BinTreeIntNode *current = root;
    while (current->key != value) {
        if (value < current->key)
            current = current->left;
        else
            current = current->right;

        if (current == NULL)
            return false;
    }
}
boolean binSearchRec(BinTreeIntNode *root, int value) {
    if (root == NULL)
        return false;

    if (root->key == value)
        return true;
    else if (root->key > value)
        binSearchRec(root->left, value);
    else if (root->key < value)
        binSearchRec(root->right, value);
}

int main()
{
//-----1-----

    BinTreeIntNode *tree = treeInsert(tree, 10);
    treeInsert(tree, 8);
    treeInsert(tree, 19);
    treeInsert(tree, 5);
    treeInsert(tree, 9);
    treeInsert(tree, 16);
    treeInsert(tree, 21);
    printBinTree(tree);
    printf(" \n");
    printf("Balanced tree %s\n", checkTreeBalance(tree) ? "true" : "false");

//-----4-----

    printf("15 in tree = %s \n", binSearchRec(tree, 15) ? "true" : "false");
    printf("8 in tree = %s \n", binSearchRec(tree, 8) ? "true" : "false");

//-----2-----

//    srand(time(0));
//    const int N = 5;
//    const int SZ = 10;
//    int k = 0;

//    BinTreeIntNode *tr[N];
//    for (int i = 0; i < N; i++) {
//        tr[i] = (BinTreeIntNode*) malloc(sizeof(BinTreeIntNode));
//        tr[i]->key = 1 + rand() % 100;
//        tr[i]->left = 0;
//        tr[i]->right = 0;
//    }
//    for (int i = 0; i < N; i++) {
//        for (int j = 1; j < SZ; j++) {
//            treeInsert(tr[i], 1 + rand() % 100);
//        }

////-----3-----

//        if (checkTreeBalance(tr[i])) k++;
//        printBinTree(tr[i]);
//        printf("\n");
//    }
//    printf("Balanced trees are %d %% \n", k * 100 / SZ);

    return 0;
}
