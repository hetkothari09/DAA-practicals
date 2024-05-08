#include <stdio.h>
#include <stdlib.h>

void bubblesortFinishTimes(int start[], int finish[], int n){
    int i, j;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(finish[j]>finish[j+1]){
                int temp = finish[j];
                finish[j]=finish[j+1];
                finish[j+1]=temp;

                temp = start[j];
                start[j] = start[j+1];
                start[j+1] = temp;
            }
        }
    }
}


void ActivitySelection(int start[], int finish[], int n, int maxFinishTime){
    int i, j;
    int count = 0;
    int currentFinishTime = 0;
    bubblesortFinishTimes(start, finish, n);
    printf("Activity selected: \n");
    for(i=0;i<n;i++){
        if(start[i]>=currentFinishTime){
            printf("Activity : %d (Start: %d) (Finish: %d)\n", i+1, start[i], finish[i]);
            currentFinishTime = finish[i];
            count++;
        }
    }

    printf("Maximum number of activities that can be selected : %d\n", count);
}

int main()
{
    int start[] = {1,3,0,5,3,6,7,3,4,1,11};
    int finish[] = {5,3,4,6,7,11,10,12,14,15,16};
    int n = sizeof(start)/sizeof(start[0]);

    ActivitySelection(start,finish,n,16);
    return 0;
}
