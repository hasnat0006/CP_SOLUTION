#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n, d;
    cin >> n >> d;

    vector<ll> ans;
    ans.push_back(1);
    if (d % 3 == 0 or n >= 3)
        ans.push_back(3);
    if (d == 5 or d == 0)
        ans.push_back(5);
    if (d == 7 or n >= 3)
        ans.push_back(7);
    if (d == 9 or n >= 6 or (n >= 3 and (d == 3 or d == 6)))
        ans.push_back(9);
    for (auto i : ans)
        cout << i << ' ';
    cout << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}