//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 15|11|2024 11:50:37            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const int mod = 1e9 + 7;
const ll inf = 1e18;

const int N = 1e6 + 5;
int spf[N];
void smallestPrimeFactorUsingSeive() {
    for (int i = 2; i < N; i++) {
        if (spf[i] == 0) {
            for (int j = i; j < N; j += i) {
                if (spf[j] == 0)
                    spf[j] = i;
            }
        }
    }
}

void solve() {
    ll n;
    cin >> n;
    map<ll, ll> mp;
    while (n > 1) {
        ll r = spf[n];
        while (n % r == 0) {
            mp[r]++;
            n /= r;
        }
    }
    ll cnt = 0;
    for (auto i : mp)
        cnt = max(cnt, i.second);
    cout << cnt << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    smallestPrimeFactorUsingSeive();
    cin >> t;
    for (int i = 1; i <= t; i++) {
        //  cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}