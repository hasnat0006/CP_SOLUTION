//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 15|11|2024 11:50:37            !//
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

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

int N = 1e6 + 1;
vector<int> countDivisor(N, 0);
void countingDivisor() {
    for (int i = 1; i < N; i++)
        for (int j = i; j < N; j += i)
            countDivisor[j]++;
}

vector<ll> ok(N, 1), ans;
void preCalculate() {
    for (int m = 1; m < N; m++) {
        for (ll n = m; n < N; n += m) {
            if (countDivisor[n] % countDivisor[m])
                ok[n] = 0;
        }
    }
    for(ll i = 1; i < N; i++){
        if(ok[i] and countDivisor[i] > 3)
            ans.push_back(i);
    }

}

void solve() {
    countingDivisor();
    preCalculate();
    for (int i = 107; i < ans.size(); i += 108) {
            cout << ans[i] << '\n';
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        //  cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}