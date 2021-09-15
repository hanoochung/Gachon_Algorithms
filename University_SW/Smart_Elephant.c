#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define NUM 1000
struct elephantData {
    int size;
    int IQ;
    int num;
};
struct elephantData elephant[NUM];
int counting[1000];
int line[1000];

int compare(const struct elephantData* e1, const struct elephantData* e2) {
    if (e1->size == e2->size)
        return e1->IQ - e2->IQ;
    return e1->size - e2->size;
}
void print(int max) {
    if (max == -1)
        return;
    print(line[max]);
    printf("%d\n", elephant[max].num);
}
void dynamic(int count) {
    int max = -1;
    int length = 0;
    for (int i = 0; i < count; i++) {
        printf("i = %d\tW:%d\tIQ:%d\n", i, elephant[i].size, elephant[i].IQ); //test
        counting[i] = 1;
        line[i] = -1;
        for (int j = 0; j < i; j++) {
            printf("\n\tj:%d\tW:%d\tIQ:%d\n\t\tcount: %d\tcounting[%d]: %d\t\tline[%d]: %d\n", j, elephant[j].size, elephant[j].IQ, i, i, counting[i], i, line[i]); //test
            if (elephant[i].size > elephant[j].size) {
                if (elephant[i].IQ < elephant[j].IQ && counting[i] < counting[j] + 1) {
                    counting[i] = counting[j] + 1;
                    line[i] = j;
                    if (max < counting[i]) {
                        max = counting[i];
                        length = i;
                    }
                    printf("\tChange: count: %d\tcounting[%d]: %d\t\tline[%d]: %d\n\n", i, i, counting[i], i, line[i]); //test

                }
            }
        }
        printf("\nFinal\ncounting[%d]: %d\t\tline[%d]: %d\n-----------------------------------------------------------------------------------------------\n", i, counting[i], i, line[i]);//test
    }
    printf("%d\n", length);
    print(max);
}

int main() {
    FILE* filePtr = fopen("Smart_Elephant.txt", "r");    //file open
    if (filePtr == NULL) {                      //file open chack
        printf("input.txt File Open Error\n");
        return -1;
    }
    int count = 0;;
    while (!feof(filePtr)) {
        fscanf(filePtr, "%d %d", &elephant[count].size, &elephant[count].IQ);
        elephant[count].num = count + 1;
        count++;
    }
    qsort(elephant, count, sizeof(struct elephantData), compare);
    dynamic(count);

    return 0;
}
