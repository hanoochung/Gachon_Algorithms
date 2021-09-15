#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void flip(int* pancake,int last) {
    if(last < 30){
        int start = 0;
        while (start < last) {
            int temp = pancake[start];
            pancake[start] = pancake[last];
            pancake[last] = temp;
            start++;
            last--;
        }
    }
}
int findMax(int arr[],int length) {
    int maxth = 0;
    for (int i = 0; i < length; i++) {
        if (arr[maxth] < arr[i])
            maxth = i;
    }
    return maxth;
}

void sort(int* arr, int count) {
    for (int i = count; i > 0; i--) {
        int max = findMax(arr, i);
        if (max + 1 != i) {
            flip(arr, max);
            flip(arr, i - 1);
            if (max)
                printf("%d ", count - max);
            if(max!=i)
                printf("%d ", count - (i - 1));
        }
    }printf("0 \n");
}
int main() {
    FILE* filePtr = fopen("input.txt", "r");    //file open
    if (filePtr == NULL) {                      //file open chack
        printf("pancake.txt File Open Error\n");
        return -1;
    }

    int num = 0;
    char pancake_str1[60] = {NULL};
    while (!feof(filePtr)) {
        int* pancake = (int*)malloc(sizeof(int) * 30);  //define before sorting array
        int dia_count = 0;    //cout of diameter data

        fgets(pancake_str1, sizeof(pancake_str1), filePtr); //read one line data'
        if (pancake_str1[strlen(pancake_str1)-1] == '\n')
            pancake_str1[strlen(pancake_str1)-1] = '\0';
        puts(pancake_str1);
        char* ptr = strtok(pancake_str1, " ");  //split data by spacebar

        while (ptr != NULL) {   //count data and input data into integer array
            pancake[dia_count] = atoi(ptr); //change data string to integer
            ptr = strtok(NULL, " ");
            dia_count++;
        }
        sort(pancake, dia_count);   //sorting
        for (int i = 0; i < dia_count; i++) { //print sorted array
            printf("%d ", pancake[i]);
        }

        printf("\n\n");

        free(pancake);  //memoery free
    }
    fclose(filePtr);
    return 0;
}
