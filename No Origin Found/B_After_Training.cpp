#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> seq;

    ll mid = (m + 1) / 2;
    ll l = mid - 1, r = mid + 1;
    seq.push_back(mid);
    if (m % 2 == 0) {
        seq.push_back(mid + 1);
        r++;
    }
    ll turn = 1;
    while (l > 0 or r <= m) {
        seq.push_back(turn ? l-- : r++);
        turn = !turn;
    }
    for(int i = 0; i < n; i++) {
        cout << seq[i % m] << '\n';
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