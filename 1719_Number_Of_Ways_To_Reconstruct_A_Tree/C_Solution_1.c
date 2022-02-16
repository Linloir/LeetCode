/*** 
 * Author       : Linloir
 * Date         : 2022-02-16 15:48:14
 * LastEditTime : 2022-02-16 21:49:58
 * Description  : [16/2/2022 daily] | LeetCode 1719 | Hard | C Solution 1
 */

//FAILED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct arc{
    int adjVex;
    bool available;
    struct arc* nextArc;
};

struct vex{
    int num;
    bool visited;
    struct arc* firstArc;
};

struct graph{
    int vexNum; 
    struct vex* vexList;
    int* arcNumList;
};

struct pair{
    int first;
    int second;
};

struct hashNode{
    struct pair val;
    struct hashNode* next;
};

struct hashMap{
    int mapSize;
    struct hashNode** list;
};

typedef struct graph* Graph;
typedef struct hashMap* Map;
typedef struct pair Pair;

int HashAddr(Pair pair){
    return pair.first % pair.second + pair.second % pair.first;
}

Map CreateMap(int mapSize){
    Map newMap = (Map)malloc(sizeof(struct hashMap));
    newMap->mapSize = mapSize;
    newMap->list = (struct hashNode**)malloc(sizeof(struct hashNode*) * mapSize);
    for(int i = 0; i < newMap->mapSize; i++){
        newMap->list[i] = NULL;
    }
    return newMap;
}

void MapInsert(Map map, Pair val){
    int addr = HashAddr(val) % map->mapSize;
    struct hashNode* newNode = (struct hashNode*)malloc(sizeof(struct hashNode));
    newNode->next = map->list[addr];
    newNode->val = val;
    map->list[addr] = newNode;
}

bool IsEqual(const Pair a, const Pair b){
    return (a.first == b.first && a.second == b.second) || (a.first == b.second && a.second == b.first);
}

bool MapFind(Map map, Pair val){
    int addr = HashAddr(val) % map->mapSize;
    struct hashNode* ptr = map->list[addr];
    while(ptr){
        if(IsEqual(ptr->val, val)){
            return true;
        }
        ptr = ptr->next;
    }
    return false;
}

Graph CreateGraph(){
    Graph newGraph = (Graph)malloc(sizeof(struct graph));
    newGraph->vexNum = 0;
    newGraph->vexList = (struct vex*)malloc(sizeof(struct vex) * 500);
    newGraph->arcNumList = (int*)malloc(sizeof(int) * 500);
    return newGraph;
}

void GraphAddVex(Graph g, int val){
    g->vexList[g->vexNum].num = val;
    g->vexList[g->vexNum].visited = false;
    g->vexList[g->vexNum].firstArc = NULL;
    g->arcNumList[g->vexNum] = 0;
    g->vexNum++;
}

void GraphAddArc(Graph g, int firstVal, int secondVal){
    //Find vex
    int firstVex = 0;
    int secondVex = 0;
    while(firstVex < g->vexNum){
        if(g->vexList[firstVex].num != firstVal){
            firstVex++;
            continue;
        }
        else{
            break;
        }
    }
    if(firstVex == g->vexNum){
        GraphAddVex(g, firstVal);
    }
    while(secondVex < g->vexNum){
        if(g->vexList[secondVex].num != secondVal){
            secondVex++;
            continue;
        }
        else{
            break;
        }
    }
    if(secondVex == g->vexNum){
        GraphAddVex(g, secondVal);
    }
    //Add arc
    struct arc* farc = (struct arc*)malloc(sizeof(struct arc));
    farc->adjVex = secondVex;
    farc->available = true;
    farc->nextArc = g->vexList[firstVex].firstArc;
    g->vexList[firstVex].firstArc = farc;
    g->arcNumList[firstVex]++;
    struct arc* sarc = (struct arc*)malloc(sizeof(struct arc));
    sarc->adjVex = firstVex;
    sarc->available = true;
    sarc->nextArc = g->vexList[secondVex].firstArc;
    g->vexList[secondVex].firstArc = sarc;
    g->arcNumList[secondVex]++;
}

struct arc* GraphFindArc(Graph g, int strt, int end){
    struct arc* ptr = g->vexList[strt].firstArc;
    while(ptr){
        if(ptr->adjVex == end){
            return ptr;
        }
        ptr = ptr->nextArc;
    }
    return NULL;
}

void BuildAndVerify(Graph g, int vexID, int* prevVex, int prevVexSize, Map dic, int* linked, bool* hasDualLinked){
    
}

int checkWays(int** pair, int pairsSize, int* pairsColSize){
    Graph g = CreateGraph();
    Map dic = CreateMap(1000);
    //Construct graph and map
    for(int i = 0; i < pairsSize; i++){
        GraphAddArc(g, pair[i][0], pair[i][1]);
        Pair p;
        p.first = pair[i][0];
        p.second = pair[i][1];
        MapInsert(dic, p);
    }
    //Traverse graph
    int* prev = (int*)malloc(sizeof(int) * g->vexNum);
    bool hasLinked = false;;
    for(int i = 0; i < g->vexNum; i++){
        if(g->arcNumList[i] == g->vexNum - 1){
            int linked = 0;
            bool hasDualLinked = false;
            BuildAndVerify(g, i, prev, 0, dic, &linked, &hasDualLinked);
            if(linked == g->vexNum && (hasLinked || hasDualLinked)){
                return 2;
            }
            else if(linked == g->vexNum){
                hasLinked = true;
            }
        }
    }
    if(hasLinked){
        return 1;
    }
    return 0;
}

//Test Bench
void TestBench(){
    int size;
    scanf("%d", &size);
    int** pair = (int**)malloc(sizeof(int*) * size);
    int* pairsColSize = (int*)malloc(sizeof(int) * size);
    for(int i = 0; i < size; i++){
        pair[i] = (int*)malloc(sizeof(int) * 2);
        scanf("%d,%d", &pair[i][0], &pair[i][1]);
        pairsColSize[i] = 2;
    }
    printf("%d\n", checkWays(pair, size, pairsColSize));
}

int main(){
    TestBench();
    return 0;
}
