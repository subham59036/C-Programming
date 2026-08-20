#include <stdio.h>

int linearSearch1Pointer(int arr[], int size, int target) {
    for(int i=0; i <= size; i++) {
        if (arr[i] == target) return i;
    }
    return -1;
}

int linearSearch2Pointer(int arr[], int size, int target) {
    for(int i=0, j=size; i < j; i++, j--) {
        if (arr[i] == target) return i;
        if (arr[j] == target) return j;
    }
    return -1;
}

void main() {
    int arr[] = {0,1,2,3,4,5,6,7,8,9};
    int size = (sizeof(arr)/sizeof(arr[0])) - 1;
    int target = 3;
    printf("%d\n", linearSearch1Pointer(arr, size, target));
    printf("%d\n", linearSearch2Pointer(arr, size, target));
}