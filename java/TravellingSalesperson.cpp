
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void tspBacktracking(vector<vector<int>>& graph, vector<bool>& visited, int currPos, int count, int cost, int& minCost) {
    int N = graph.size();
    if (count == N && graph[currPos][0] != 0) {
        minCost = min(minCost, cost + graph[currPos][0]);
        return;
    }

    for (int i = 0; i < N; i++) {
        if (!visited[i] && graph[currPos][i] != 0) {
            visited[i] = true;
            tspBacktracking(graph, visited, i, count + 1, cost + graph[currPos][i], minCost);
            visited[i] = false; // Backtrack
        }
    }
}

int main() {
    int N;
    cout << "Enter number of cities: ";
    cin >> N;

    vector<vector<int>> graph(N, vector<int>(N));
    cout << "Enter the distance matrix (row-wise, 0 for no path):\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> graph[i][j];
        }
    }

    vector<bool> visited(N, false);
    visited[0] = true; // Start from city 0 (can be changed)
    int minCost = INT_MAX;

    tspBacktracking(graph, visited, 0, 1, 0, minCost);

    if (minCost != INT_MAX)
        cout << "Minimum TSP cost: " << minCost << endl;
    else
        cout << "No valid TSP route exists!" << endl;

    return 0;
}
