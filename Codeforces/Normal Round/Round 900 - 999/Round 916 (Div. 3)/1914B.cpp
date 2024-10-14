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
    int n, k;
    cin >> n >> k;
    vector<int> v(n + 1, 0);
    if (k != 0) {
        cout << 1 << " ";
        v[1] = 1;
        int c = 0;
        for (int i = 2; i <= n; i++) {
            if (k == c + 1) {
                cout << n << " ";
                v[n] = 1;
                break;
            }
            else {
                cout << i << " ";
                v[i] = 1;
            }
            c++;
        }
        for (int i = n; i >= 1; i--) {
            if (v[i] == 0) {
                cout << i << " ";
            }
        }
    }
    else {
        for (int i = n; i >= 1; i--) {
            cout << i << " ";
        }
    }
    cout << endl;
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