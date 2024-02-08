#include <stdio.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void selectionSort(int arr[], int n) {
    int i, j, minIndex;

    for (i = 0; i < n - 1; i++) {
        // Assume the current index is the minimum
        minIndex = i;

        // Find the index of the minimum element in the unsorted part
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the first element
        swap(arr, i, minIndex);
    }
}



int main() {
    int arr[10000],n=10000;
    clock_t t1,t2,t3;
    int i,j,num;
    j=1;
    //Worst case
    /*
    for(i=n;i>=1;i--)
    {
        arr[j]=i;
        j++;
    }
    
    //best case
    for(i=1;i<=n;i++)
    {
        arr[i]=i; 
    }
*/
    //Average case
    
    for(i=1;i<=n;i++)
    {
        num=rand();
        arr[i]=num; 
    }
    
    t1 = clock();
    selectionSort(arr, n);
    t2= clock();
    t3=t2-t1;
    
    printf("Time taken to sort: %ld ",t3);
    return 0;

}