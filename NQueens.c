#include <stdio.h>
#include <stdlib.h>

int x[10];
int n;

int place(int k, int j){
    int i;
    for(i=0;i<k;i++){
        if(x[i]==j || abs(x[i]-j)==abs(i-k)){
            return 0;
        }
    }
    return 1;
}

void NQueens(int k, int n){
    int j;
    for(j=0;j<n;j++){
        if(place(k,j)==1){
            x[k]=j;

            if(k+1==n){
                for(int i=0;i<n;i++){
                    printf("%d", x[i]+1);
                }
                printf("\n");
            }
            else{
                NQueens(k+1,n);
            }
        }
    }
}


void main()
{
    printf("Enter the size of the chessboard:");
    scanf("%d",&n);
    NQueens(0,n);
}
