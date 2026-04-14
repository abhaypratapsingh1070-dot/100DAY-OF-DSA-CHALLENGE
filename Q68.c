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
    int inDegree[MAX];
}:

struct Queue {
    int items[MAX];
    int front, rear;
};

void initQueue(struct Queue* q) {
    q->front = q->rear = -1;
}

int isEmpty(struct Queue* q) {
    return q->front == -1;
}

void enqueue(struct Queue* q, int val) {
    if (q->rear == MAX - 1) return;
    if (q->front == -1) q->front = 0;
    q->items[++q->rear] = val;
}

int dequeue(struct Queue* q) {
    int item = q->items[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
    return item;
}
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
        graph->inDegree[i] = 0;
    }
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    graph->inDegree[dest]++;  
}

void topologicalSort(struct Graph* graph) {
    struct Queue q;
    initQueue(&q);

    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->inDegree[i] == 0)
            enqueue(&q, i);
    }

    int count = 0;
    while (!isEmpty(&q)) {
        int current = dequeue(&q);
        printf("%d ", current);
        count++;

        struct Node* temp = graph->adjList[current];
        while (temp != NULL) {
            int adj = temp->vertex;
            graph->inDegree[adj]--;

            if (graph->inDegree[adj] == 0)
                enqueue(&q, adj);

            temp = temp->next;
        }
    }

    if (count != graph->numVertices) {
        printf("\nCycle exists, topological sort not possible");
    }
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

    topologicalSort(&graph);

    return 0;
}