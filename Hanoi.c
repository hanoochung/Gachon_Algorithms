#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int hanoi(int input) {
    int string[50] = { 1,0 };
    int string_now = 1;
    int integer_count = 2;
    int result = 0;

    while (1) {
        for (int i = 0; i < string_now + 1; i++) {
            result = string[i] + integer_count;
            result = (int)sqrt(result);
            if (string[i] == 0) {
                string_now++;
                string[i] = integer_count;
                break;
            }
            else if (result * result == string[i] + integer_count) {
                string[i] = integer_count;
                break;
            }
        }
        if (string_now > input)
            break;
        integer_count++;
    }
    printf("ÃÖ´ë°ª: %d\n", integer_count - 1);

    return 0;
}
int main(void) {
    int time;
    int input;
    scanf("%d", &time);
    for (int i = 0; i < time; i++) {
        scanf("%d", &input);
        hanoi(input);
    }
    return 0;
}
