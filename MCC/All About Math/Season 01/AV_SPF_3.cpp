//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 11|10|2024 12:20:42            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

const int mod = 1e9 + 7;
const int inf = 1e18;

const int N = 1e6 + 5;
int factor[N];
void SmallestPrimeFactorSeive() {
    for (int i = 2; i < N; i++) {
        if (factor[i] == 0) {
            for (int j = i; j < N; j += i) {
                if (factor[j] == 0)
                    factor[j] = i;
            }
        }
    }
}

bool prime[N];
vector<int> store;
vector<int> prefixSum;
void sieve() {
    for (int i = 2; i < N; i++)
        prime[i] = 1;
    for (int i = 4; i < N; i += 2)
        prime[i] = 0;
    for (int i = 3; i * i < N; i++) {
        if (prime[i]) {
            for (int j = i * i; j < N; j += i * 2)
                prime[j] = 0;
        }
    }
    for (int i = 2; i < N; i++) {
        if (prime[i])
            store.push_back(i);
    }
    prefixSum.resize(store.size(), 0);
    partial_sum(vf(store), prefixSum.begin());
}

void solve() {
    int n;
    cin >> n;
    int spf = factor[n];
    int id = upper_bound(vf(store), spf) - store.begin();
    cout << n * prefixSum[id - 1] << endl;
    // cerr << spf << " " << id << " " << prefixSum[id] << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    SmallestPrimeFactorSeive();
    sieve();
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}