#include <iostream>
using namespace std;

class Graph {
    int v;                 // number of cities (vertices)
    int adj[10][10];       // adjacency matrix

public:
    Graph(int n) {
        v = n;
        for (int i = 0; i < v; i++)
            for (int j = 0; j < v; j++)
                adj[i][j] = 0;
    }

    // Add an edge (flight) between two cities
    void addEdge(int u, int w, int cost) {
        adj[u][w] = cost;
        adj[w][u] = cost;  // because the graph is undirected
    }

    // Depth First Search (DFS)
    void dfs(int node, bool visited[]) {
        visited[node] = true;
        for (int i = 0; i < v; i++) {
            if (adj[node][i] && !visited[i])
                dfs(i, visited);
        }
    }

    // Check whether the graph is connected
    bool isConnected() {
        bool visited[10];
        for (int i = 0; i < v; i++)
            visited[i] = false;

        dfs(0, visited);   // start DFS from first city

        for (int i = 0; i < v; i++)
            if (!visited[i])
                return false;

        return true;
    }

    // Display the adjacency matrix
    void display() {
        cout << "\nAdjacency Matrix:\n";
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++)
                cout << adj[i][j] << " ";
            cout << endl;
        }
    }
};

int main() {
    int n, e, u, w, cost;
    cout << "Enter number of cities: ";
    cin >> n;

    Graph g(n);

    cout << "Enter number of flights: ";
    cin >> e;

    cout << "Enter flights (city1 city2 cost):\n";
    for (int i = 0; i < e; i++) {
        cin >> u >> w >> cost;
        g.addEdge(u, w, cost);
    }

    g.display();

    if (g.isConnected())
        cout << "\nThe flight network (graph) is connected.\n";
    else
        cout << "\nThe flight network (graph) is NOT connected.\n";

    cout << "Press any key to exit...";
    cin.ignore();
    cin.get();
    return 0;
}
