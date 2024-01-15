//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "C:\Users\Yusuf Reza Hasnat\OneDrive\Desktop\CP\debug.h"
#else
#define dbg(x...)
#define dbgc(x...)
#endif

using namespace std;

#define int long long
#define float long double
#define pb push_back
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define dosomic(x) fixed << setprecision(x)
#define endl "\n"
#define case(x) cout << "Case " << x << ": "
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)

int mod = 1000000007;
float pi = acos(-1);
int inf = 1e18;

int dp[100005][20];

string s;
vector<string> c = {"ash",    "red",    "blue",  "gold",   "grey",
                    "pink",   "cyan",   "brown", "white",  "black",
                    "orange", "silver", "green", "yellow", "purple"};

int check(int i, int wt, unordered_map<int, int> &visited) {
    if (i > 14 or wt <= 0)
        return 0;
    if (dp[i][wt] != -1)
        return dp[i][wt];
    // for (auto it : emni)
    //     visited[it] = 1;
    vector<int> emni;
    string temp = c[i];
    int id = 0;
    int nibo = 0;
    for (int i = 0; i < s.size(); i++) {
        // dbg(temp, s, s[i], temp[id]);
        if (s[i] == temp[id] and !visited[i])
            emni.push_back(i), id++;
        if (id == temp.size()) {
            nibo = 1;
            break;
        }
    }
    dbg(temp, nibo);
    int yes = 0;
    if (nibo) {
        for (auto x : emni)
            visited[x] = 1;
        yes = check(i + 1, wt - 1, visited) + 1;
        dbg(visited);
        // emni.clear();
    }
    // emni.clear();
    for (auto x : emni)
        visited[x] = 0;
    int noo = check(i + 1, wt, visited);
    dbg(visited);
    return dp[i][wt] = max(noo, yes);
}

void solve() {
    unordered_map<int, int> visited;
    // vector<int> emni;
    visited.clear();
    memset(dp, -1, sizeof(dp));
    s.clear();
    cin >> s;
    sort(vf(s));
    cout << check(0, 15, visited) << endl;
    // for (auto i : visited)
    //     cout << i.first << " " << i.second << endl;
    // cout << endl;
    dbg(visited);
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    for (int i = 0; i < c.size(); i++)
        sort(vf(c[i]));
    reverse(vf(c));
    for (int i = 1; i <= t; i++)
        // case(i)
        solve();
    return 0;
}