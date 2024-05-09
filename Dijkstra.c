#include <stdio.h>
#include <stdlib.h>

int map[100][100]={
    {0,7,9,0,0,4},
    {7,0,10,15,0,0},
    {9,10,0,11,0,2},
    {0,15,11,0,6,0},
    {0,0,0,6,0,9},
    {4,0,2,0,9,0},
};

int visited[100] = {0,0,0,0,0,0};
int parent[100];
int distance[100];
int n = 6;
int source = 0;

int extract_min(){
    int temp = 10000;
    int tempi = 0;
    int i;
    for(i=0;i<n;i++){
        if(distance[i]<temp && visited[i]!=1){
            temp = distance[i];
            tempi = i;
        }
    }
    return tempi;
}

void InitializeSingleSource(){
    int j;
    for(j=0;j<n;j++){
        distance[j] = 99999;
        parent[j] = -1;
    }
    distance[source] = 0;
}

void relax(int u, int v){
    int i;
    for(i=0; i<n; i++){
        if(distance[v]>distance[u]+map[u][v]){
            distance[v]= distance[u]+map[u][v];
            parent[v] = u;
        }
    }
}

void Dijkstra(){
    InitializeSingleSource();
    int i;
    int j;
    for(i=0;i<n;i++){
        int U = extract_min();
        for(j=0;j<n;j++){
            if(map[U][j]!=0 && visited[j]!=1){
                relax(U,j);
            }
        }
        visited[U] = 1;
    }
}


int main()
{
    Dijkstra();

    printf("Distance: \n\n");
    for(int i=0; i<n; i++){
        printf("%d\n", distance[i]);
    }

    printf("\nParent: \n\n");
    for(int i=0; i<n; i++){
        printf("%d\n", parent[i]+1);
    }

    return 0;
}
