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
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)

int mod = 1000000007;
int inf = 1e18;

bool prime[4005];
void sieve(int n) {
    for (int i = 2; i <= n; i++) {
        prime[i] = 1;
    }
    for (int i = 4; i <= n; i += 2) {
        prime[i] = 0;
    }
    for (int i = 3; i * i <= n; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= n; j += i * 2)
                prime[j] = 0;
        }
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    sieve(n);
    vector<int> v;
    for (int i = 2; i <= n; i++)
        if (prime[i])
            v.push_back(i);
    dbg(v);
    int cnt = 0;
    for (int i = 0; i < v.size() - 1; i++) {
        if(prime[v[i] + v[i + 1] + 1])
            cnt++;
    }
    cnt >= k ? cout << "YES" << endl : cout << "NO" << endl;
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}