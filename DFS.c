#include <stdio.h>

#define MAX 100  // Maximum number of vertices

// Graph represented as an adjacency matrix
int graph[MAX][MAX];
int visited[MAX];
int numVertices;

// DFS algorithm
void DFS(int vertex) {
    printf("Visited %d\n", vertex);
    visited[vertex] = 1;

    for (int i = 0; i < numVertices; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

int main() {
    int edges, u, v;

    // Initialize the graph and visited array
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            graph[i][j] = 0;  // Initialize all edges as 0 (no connection)
        }
        visited[i] = 0;  // Mark all vertices as unvisited
    }

    // Input the number of edges
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // Input edges
    for (int i = 0; i < edges; i++) {
        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;  // Mark the edge between vertex u and v
        graph[v][u] = 1;  // For an undirected graph, also mark v to u
    }

    // Perform DFS starting from vertex 0
    DFS(0);

    return 0;
}
