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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(2, vector<int>(2));
    cin >> v[0][0] >> v[0][1] >> v[1][0] >> v[1][1];
    if (v[0][0] >= v[1][0]) {
        cout << "Draw" << endl;
        return;
    }
    int winner = -1, turn = 0;
    while (v[0][0] < v[1][0]) {
        int dist = v[0][0] - v[1][0];
        if (dist & 1) {
            if (v[turn][1] > v[!turn][1])
                v[turn][1]--;
            if (v[turn][1] < v[!turn][1])
                v[turn][1]++;
        }
        else {
            if (v[turn][1] > v[!turn][1] && v[turn][1] + 1 <= m)
                v[turn][1]++;
            if (v[turn][1] < v[!turn][1] && v[turn][1] - 1 >= 1)
                v[turn][1]--;
        }
        v[turn][0] += turn ? -1 : 1;
        if (v[0] == v[1]) {
            winner = turn;
            break;
        }
        turn ^= 1;
    }
    if (winner == -1)
        cout << "Draw" << endl;
    else if (winner == 0)
        cout << "Alice" << endl;
    else
        cout << "Bob" << endl;
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // case(i)
        solve();
    }
    return 0;
}