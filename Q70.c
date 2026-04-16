#include <stdio.h>
#include <limits.h>

#define MAX 100

struct Edge {
    int u, v, w;
};

void bellmanFord(struct Edge edges[], int n, int m, int src) {
    int dist[MAX];

    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    int hasCycle = 0;
    for (int j = 0; j < m; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            hasCycle = 1;
            break;
        }
    }

    if (hasCycle) {
        printf("Negative weight cycle detected\n");
    } else {
        printf("Vertex   Distance from Source\n");
        for (int i = 0; i < n; i++) {
            printf("%d \t\t %d\n", i, dist[i]);
        }
    }
}

int main() {
    int n, m, src;

    scanf("%d", &n);
    scanf("%d", &m);

    struct Edge edges[MAX];

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    scanf("%d", &src);

    bellmanFord(edges, n, m, src);

    return 0;
}