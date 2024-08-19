//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 19|08|2024 21:08:43            !//
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

bool prime[1000005];
void sieve() {
    for (int i = 2; i <= 1000005; i++)
        prime[i] = 1;
    for (int i = 4; i <= 1000005; i += 2)
        prime[i] = 0;
    for (int i = 3; i * i <= 1000005; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= 1000005; j += i * 2)
                prime[j] = 0;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    int N = n;
    int ans = 0, num = 1;
    for (int i = 0; i <= 20; i++) {
        if (prime[N]) {
            ans++;
            N = 0;
            break;
        }
        int num = 1 << i;
        int dam = num;
        if (dam <= N) {
            ans++;
            N -= dam;
        }
        else
            break;
    }
    if(N == 0)
        cout << ans << endl;
    else
        cout << -1 << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    sieve();
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}