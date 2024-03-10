//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 07|03|2024 21:29:15            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

int mod = 1000000007;
int inf = 1e18;

int prime[10000007];
void sieve(int n) {
    for (int i = 2; i <= n; i++)
        prime[i] = 1;
    for (int i = 4; i <= n; i += 2)
        prime[i] = 0;
    for (int i = 3; i * i <= n; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= n; j += i * 2)
                prime[j] = 0;
        }
    }
}

vector<int> v;

void solve() {
    int n;
    cin >> n;
    int ans = 0;
    for (auto i : v) {
        if (i > n)
            break;
        if (i % 2) {
            if (i * 2 > n)
                ans++;
        }
        else
            ans++;
    }
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    sieve(10000007);
    for (int i = 2; i <= 10000002; i++) {
        if (prime[i])
            v.push_back(i);
    }
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}