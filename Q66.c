#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node* adjList[MAX];
    int visited[MAX];
    int recStack[MAX];
};

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void initGraph(struct Graph* graph, int vertices) {
    graph->numVertices = vertices;
    for (int i = 0; i < vertices; i++) {
        graph->adjList[i] = NULL;
        graph->visited[i] = 0;
        graph->recStack[i] = 0;
    }
}
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
}

int hasCycle(struct Graph* graph, int v) {
    graph->visited[v] = 1;
    graph->recStack[v] = 1;

    struct Node* temp = graph->adjList[v];
    while (temp != NULL) {
        int adj = temp->vertex;

        if (!graph->visited[adj]) {
            if (hasCycle(graph, adj))
                return 1;
        }
        else if (graph->recStack[adj]) {
            return 1; 
        }

        temp = temp->next;
    }

    graph->recStack[v] = 0;
    return 0;
}

int main() {
    int n, edges, u, v;

    scanf("%d", &n);
    struct Graph graph;
    initGraph(&graph, n);

    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        addEdge(&graph, u, v);
    }

    int cycle = 0;

    for (int i = 0; i < n; i++) {
        if (!graph.visited[i]) {
            if (hasCycle(&graph, i)) {
                cycle = 1;
                break;
            }
        }
    }

    if (cycle)
        printf("YES");
    else
        printf("NO");

    return 0;
}