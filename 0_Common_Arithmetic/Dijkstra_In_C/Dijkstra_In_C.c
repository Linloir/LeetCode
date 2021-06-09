#include <stdio.h>
#define MAX_MAP 999
#define MAX 65535

int Dijkstra(int, int, int, int*, int **);

int main(){
    //read a map
    int vertex_1 = 0, vertex_2 = 0;
    int **map = (int **)malloc(sizeof(int *) * MAX_MAP);
    for (int i = 0; i < MAX_MAP; i++){
        map[i] = (int *)malloc(sizeof(int) * MAX_MAP);
        for (int j = 0; j < MAX_MAP; j++){
            map[i][j] = MAX;
        }
    }
    do{
        scanf("%d %d", &vertex_1, &vertex_2);
        if(vertex_1 >= 0 && vertex_2 >= 0){
            scanf("%d", &map[vertex_1][vertex_2]);
        }
    } while (vertex_1 != -1 || vertex_2 != -1);

    //read two points
    int start, end;
    scanf("%d %d", &start, &end);

    //dijkstra
    int min_lenth = Dijkstra(start, end, 0, NULL, map);
}

int Dijkstra(int start, int end, int n, int* dij, int** map){
    if(dij == NULL){
        dij = (int *)malloc(sizeof(int) * n);
        dij[0] = start;
    }

    int min = MAX;
    for (int i = 0; i <= n; i++){
        for (int j = 0; j < MAX_MAP; j++){
            if(map[dij[i]][j] < min){
                min = map[dij[i][j]];
                dij[n + 1] = j;
            }
        }
    }

    
}