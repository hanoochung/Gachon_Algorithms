// 201835526 Á¤Çö¿ì
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct sentence {
    char x[10001];
    char y[101];
};

void dynamic(struct sentence* sample, int lengx, int lengy) {
    printf("%s\n", sample->x); //test
    printf("%s\n", sample->y); //test
    int** sheet = malloc(sizeof(int) * lengy + 1);  //Y
    for (int i = 0; i < lengy + 1; i++) {
        sheet[i] = (int*)malloc(sizeof(int) * lengx + 1);   //X
    }
    for (int i = 0; i < lengy + 1; i++) { //Y
        sheet[i][0] = 0;
    }
    for (int j = 0; j < lengx + 1; j++) {   //X
        sheet[0][j] = 1;
    }
    for (int i = 1; i < lengy + 1; i++) {   //Y
        for (int j = 1; j < lengx + 1; j++) {   //X
            if (sample->x[j - 1] == sample->y[i - 1])
                sheet[i][j] = sheet[i - 1][j - 1] + sheet[i][j - 1];
            else
                sheet[i][j] = sheet[i][j - 1];
            printf("[(%d, %d)(%c, %c) = %d]  ", i, j, sample->x[j - 1], sample->y[i - 1], sheet[i][j]); //test
        }
        printf("\n"); //test
    }
    printf("%d\n\n", sheet[lengy][lengx]); //print count of able matching sentence
}

int main() {
    FILE* filePtr = fopen("input.txt", "r");    //file open
    if (filePtr == NULL) {                      //file open chack
        printf("input.txt File Open Error\n");
        return -1;
    }
    int count = 0;
    fscanf(filePtr, "%d", &count);
    while (0 < count) {
        struct sentence* sample = malloc(sizeof(struct sentence));
        fscanf(filePtr, "%s", &sample->x);
        fscanf(filePtr, "%s", &sample->y);
        dynamic(sample, strlen(sample->x), strlen(sample->y));
        free(sample);
        count--;
    }
    fclose(filePtr);
    return 0;
}