//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 12|04|2024 10:26:29            !//
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

typedef pair<int, int> pairi;
int N = 20000 + 5;
vector<vector<pairi>> adj(N);
vector<int> dis(N, inf), parent(N);

void dijkstra(int src) {
    priority_queue<pairi, vector<pairi>, greater<pairi>> pq;
    dis[src] = 0;
    pq.push({0, src});
    while (pq.size()) {
        auto top = pq.top();
        pq.pop();
        for (auto i : adj[top.second]) {
            int v = i.first;
            int wt = i.second;
            if (dis[v] > dis[top.second] + wt) {
                dis[v] = dis[top.second] + wt;
                pq.push({dis[v], v});
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;
    adj.resize(n + 1);
    for(int i = 1; i < n; i++){
        for(int j = 1; j <= i; j++){
            string x;
            cin >> x;
            if(x != "x"){
                adj[i + 1].push_back({j, stoll(x)});
                adj[j].push_back({i + 1, stoll(x)});
            }
        }
    }
    dijkstra(1);
    int ans = 0;
    for(int i = 2; i <= n; i++){
        ans = max(ans, dis[i]);
    }
    cout << ans << endl;
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