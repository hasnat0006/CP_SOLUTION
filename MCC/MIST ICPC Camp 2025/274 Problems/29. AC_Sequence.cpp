#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    auto calAns = [&]() {
        ll sum = v[0], turn = 0;
        ll pos = (v[0] > 0);
        for (int i = 1; i < n; i++) {
            sum += v[i];
            if (pos) {
                if (sum >= 0) {
                    turn += (sum + 1);
                    sum = -1;
                }
            }
            else {
                if (sum <= 0) {
                    turn += abs(sum) + 1;
                    sum = 1;
                }
            }
            pos = !pos;
        }
        return turn;
    };
    if (v.front() == 0) {
        v[0] = 1;
        ll t1 = calAns();
        v[0] = -1;
        ll t2 = calAns();
        cout << min(t1, t2) + 1 << '\n';
    }
    else {
        ll t1 = calAns();
        ll temp = v[0];
        v[0] = 1;
        ll t2 = abs(temp - 1) + calAns();
        v[0] = -1;
        ll t3 = abs(temp + 1) + calAns();
        cout << min({t1, t2, t3}) << '\n';
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