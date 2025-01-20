#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug1.cpp"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<vector<ll>> a(n, vector<ll>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    vector<ll> rowSum(n), colSum(m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            rowSum[i] += a[i][j];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            colSum[i] += a[j][i];
    dbg(rowSum);
    dbg(colSum);
    auto isPossible = [&](ll sum) {
        ll turn = 0, row = 0, col = 0;
        vector<vector<ll>> copy = a;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'D') {
                // taile row niye chinta korbo
                ll needToAdd = sum - rowSum[row];
                copy[row][col] = needToAdd;
                rowSum[row] += needToAdd;
                colSum[col] += needToAdd;
                row++;
            }
            else {
                // taile col niye chinta korbo
                ll needToAdd = sum - colSum[col];
                copy[row][col] = needToAdd;
                rowSum[row] += needToAdd;
                colSum[col] += needToAdd;
                col++;
            }
            // dbg(row, col, copy);
        }
        // last element
        ll needToAdd = sum - rowSum[row];
        copy[row][col] = needToAdd;
        rowSum[row] += needToAdd;
        colSum[col] += needToAdd;
        dbg(rowSum);
        dbg(colSum);
        dbg(copy);
        for (auto i : copy) {
            for (auto j : i)
                cout << j << " ";
            cout << '\n';
        }
        return;
    };
    isPossible(0);
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}