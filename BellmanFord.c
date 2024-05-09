# include <stdio.h>
// het
int map[8][8]={
    {0,6,5,5,0,0,0},
    {0,0,0,0,-1,0,0},
    {0,-2,0,0,1,0,0},
    {0,0,-2,0,0,-1,0},
    {0,0,0,0,0,0,3},
    {0,0,0,0,0,0,3},
    {0,0,0,0,0,0,0},
};

int n = 7;
int parent[10];
int distance[10];
int negCycle = 0;
int source = 0;

void InitializeSource(){
    int i;
    for(i=0;i<n;i++){
        distance[i] = 99999;
        parent[i] = -1;
    }
    distance[source] = 0;
}

void relax(int u, int v){
    if(distance[v] > distance[u]+map[u][v]){
        distance[v] = distance[u]+map[u][v];
        parent[v] = u;
    }
}

void BellmanFord(){
    InitializeSource();

    for(int k=0; k<n; k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(map[i][j]!=0){
                    relax(i,j);
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(map[i,j]!=0 && distance[j]>distance[i]+map[i][j]){
                negCycle = 1;
            }
        }
    }
    negCycle = 0;
}

int main(){
    BellmanFord();
    if(negCycle == 1){
        printf("Negative Cycle Detected!");
    }
    else{
        printf("Distance: \n\n");
        for(int i=0;i<n;i++){
            printf("%d\n", distance[i]);
        }
        printf("\nParents: \n\n");
        for(int i=0;i<n;i++){
            printf("%d\n", parent[i]+1);
        }
    }
    return 0;
}
