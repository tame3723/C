#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define INF 99999

int graph[MAX][MAX], vertices;

// Function to create a graph
void createGraph() {
    int edges, u, v, w;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            graph[i][j] = (i == j) ? 0 : INF;
    
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    
    printf("Enter edges (start end weight):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }
}

// Function for Breadth-First Search
void bfs(int start) {
    int queue[MAX], front = 0, rear = 0, visited[MAX] = {0};
    queue[rear++] = start;
    visited[start] = 1;

    printf("BFS Traversal: ");
    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);
        for (int i = 0; i < vertices; i++) {
            if (graph[node][i] != INF && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

// Function for Depth-First Search
void dfsUtil(int node, int visited[]) {
    printf("%d ", node);
    visited[node] = 1;
    for (int i = 0; i < vertices; i++) {
        if (graph[node][i] != INF && !visited[i]) {
            dfsUtil(i, visited);
        }
    }
}

void dfs(int start) {
    int visited[MAX] = {0};
    printf("DFS Traversal: ");
    dfsUtil(start, visited);
    printf("\n");
}

// Function to find the shortest path using Dijkstra's algorithm
void dijkstra(int start) {
    int dist[MAX], visited[MAX] = {0};
    
    for (int i = 0; i < vertices; i++) dist[i] = INF;
    dist[start] = 0;

    for (int count = 0; count < vertices - 1; count++) {
        int min = INF, u = -1;
        for (int i = 0; i < vertices; i++)
            if (!visited[i] && dist[i] <= min) min = dist[i], u = i;

        visited[u] = 1;
        for (int v = 0; v < vertices; v++)
            if (!visited[v] && graph[u][v] != INF && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printf("Shortest distances from vertex %d:\n", start);
    for (int i = 0; i < vertices; i++)
        printf("To %d -> %d\n", i, dist[i]);
}

// Function to find Minimum Spanning Tree using Prim's algorithm
void primMST() {
    int parent[MAX], key[MAX], mstSet[MAX] = {0};
    
    for (int i = 0; i < vertices; i++) key[i] = INF, parent[i] = -1;
    key[0] = 0;

    for (int count = 0; count < vertices - 1; count++) {
        int min = INF, u;
        for (int i = 0; i < vertices; i++)
            if (!mstSet[i] && key[i] < min) min = key[i], u = i;

        mstSet[u] = 1;
        for (int v = 0; v < vertices; v++)
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    printf("Minimum Spanning Tree (Prim's Algorithm):\n");
    for (int i = 1; i < vertices; i++)
        printf("Edge %d - %d (Weight: %d)\n", parent[i], i, graph[i][parent[i]]);
}

// Menu-Driven Program
int main() {
    int choice, startVertex;

    while (1) {
        printf("\n===== GRAPH OPERATIONS MENU =====\n");
        printf("1. Create Graph\n2. BFS Traversal\n3. DFS Traversal\n4. Dijkstra's Shortest Path\n");
        printf("5. Find Minimum Spanning Tree (Prim's Algorithm)\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createGraph(); break;
            case 2: printf("Enter start vertex for BFS: "); scanf("%d", &startVertex); bfs(startVertex); break;
            case 3: printf("Enter start vertex for DFS: "); scanf("%d", &startVertex); dfs(startVertex); break;
            case 4: printf("Enter start vertex for Dijkstra: "); scanf("%d", &startVertex); dijkstra(startVertex); break;
            case 5: primMST(); break;
            case 6: exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
}