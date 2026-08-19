#include <stdio.h>

int binarySearch(int arr[], int size, int target) {
      int left = 0;
      int right = size;
      if (left == right) {
            return 0;
      }
      while(left <= right) {
            int mid = left + (right-left)/2;
            if(target > arr[mid]){
                  left = mid+1;
            }
            else if(target < arr[mid]){
                  right = mid-1;
            }
            else{
                  return mid;
            }
      }
      return -1;
}

void main() {
      int arr[] = {0,1,2,3,4,5,6,7,8,9};
      int target = 0;
      int size = (int)(sizeof(arr) / sizeof(arr[0])) - 1;
      printf("%d\n", binarySearch(arr, size, target));
}