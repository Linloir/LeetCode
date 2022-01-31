#include "c_graph.h"
#include <stdio.h>

/*
算法核心：
迪杰斯特拉算法采用BFS广度优先搜索，在不使用堆优化时间复杂度的情况下，可以使用标准的BFS算法进行遍历
visit函数功能为更新节点距离
*/

int distance[GRAPH_MAX];
int path[GRAPH_MAX];

int dij_visit(Graph g, int vexID){
    for (int i = graph_vex_first_adj(g, vexID); i >= 0; i = graph_vex_next_adj(g, vexID, i)){
        int w = graph_arc_weight(g, vexID, i);
        if(distance[vexID] + w < distance[i]){
            distance[i] = distance[vexID] + w;
            path[i] = vexID;
        }
    }
}

void dij_print(int vexID){
    if(path[vexID] >= 0){
        dij_print(path[vexID]);
    }
    printf("%d->", vexID);
}

void Dijkstra(Graph g, int s_vexID, int e_vexID){
    for (int i = 0; i < GRAPH_MAX; i++){
        distance[i] = 65535;
        path[i] = -1;
    }
    distance[s_vexID] = 0;
    graph_BFS_traverse(g, s_vexID, dij_visit);
    printf("Path:\n", e_vexID);
    dij_print(path[e_vexID]);
    printf("%d\nTotal length: %d\n", e_vexID, distance[e_vexID]);
}

int main(){
    Graph sample_graph = graph_init(1);
    graph_create(sample_graph);
    int s, e;
    printf("Insert two vertices:\n");
    scanf("%d %d", &s, &e);
    Dijkstra(sample_graph, s, e);
}