#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    int N, M;//N ���ڰ���, M ��������
    int arr[5000];//�� ����
    int start = 0, end = 0;//start,end ���� �ּ��ִ밪
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] > end) {
            end = arr[i];
        }
    }

    printf("start: %d\tend: %d\n", start, end);

    while (start <= end) {
        int mid = (start + end) / 2;
        int section_max = 0, section_min = 10001, section_count = 1;

        for (int i = 0; i < N; i++) {
            if (section_max < arr[i])
                section_max = arr[i];
            if (section_min > arr[i])
                section_min = arr[i];
            if (section_max - section_min > mid) { //���� ������ �ϳ��� section���� ���
                section_count++;  //section �� �߰�
                section_max = arr[i];
                section_min = arr[i];
            }
        }
        if (section_count > M)
            start = mid + 1;
        else
            end = mid - 1;
        printf("mid:%d\tstart:%d \tend:%d\tsection_count:%d\n", mid, start, end, section_count);
    }
    printf("%d", start);
    return 0;
}