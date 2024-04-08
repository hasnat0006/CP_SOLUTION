//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 08|04|2024 20:48:34            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug.h"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

const int mod = 1e9 + 7;
const int inf = 1e18;

void solve() {
    int n, c, d;
    cin >> n >> c >> d;
    vector<int> v(n * n);
    for (int i = 0; i < n * n; i++)
        cin >> v[i];
    sort(vf(v));
    int arr[n][n];
    arr[0][0] = v[0];
    for(int i = 1; i < n; i++){
        arr[0][i] = arr[0][i - 1] + c;
        arr[i][0] = arr[i - 1][0] + d;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            arr[i][j] = max(arr[i - 1][j] + d, arr[i][j - 1] + c);
        }
    }
    map<int, int> mp;
    for (int i = 0; i < n * n; i++)
        mp[v[i]]++;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(mp[arr[i][j]] == 0){
                cout << "NO" << endl;
                return;
            }
            mp[arr[i][j]]--;
        }
    }
    cout << "YES" << endl;
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