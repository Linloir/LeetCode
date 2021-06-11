#include "c_graph.h"
#include "c_queue.h"
#include <stdio.h>
#include <stdlib.h>

/*
In this impletation, crossed-linked-list ADT is used to conserve the graph
*/

struct VexNode{
    int info;
    ArcNode *first_arc;
};

struct ArcNode{
    int weight;
    int next_vexID;
    ArcNode *next_arc;  //Next adjcent arc of the source vertex
};

struct Graph{
    int vex_num, arc_num;
    int kind;
    VexNode *vex_list;
};

Graph graph_init(int kind){
    //Initiate graph
    Graph new_graph = (Graph)malloc(sizeof(struct Graph));
    new_graph->vex_num = 0;
    new_graph->arc_num = 0;
    new_graph->vex_list = (VexNode *)malloc(sizeof(VexNode) * MAX);
    for (int i = 0; i < MAX; i++){
        new_graph->vex_list[i].info = NOT_ASSIGNED;
        new_graph->vex_list[i].first_arc = NULL;
    }
    return new_graph;
}

void graph_build(Graph g, int* vex_list, int* arc_list){
    int iterator;
    //Insert vertices
    iterator = 1;
    while(iterator <= vex_list[0])
        graph_insert_vex(g, vex_list[iterator++]);
    
    //Insert arcs
    iterator = 1;
    while(iterator <= arc_list[0] * 3){
        graph_insert_arc(g, arc_list[iterator], arc_list[iterator + 1], arc_list[iterator + 2]);
        iterator += 3;
    }
}

void graph_create(Graph g){
    int vex_num;
    printf("Please insert number of input vertices:\n");
    scanf("%d", &vex_num);

    printf("Please insert info of vertices:\n");
    int *vex_list = (int *)malloc(sizeof(int) * (vex_num + 1));
    for (int i = 1; i <= vex_num; i++){
        scanf("%d", &vex_list[i]);
    }
    vex_list[0] = vex_num;

    int arc_num;
    printf("Please insert number of input arcs:\n");
    scanf("%d", &arc_num);

    printf("Please insert arc <v1,v2,weight>:\n");
    int *arc_list = (int *)malloc(sizeof(int) * (arc_num * 3 + 1));
    for (int i = 1; i <= arc_num * 3; i+=3){
        scanf("%d,%d,%d", &arc_list[i], &arc_list[i + 1], &arc_list[i + 2]);
    }
    arc_list[0] = arc_num;

    graph_build(g, vex_list, arc_list);

    free(vex_list);
    free(arc_list);
}

int graph_find_vex(Graph g, int info){
    int iterator = 0;
    while(iterator <= MAX){
        if(g->vex_list[iterator].info == info)
            return iterator;
        else
            iterator++;
    }
    return -1;
}

int graph_vex_info(Graph g, int vexID){
    if(vexID < 0 || vexID > MAX){
        printf("Request overflow.\n");
        return NOT_ASSIGNED;
    }
    return g->vex_list[vexID].info;
}

void graph_set_vex(Graph g, int vexID, int info){
    if(graph_vex_info(g, vexID) == NOT_ASSIGNED){
        printf("Vex not found.\n");
        return;
    }
    g->vex_list[vexID].info = info;
}

int graph_vex_first_adj(Graph g, int vexID){
    if(graph_vex_info(g, vexID) == NOT_ASSIGNED){
        printf("Vex not found.\n");
        return NOT_ASSIGNED;
    }
    if(g->vex_list[vexID].first_arc == NULL)
        return -1;
    return g->vex_list[vexID].first_arc->next_vexID;
}

int graph_vex_next_adj(Graph g, int vexID, int p_vexID){
    if(graph_vex_info(g, vexID) == NOT_ASSIGNED || g->vex_list[vexID].first_arc == NULL){
        printf("Vex not found.\n");
        return NOT_ASSIGNED;
    }
    if(vexID == p_vexID)
        return g->vex_list[vexID].first_arc->next_vexID;
    else{
        ArcNode *iterator = g->vex_list[vexID].first_arc;
        while(iterator->next_arc != NULL){
            if(iterator->next_vexID == p_vexID)
                return iterator->next_arc->next_vexID;
            else
                iterator = iterator->next_arc;
        }
        return -1;
    }
}

void graph_insert_vex(Graph g, int info){
    if(g->vex_num == MAX){
        printf("Graph full.\n");
        return;
    }
    if(graph_find_vex(g, info) != -1){
        printf("Vex already in the graph.\n");
        return;
    }
    int insert_pos = graph_find_vex(g, NOT_ASSIGNED);
    g->vex_list[insert_pos].info = info;
    g->vex_list[insert_pos].first_arc = NULL;
    g->vex_num++;
}

void graph_delete_vex(Graph g, int vexID){
    if(vexID < 0 || vexID >= g->vex_num){
        printf("Vex not found.\n");
        return;
    }
    //Delete indegree arcs of this vertex
    for (int i = 0, c = 0; c < g->vex_num; i++){
        if(i == vexID){
            c++;
            continue;
        }
        if(g->vex_list[i].info != NOT_ASSIGNED){
            ArcNode *iterator = g->vex_list[i].first_arc;
            while(iterator != NULL){
                if(iterator->next_vexID == vexID)
                    graph_delete_arc(g, i, iterator->next_vexID);
                iterator = iterator->next_arc;
            }
        }
        else
            continue;
    }

    //Delete the vertex
    ArcNode *iterator = g->vex_list[vexID].first_arc;
    while(iterator != NULL){
        ArcNode *temp = iterator->next_arc;
        free(iterator);
        iterator = temp;
    }
    g->vex_list[vexID].info = NOT_ASSIGNED;
    g->vex_list[vexID].first_arc = NULL;
}

