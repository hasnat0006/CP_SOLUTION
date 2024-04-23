//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 23|04|2024 17:18:58            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

#define int   long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

const int mod = 1e9 + 7;
const int inf = 1e18;

vector<int> color;
vector<int> adj[200005];
vector<int> visited;
vector<int> ans;

bool dfs(int src, int clr){
    visited[src] = 1;
    bool f = true;
    for(auto i : adj[src]){
        if(!visited[i]){
            f &= dfs(i, color[i]);
        }
    }
    cerr << src << " " << clr << " " << f << endl;
    if(f and (clr == 1 or clr == -1)){
        ans.push_back(src);
    }
    return f;
}

void solve() {
    int n, k, x;
    cin >> n >> k;
    color.resize(n + 1, 0);
    visited.resize(n + 1, 0);
    for(int i = 1; i <= k; i++){
        cin >> x;
        color[x] = 1;
    }
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(color.front(), -1);
    cout << ans.size() << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++){
        solve(); 
    }
    return 0;
}