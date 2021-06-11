#ifndef _C_GRAPH_
#define _C_GRAPH_

/*
In this impletation, crossed-linked-list ADT is used to conserve the graph
*/

#define NOT_ASSIGNED -65535
#define GRAPH_MAX 256

typedef struct VexNode VexNode;
typedef struct ArcNode ArcNode;
typedef struct Graph _Graph;
typedef _Graph *Graph;
typedef int _STATUS_;

int visited[GRAPH_MAX];
_STATUS_ (*graph_visit_func)(Graph g, int vexID);
/*
A sample of visit function is given in this impletation
*/

Graph graph_init();
void graph_build(Graph g, int* vex_list, int* arc_list);    //Read a graph from lists of vertices and arcs
/*
Vex_list and Arc_list should be given with its size at position 0.
*/
void graph_create(Graph g);                                         //Create a graph from cmd window
void graph_destroy(Graph g);
int graph_find_vex(Graph g, int info);      //Find vertex and return ID
int graph_vex_info(Graph g, int vexID);     //Return info of a vertex
void graph_set_vex(Graph g, int vexID, int info);   //Set info of a vertex
int graph_vex_first_adj(Graph g, int vexID);        //Return the first adjacent vexID of a vertex
int graph_vex_next_adj(Graph g, int vexID, int p_vexID);
void graph_insert_vex(Graph g, int info);
void graph_delete_vex(Graph g, int vexID);
ArcNode *graph_find_arc(Graph g, int s_vexID, int e_vexID);
ArcNode *graph_find_previous_arc(Graph g, int s_vexID, int e_vexID);
int graph_arc_weight(Graph g, int s_vexID, int e_vexID);
void graph_insert_arc(Graph g, int s_vexID, int e_vexID, int weight);
void graph_delete_arc(Graph g, int s_vexID, int e_vexID);
void graph_DFS_traverse(Graph g, int s_vexID, _STATUS_ (*visit)(Graph g, int vexID));
void graph_BFS_traverse(Graph g, int s_vexID, _STATUS_ (*visit)(Graph g, int vexID));
void DFS(Graph g, int vexID);
int graph_visit(Graph g, int vexID);

#endif