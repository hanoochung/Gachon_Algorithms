#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int remain(int average, int num, int* list) {
    int remain = 0;
    for (int i = 0; i < num; i++) {
        if (list[i] > average) {
            remain += (list[i] - average);
        }
    }
    return remain;
}
int average(int num, int* list) {
    int sum = 0;
    int average;
    for (int i = 0; i < num; i++) {
        sum += list[i];
    }
    average = sum / num;
    if (average % 10 != 0)
        return ((average / 10) + 1) * 10;
    else
        return average;
    //if (average % 10 >= 5)  //반올림 5보다 클 때
    //    return ((average / 10) + 1) * 10;
    //else    //반올림 5보다 작을 때
    //    return (average / 10) * 10;
}
int main() {
    FILE* filePtr = fopen("input.txt", "r");    //file open
    if (filePtr == NULL) {                      //file open chack
        printf("input.txt File Open Error\n");
        return -1;
    }
    while (!feof(filePtr)) {
        int count;
        fscanf(filePtr, "%d", &count);
        if (!count)
            break;
        int* amount = (int*)malloc(sizeof(int) * count);
        for (int i = 0; i < count; i++) {
            fscanf(filePtr, "%d", &amount[i]);
        }
        int value = remain(average(count, amount), count, amount);
        printf("\\%d\n", value);
    }

    return 0;
}