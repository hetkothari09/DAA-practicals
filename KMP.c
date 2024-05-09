#include <stdio.h>
#include <stdlib.h>

char Text[100];
char Pattern[100];
int pie[100];


void Compute_prefix(){
    int m = strlen(Pattern);
    int k = 0;
    pie[0] = 0;

    for(int i=1; i<m; i++){
        while(k>0 && Pattern[k]!=Pattern[i]){
            k = pie[i];
        }
        if(Pattern[k]==Pattern[i]){
            k++;
        }
        pie[i] = k;
    }
}

void KMP(){
    int m = strlen(Pattern);
    int n = strlen(Text);
    int q = 0;

    for(int i=0; i<n; i++){
        while(q>0 && Pattern[q]!=Text[i]){
            q = pie[q-1];
        }
        while(Pattern[q]==Text[i]){
            q++;
        }
        if(q==m){
            printf("Pattern Found at shift : %d", i-m+1);
            q = pie[q-1];
        }
    }
}


int main()
{
    printf("Enter the text: ");
    scanf("%s", Text);
    printf("Enter the pattern to be checked: ");
    scanf("%s", Pattern);

    Compute_prefix();
    KMP();
    return 0;
}
