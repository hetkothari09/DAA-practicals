#include <stdio.h>
#include <stdlib.h>

int c[20][20];
char b[20][20];
char x[20];
char y[20];
int m;
int n;

void print_LCS(int i, int j){
    if(i==0||j==0){
        return;
    }
    if(b[i][j]=='d'){
        printf("%c", x[i-1]);
        print_LCS(i-1, j-1);
    }
    else if(b[i][j]=='u'){
        print_LCS(i-1, j);
    }
    else{
        print_LCS(i, j-1);
    }
}

void LCS(){
    m = strlen(x);
    n = strlen(y);

    for(int i=0; i<=m; i++){
        c[i][0] = 0;
    }
    for(int i=0; i<=n; i++){
        c[0][i] = 0;
    }

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(x[i-1]==y[j-1]){
                c[i][j] = c[i-1][j-1]+1;
                b[i][j] = 'd';
            }
            else if(c[i-1][j]>=c[i][j-1]){
                c[i][j]==c[i-1][j];
                b[i][j]=='u';
            }
            else{
                c[i][j]==c[i][j-1];
                b[i][j]=='l';
            }
        }
    }
}


int main()
{
    printf("Enter the first sequence: ");
    scanf("%s", x);
    printf("Enter the second sequence: ");
    scanf("%s", y);

    printf("The LCS is: \n");
    LCS();
    print_LCS(m,n);
    return 0;
}
