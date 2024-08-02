#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define MAX_VERTICES 100 // Maximum number of vertices

int minDistance(int dist[], bool sptSet[], int V)
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void printPath(int parent[], int j)
{
    // Base case: if j is the source
    if (parent[j] == -1)
        return;

    printPath(parent, parent[j]);

    printf(" -> %d", j);
}

void printSolution(int dist[], int parent[], int src, int V)
{
    printf("Vertex \t\t Distance from Source \t Path\n");
    for (int i = 0; i < V; i++)
    {
        printf("%d \t\t\t %d \t\t\t\t %d", i, dist[i], src);
        printPath(parent, i);
        printf("\n");
    }
}

void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int src, int V)
{
    int dist[MAX_VERTICES];
    int parent[MAX_VERTICES]; // Array to store the parent vertex
    bool sptSet[MAX_VERTICES];

    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        sptSet[i] = false;
        parent[i] = -1; // Initialize parent of each vertex as -1 (indicating no parent)
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, sptSet, V);

        sptSet[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (!sptSet[v] && graph[u][v] != INT_MAX && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u; // Set u as parent of vertex v
            }
        }
    }

    printSolution(dist, parent, src, V);
}

int main()
{
    int V, E; // Number of vertices and edges
    scanf("%d %d", &V, &E);

    int graph[MAX_VERTICES][MAX_VERTICES];

    // Initialize graph with infinity distances
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            graph[i][j] = INT_MAX;
        }
    }

    // Input edges and weights
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;

        // For undirected graph (remove this if only dealing with directed graphs)
        graph[v][u] = w;
    }

    int src = 0;

    // Function call
    dijkstra(graph, src, V);

    return 0;
}
