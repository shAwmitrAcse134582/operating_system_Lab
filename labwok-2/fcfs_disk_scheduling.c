#include<stdio.h>
#include<stdlib.h>

#define MAX 10000

int csc(int array[], int head, int start, int end, int step) {
    int sc = 0;
    int distance, ct;

    for (int i = start; i != end; i += step) {
        ct = array[i];
        distance = abs(ct - head);
        sc += distance;
        head = ct;
    }

    return sc;
}

void FCFS(int array[], int head, int size) {
    printf("Total seek operations in FCFS = %d\n", csc(array, head, 0, size, 1));
}

int main() {
    int rs[] = {176, 79, 34, 60, 92, 11, 41, 114};
    int n = sizeof(rs) / sizeof(rs[0]);
    int ihp = 50;


    FCFS(rs ,ihp ,n);

   return 0;
}
