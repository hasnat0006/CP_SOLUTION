//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
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

const int N = 200005;

class Disjoint_Set_Union {
   public:
    vector<int> parent, size;
    Disjoint_Set_Union() {}
    void init(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findRoot(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = findRoot(parent[v]);
    }
    void Union(int a, int b) {
        int rootA = findRoot(a);
        int rootB = findRoot(b);
        if (rootA != rootB) {
            if (size[rootA] < size[rootB])
                swap(rootA, rootB);
            parent[rootB] = rootA;
            size[rootA] += size[rootB];
        }
    }
};

void solve() {
    int n, k;
    cin >> n >> k;
    string s, t;
    cin >> s >> t;
    s = "#" + s;
    t = "#" + t;
    dbg(s, t) Disjoint_Set_Union DSU;
    DSU.init(n + 5);
    for (int i = 1; i <= n; i++) {
        if (i + k <= n)
            DSU.Union(i, i + k);
        if (i + k + 1 <= n)
            DSU.Union(i, i + k + 1);
    }
    map<int, string> rootS, rootT;
    set<int> unique;
    for (int i = 1; i <= n; i++) {
        int root = DSU.findRoot(i);
        unique.insert(root);
        rootS[root].push_back(s[i]);
        rootT[root].push_back(t[i]);
    }
    for (auto it : unique) {
        sort(vf(rootS[it]));
        sort(vf(rootT[it]));
        if (rootS[it] != rootT[it]) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // case(i)
        dbg(i);
        solve();
    }
    return 0;
}