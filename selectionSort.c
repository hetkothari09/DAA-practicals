#include <stdio.h>
#include <stdlib.h>

int a[100];
int n;

void SelectionSort(){
    int imin;
    int temp;
    int i;
    int j;

    for(i=0;i<n;i++){
        imin = i;

        for(j=i+1;j<n;j++){

            if(a[j]<a[imin]){
                imin = j;
            }
        }

        temp = a[imin];
        a[imin] = a[i];
        a[i] = temp;
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
        a[i] = data;
    }

    SelectionSort();

    for(int i=0; i<n; i++){
        printf("%d", a[i]);
    }

    return 0;
}
