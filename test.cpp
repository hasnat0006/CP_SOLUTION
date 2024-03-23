#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

// Perform DFS to count the number of nodes in each subtree
int dfs(int node, int parent, int& count) {
    int size = 1;
    for (int child : adj[node]) {
        if (child != parent && !visited[child]) {
            size += dfs(child, node, count);
        }
    }
    if (size < count && parent != -1) {
        // Mark the subtree as visited
        visited[node] = true;
    }
    return size;
}

// Check if it's possible to remove k edges while maintaining each component
// size at least x
bool possible(int x, int k, int n) {
    visited.assign(n + 1, false);
    int components = 0;
    int edges_to_remove = 0;
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            // Count the number of nodes in the subtree rooted at i
            int size = dfs(i, -1, x);
            components++;
            edges_to_remove +=
                max(0, size - 1);  // Count edges to remove for this component
        }
    }
    edges_to_remove /= 2;  // Divide by 2 to account for double counting
    return edges_to_remove <= k;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        adj.assign(n + 1, vector<int>());
        for (int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // Binary search for the maximum possible x
        int low = 1, high = n, result = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (possible(mid, k, n)) {
                result = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        cout << result << endl;
    }
    return 0;
}
