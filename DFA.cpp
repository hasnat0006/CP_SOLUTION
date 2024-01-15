#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> g[N];
int vis[N];
vector<vector<int>> cc;
vector<int> current;
bool dfs(int vertex, int par)
{
    // Take action on vertex after entering the vertex.
    vis[vertex] = 1;
    bool isLoopExits = false;
    // cout << vertex << endl;
    for (auto child : g[vertex])
    {
        // cout << "Parent: " << vertex << " child: " << child << endl;
        if (vis[child] and child == par)
            continue;
        if (vis[child])
            return true;
        // Take action on child before entering the vertex.
        isLoopExits |= dfs(child, vertex);
        // Take action on child after leaving the vertex.
    }
    // take action on vertex before leaving the vertex.
    return isLoopExits;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (vis[i])
            continue;
        if (dfs(i, 0))
        {
            cout << "YES\n";
            return 0;
        } 
        // c++;
    }
    cout << c << endl;
}