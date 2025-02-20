#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = 1e9; // Use a large but safe value to prevent overflow

typedef vector<vector<int>> Graph;

// Function to find the shortest path using Dijkstra's algorithm
vector<int> dijkstra(const Graph& graph, int src) {
    int n = graph.size();
    vector<int> dist(n, INF);
    vector<bool> visited(n, false);
    dist[src] = 0;

    for (int i = 0; i < n - 1; ++i) {
        int minDist = INF, u = -1;
        
        for (int v = 0; v < n; ++v) {
            if (!visited[v] && dist[v] < minDist) {
                minDist = dist[v];
                u = v;
            }
        }
        
        if (u == -1) break;
        visited[u] = true;

        for (int v = 0; v < n; ++v) {
            if (graph[u][v] != 0 && dist[u] != INF && dist[u] < INF - graph[u][v] && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    return dist;
}

int main() {
    // Adjacency matrix representation of the graph from the first task
    Graph graph = {
        {0, 5, 12, INF, INF, INF, 25},
        {5, 0, 8, INF, INF, INF, INF},
        {12, 8, 0, 2, INF, INF, INF},
        {INF, INF, 2, 0, 4, INF, INF},
        {INF, INF, INF, 4, 0, 5, INF},
        {INF, INF, INF, INF, 5, 0, 5},
        {25, INF, INF, INF, INF, 5, 0}
    };
    
    int start = 0; // Node A (index 0)
    int end = 6;   // Node G (index 6)
    
    vector<int> distances = dijkstra(graph, start);
    cout << "Shortest path from A to G: " << distances[end] << endl;
    
    return 0;
}
