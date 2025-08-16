#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug1.cpp"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n;
    cin >> n;
    int arr[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    vector<ll> ans(n * n + 5, 0);

    for (int row = 1; row <= n; row++) {
        for (int col = 1; col <= n; col++) {
            for (int startR = 0; startR + row - 1 < n; startR++) {
                for (int startC = 0; startC + col - 1 < n; startC++) {
                    ll sum = 0;
                    for (int i = startR; i < startR + row; i++) {
                        for (int j = startC; j < startC + col; j++) {
                            sum += arr[i][j];
                        }
                    }
                    ans[row * col] = max(ans[row * col], sum);
                    // dbg(row, col, startR, startC, sum);
                }
            }
        }
    }
    dbg(ans);
    ll q;
    cin >> q;
    while (q--) {
        ll x;
        cin >> x;
        ll finalAns = 0;
        for (int i = 1; i <= x; i++)
            finalAns = max(finalAns, ans[i]);
        cout << finalAns << '\n';
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}