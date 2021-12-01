#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef int htIndex;

int htSize;

htIndex hashS(char* word) {
    int sum = 0;
    for (int i = 0; i < strlen(word); ++i) {
        sum += word[i];
    }
    return sum;
}
void printCharArray(char* array, int size) {


    for (int i = 0; i < size; ++i) {
        printf("%s", &array[i]);

    }
    printf("\n");
}
void clearCharArray(char* arr, const int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = 0;
    }
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

char* encryptCaesar(char *text, const int key) {
    char *cipher = (char*)malloc(sizeof (char));


    for (int i = 0; i < (int)strlen(text); i++) {
        if (text[i] >= 97 && text[i] <= 122 && key <= 26) {
            if (text[i] + key > 122)
                cipher[i] = 96 + (text[i] + key - 122);
            else
                cipher[i] = text[i] + key;
        }

        else {
            printf("Wrong data!\n"
                   "Enter only lower case.\n"
                   "Key should be less than 26 and more 0.\n");
            break;
        }
        printf("%c", cipher[i]);
    }
    printf("\n");
    return cipher;

}
char* decryptCaesar(char *cipher, const int key) {
    char *text = (char*)malloc(sizeof (char));
    for (int i = 0; i < (int)strlen(cipher); ++i) {
        if (cipher[i] - key < 97)
            text[i] = 123 + (cipher[i] - key - 97);
        else
            text[i] = cipher[i] - key;
        printf("%c", text[i]);
    }
    printf("\n");
    return text;
}

char* transpCipher(char *text, int col){
    int row = (int)strlen(text) % col ? (int)strlen(text) / col + 1 : (int)strlen(text) / col;

    char **matrix;
    matrix = (char**) calloc(sizeof(char*), row);
    for (int i = 0; i < row; ++i) {
        *(matrix + i) = (char*) calloc(sizeof(char), col);
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++){
            *((*(matrix + i)) + j) = *(text + j + i * col);
            if ((i * col + j ) >= (int)strlen(text)) {

                *((*(matrix + i)) + j) = 'x';

            }
            printf("%c ", *((*(matrix + i)) + j));
        }
        printf("\n");
    }
    printf("\n");
    char *cipher = (char*)malloc(sizeof(char));
    for (int j = 0; j < col; j++) {
        for (int i = 0; i < row; i++){
            *(cipher + i + j * row) = *((*(matrix + i)) + j);
            printf("%c", *(cipher + i + j * row));
        }
    }
    free(matrix);
return cipher;
}
char* transpDeCipher(char *cipher, int col) {
    int row = (int)strlen(cipher) / col;

    char **matrix;
    matrix = (char**) calloc(sizeof(char*), row);
    for (int i = 0; i < row; ++i) {
        *(matrix + i) = (char*) calloc(sizeof(char), col);
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++){
            *((*(matrix + i)) + j) = *(cipher + row * j + i);
            printf("%c ", *((*(matrix + i)) + j));
        }
        printf("\n");
    }
    printf("\n");
    char *text = (char*)malloc(sizeof(char));

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++){
            *(text + i + j * row) = *((*(matrix + i)) + j);
            printf("%c", *(text + i + j * row));
        }
    }
    printf("\n");
    free(matrix);
    return text;
}

int main()
{
    //--1--

    char t[100] = "theonesecretphrase";
    const int k = 10;

    for (int i = 0; i < (int)strlen(t); ++i) {
        printf("%c", t[i]);
    }
    printf("\n");
    char *code = encryptCaesar(t, k);
    decryptCaesar(code, k);
    printf("\n");

    //--2--

    char w[100] = "The one secret phrase";
    const int N = 3;
    char *c = (char*)malloc(sizeof(char));

    for (int i = 0; i < (int)strlen(w); ++i) {
        printf("%c", w[i]);
    }
    printf("\n");
    c = transpCipher(w, N);
    printf("\n");
    transpDeCipher(c, N);
    free(c);

    return 0;
}
