#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll int

int ori(const pair<int, int> &o, const pair<int, int> &a, const pair<int, int> &b)
{
    int ret = (a.first - o.first) * (b.second - o.second) -
              (a.second - o.second) * (b.first - o.first);
    return (ret > 0) - (ret < 0);
}

bool isIntersect(const pair<int, int> &p1, const pair<int, int> &p2,
                 const pair<int, int> &q1, const pair<int, int> &q2)
{
    if (ori(p1, p2, q1) == 0 && ori(p1, p2, q2) == 0 && ori(q1, q2, p1) == 0 && ori(q1, q2, p2) == 0)
    { 
        if (ori(p1, p2, q1))
            return false;
        return (p1.first - q1.first) * (p2.second - q1.second) <= 0 ||
               (p1.second - q1.second) * (p2.first - q1.first) <= 0 ||
               (q1.first - p1.first) * (q2.second - p1.second) <= 0 ||
               (q1.second - p1.second) * (q2.first - p1.first) <= 0;
    }
    return (ori(p1, p2, q1) * ori(p1, p2, q2) <= 0) &&
           (ori(q1, q2, p1) * ori(q1, q2, p2) <= 0);
}

void solve() {
    pair<ll, ll> a, b;
    cin >> a.first >> a.second >> b.first >> b.second;
    ll n;
    cin >> n;
    vector<pair<ll, ll>> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i].first >> v[i].second;
    ll cnt = 0;
    for(int i = 0; i < n - 1; i++) {
        cnt += isIntersect(v[i], v[i + 1], a, b);
    }
    cnt += isIntersect(v.back(), v.front(), a, b);
    cout << cnt / 2 + 1 << '\n';
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