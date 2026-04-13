/*Q61 Build a graph with n vertices and m edges using adjacency matrix representation.
The graph may be directed or undirected.*/

#include <stdio.h>

int main() {
    int n, m, i, j;
    
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int adj[n][n];

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter number of edges: ");
    scanf("%d", &m);

    int type;
    printf("Enter 1 for Directed graph, 0 for Undirected graph: ");
    scanf("%d", &type);

    int u, v;
    printf("Enter edges (u v):\n");
    for(i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        adj[u][v] = 1;

        if(type == 0) { 
            adj[v][u] = 1;
        }
    }

    printf("\nAdjacency Matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}