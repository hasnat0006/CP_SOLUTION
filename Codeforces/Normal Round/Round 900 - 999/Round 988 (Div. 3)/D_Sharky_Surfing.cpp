//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 17|11|2024 21:35:33            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;
#define pii pair<ll, ll>

void solve() {
    ll n, m, des;
    cin >> n >> m >> des;
    vector<pii> hill(n);
    for (auto &[l, r] : hill)
        cin >> l >> r;

    priority_queue<pii> pq;
    for (int i = 0; i < m; i++) {
        ll x, y;
        cin >> x >> y;
        pq.push({y, x});
    }
    

    ll move = 0, pos = 1, power = 0;
    for (auto [l, r] : hill) {
        ll needPower = r - l + 1;
        vector<pii> temp;
        while (power < needPower and pq.size()) {
            auto [v, x] = pq.top();
            pq.pop();
            if (x < l) {
                power += v;
                move++;
            }
            else
                temp.push_back({v, x});
        }
        while(!temp.empty()){
            pq.push(temp.back());
            temp.pop_back();
        }

        if(power < needPower){
            cout << -1 << '\n';
            return;
        }
        pos = r + 1;
        if(pos >= des){
            cout << move << '\n';
            return;
        }
    }
    cout << move << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    ll t = 1;
    cin >> t;
    for (ll i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}