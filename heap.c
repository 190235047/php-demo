#最小堆
#include <stdio.h>
int a[] = {0,0,0,0,0,0,0,0,0,0,0};
int b[] = {6,7,8,9,12,45,2,1,6,8,67,34,18,20,11,5};
int heap(int num, int size) {
        if (num <= a[1]) return -1;
        int i = 1;
        int j, tmp;
        a[i]  = num;
        //printf("%d\n", num);
        while(i * 2 <= size) {
                j = i * 2;
                if (a[j] > a[j + 1] && j < size) j++;
                if (a[i] > a[j]) {printf("i:%d, j:%d, a[i]:%d\n", i, j, a[i]);
                        tmp  = a[i];
                        a[i] = a[j];
                        a[j] = tmp;
                        i = j;
                } else {
                        break;
                }

        }
        return 0;
}
int main(){
        //int a[] = {0,0,0,0,0,0,0,0,0,0};
        //int b[] = {6,7,8,9,12,45,2,1,6,8,67,34,18,20,11,5};
        int i;
        for (i = 1; i < 16; i++) {
                heap(b[i], 10);
        }
        //a[1] = 11;
        for (i = 1; i <= 10; i++) {
                printf("%d ", a[i]);
        }
        printf("\n");
}