ArcNode *graph_find_arc(Graph g, int s_vexID, int e_vexID){
    if(graph_vex_info(g, s_vexID) == NOT_ASSIGNED || graph_vex_info(g, e_vexID) == NOT_ASSIGNED){
        printf("Vex not found.\n");
        return NULL;
    }
    ArcNode *iterator = g->vex_list[s_vexID].first_arc;
    while(iterator != NULL){
        if(iterator->next_vexID == e_vexID)
            return iterator;
        else
            iterator = iterator->next_arc;
    }
    return NULL;
}

ArcNode *graph_find_previous_arc(Graph g, int s_vexID, int e_vexID){
    if(graph_vex_info(g, s_vexID) == NOT_ASSIGNED || graph_vex_info(g, e_vexID) == NOT_ASSIGNED){
        printf("Vex not found.\n");
        return NULL;
    }
    if(g->vex_list[s_vexID].first_arc == NULL || g->vex_list[s_vexID].first_arc->next_vexID == e_vexID){
        return NULL;
    }
    ArcNode *iterator = g->vex_list[s_vexID].first_arc;
    while(iterator->next_arc != NULL){
        if(iterator->next_arc->next_vexID == e_vexID)
            return iterator;
        else
            iterator = iterator->next_arc;
    }
}

int graph_arc_weight(Graph g, int s_vexID, int e_vexID){
    ArcNode *arc = graph_find_arc(g, s_vexID, e_vexID);
    if(arc == NULL){
        printf("Arc not found.\n");
        return NOT_ASSIGNED;
    }
    return arc->weight;
}

void graph_insert_arc(Graph g, int s_vexID, int e_vexID, int weight){
    if(graph_find_arc(g, s_vexID, e_vexID) != NULL){
        printf("Arc already existed.\n");
        return;
    }
    if(graph_vex_info(g, s_vexID) == NOT_ASSIGNED || graph_vex_info(g, e_vexID) == NOT_ASSIGNED){
        printf("Vex not found.\n");
        return;
    }
    ArcNode *new_arc = (ArcNode *)malloc(sizeof(ArcNode));
    new_arc->weight = weight;
    new_arc->next_vexID = e_vexID;
    new_arc->next_arc = g->vex_list[s_vexID].first_arc;
    g->vex_list[s_vexID].first_arc = new_arc;
    g->arc_num++;
}

void graph_delete_arc(Graph g, int s_vexID, int e_vexID){
    if(graph_find_arc(g, s_vexID, e_vexID) == NULL){
        printf("Arc not found.\n");
        return;
    }
    if(g->vex_list[s_vexID].first_arc->next_vexID == e_vexID){
        ArcNode *temp = g->vex_list[s_vexID].first_arc;
        temp->next_arc = temp->next_arc->next_arc;
        free(temp);
        return;
    }
    else{
        ArcNode *target = graph_find_previous_arc(g, s_vexID, e_vexID);
        ArcNode *temp = target->next_arc;
        target->next_arc = temp->next_arc;
        free(temp);
    }
}

void graph_DFS_traverse(Graph g, _STATUS_ (*visit)(Graph g, int vexID)){
    graph_visit_func = visit;
    //Initialize visit array
    for (int i = 0; i < g->vex_num; i++)
        visited[i] = 0;
    //DFS
    for (int i = 0; i < g->vex_num; i++){
        if(!visited[i])
            DFS(g, i);
    }
}

void graph_BFS_traverse(Graph g, _STATUS_ (*visit)(Graph g, int vexID)){
    //Initialize visit array
    for (int i = 0; i < g->vex_num; i++)
        visited[i] = 0;
    //BFS
    Queue await_vex = queue_init();
    for (int i = 0; i < g->vex_num; i++){
        if(!visited[i]){
            //Set parent vex as visited
            visited[i] = 1;
            visit(g, i);
            //Put parent vex in await visiting queue
            queue_enqueue(await_vex, i);
            //Start visiting child
            while(!queue_is_empty(await_vex)){
                int vex = queue_dequeue(await_vex);
                for (int j = graph_vex_first_adj(g, vex); j >= 0; j = graph_vex_next_adj(g, vex, j)){
                    if(!visited[j]){
                        visited[j] = 1;
                        visit(g, j);
                        queue_enqueue(await_vex, j);
                    }
                }
            }
        }
    }
    free(await_vex);
}

void DFS(Graph g, int vexID){
    graph_visit_func(g, vexID);
    visited[vexID] = 1;
    for (int i = graph_vex_first_adj(g, vexID); i >= 0; i = graph_vex_next_adj(g, vexID, i)){
        if(!visited[i]){
            DFS(g, i);
        }
    }
}

int graph_visit(Graph g, int vexID){
    printf("Visiting node: %d, Info: %d\n", vexID, graph_vex_info(g, vexID));
    return 0;
}