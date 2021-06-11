#include "c_graph.h"
#include <stdio.h>

int main(){
    Graph sample_graph = graph_init(1);
    graph_create(sample_graph);
    printf("DFS:\n");
    graph_DFS_traverse(sample_graph, 0, graph_visit);
    printf("BFS:\n");
    graph_BFS_traverse(sample_graph, 0, graph_visit);
    return 0;
}