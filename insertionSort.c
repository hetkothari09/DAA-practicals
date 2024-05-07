#include <stdio.h>
#include <stdlib.h>

int a[100];
int n;

void InsertionSort(){
    int temp;
    for(int i=0; i<n; i++){
        temp = a[i];
        int j = i-1;

        while(j>=0 && a[j]>temp){
            a[j+1] = a[j];
            j--;
        }

        a[j+1] = temp;
    }
}



int main()
{
    int data;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        printf("Enter the data: ");
        scanf("%d", &data);
        a[i]=data;
    }

    InsertionSort();

    for(int i=0; i<n; i++){
        printf("%d", a[i]);
    }

    return 0;
}
