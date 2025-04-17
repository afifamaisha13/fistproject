
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int INF = INT_MAX;

int multistageForward(vector<vector<pair<int, int>>>& graph, int stages, int source, int target) {
    int n = graph.size();
    vector<int> dp(n, INF);
    dp[source] = 0;

    // Forward pass: Process stages 1 to stages-1
    for (int k = 1; k < stages; k++) {
        for (int u = 0; u < n; u++) {
            if (dp[u] != INF) {  // Only process reachable nodes
                for (auto& edge : graph[u]) {
                    int v = edge.first;
                    int weight = edge.second;
                    if (dp[v] > dp[u] + weight) {
                        dp[v] = dp[u] + weight;
                    }
                }
            }
        }
    }

    return dp[target];
}

int main() {
    int n, stages, edges, source, target;
    cout << "Enter number of nodes, stages, and edges: ";
    cin >> n >> stages >> edges;

    vector<vector<pair<int, int>>> graph(n);
    cout << "Enter edges (u v weight) for " << edges << " edges:\n";
    for (int i = 0; i < edges; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    cout << "Enter source and target nodes: ";
    cin >> source >> target;

    int minCost = multistageForward(graph, stages, source, target);

    if (minCost != INF)
        cout << "Minimum cost from " << source << " to " << target << ": " << minCost << endl;
    else
        cout << "No path exists!" << endl;

    return 0;
}
