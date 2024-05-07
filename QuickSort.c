#include <stdio.h>

int a[100];
int n;

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void QuickSort(int low, int high){
    if(low<high){
        int loc = partition(low, high);
        QuickSort(low, loc-1);
        QuickSort(loc+1, high);
    }
}

int partition(int low, int high){
    int pivot = a[low];
    int start = low;
    int end = high;

    while(start<end){

        while(a[start]<=pivot){
            start++;
        }
        while(a[end]>pivot){
            end--;
        }
        if(start<end){
            swap(&a[start],&a[end]);
        }
    }
    swap(&a[low],&a[end]);
    return end;
}

int main() {
    int data;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        printf("Enter the data: ");
        scanf("%d", &data);
        a[i]=data;
    }

    QuickSort(0,n-1);

    for(int i=0; i<n; i++){
        printf("%d", a[i]);
    }

    return 0;
}
