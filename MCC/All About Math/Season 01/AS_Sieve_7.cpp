//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 11|10|2024 11:45:46            !//
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
int prime[N];
vector<int> store[11];
void seive() {
    for (int i = 2; i < N; i++) {
        if (prime[i] == 0) {
            for (int j = i; j < N; j += i)
                prime[j]++;
        }
    }
    for (int i = 0; i < N; i++) {
        store[prime[i]].push_back(i);
    }
}

void solve() {
    int a, b, n;
    cin >> a >> b >> n;
    int id1 = upper_bound(vf(store[n]), a - 1) - store[n].begin();
    int id2 = upper_bound(vf(store[n]), b) - store[n].begin();
    cout << (id2 - id1) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    seive();
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}