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
    ll n;
    cin >> n;
    int grid[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            grid[i][j] = 0;
        }
    }
    int row_start = 0, row_end = n - 1, col_start = 0, col_end = n - 1;
    int num = n * n - 1;
    while (row_start <= row_end && col_start <= col_end) {
        for (int i = col_start; i <= col_end; i++) {
            grid[row_start][i] = num--;
        }
        row_start++;
        for (int i = row_start; i <= row_end; i++) {
            grid[i][col_end] = num--;
        }
        col_end--;
        if (row_start <= row_end) {
            for (int i = col_end; i >= col_start; i--) {
                grid[row_end][i] = num--;
            }
            row_end--;
        }
        if (col_start <= col_end) {
            for (int i = row_end; i >= row_start; i--) {
                grid[i][col_start] = num--;
            }
            col_start++;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }


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