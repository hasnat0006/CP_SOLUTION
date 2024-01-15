#include <bits/stdc++.h>
#define int long long
using namespace std;
int inf = -1 * 1e18;
typedef pair<int, pair<int, int>> pairUV;

// vector<pair<int, int>> adj[10005];
map<int, bool> visited;
map<int, vector<pair<int, int>>> adj;
int32_t main()
{
    int a, e;
    std::cin >> a >> e;
    while (e--)
    {
        int u, v;
        int wt;
        std::cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        // adj[v].push_back({u, wt});
    }
    int sum = 0, c = 0;
    vector<pairUV> ans;
    priority_queue<pairUV> pq;
    pq.push({0, {1, inf}});
    while (!pq.empty())
    {
        pairUV k = pq.top();
        pq.pop();
        int u = k.second.first;
        int v = k.second.second;
        int wt = k.first;
        if (visited[u])
            continue;
        sum += wt;
        visited[u] = 1;
        if (v != inf)
            ans.push_back({wt, {u, v}});
        for (auto it : adj[u])
        {
            int adjNode = it.first;
            int adjwt = it.second;
            if (!visited[adjNode])
                pq.push({adjwt, {adjNode, u}});
        }
    }
    std::cout << sum << endl;
    // for (auto it : ans)
    //     std::cout << it.second.first << " " << it.second.second << " -> " << it.first << endl;
}

/*
9
1 4 1
1 2 2
2 3 3
2 4 3
6 3 8
3 4 5
3 2 3
5 4 9
5 1 4

9
Hasnat Raisul 4
Hasnat Zaima 1
Zaima Raisul 9
Hasnat Nabiha 2
Nabiha Ifrit 3
Nabiha Zaima 3
Nabiha Pallob 7
Zaima Ifrit 5
Ifrit Pallob 8


*/