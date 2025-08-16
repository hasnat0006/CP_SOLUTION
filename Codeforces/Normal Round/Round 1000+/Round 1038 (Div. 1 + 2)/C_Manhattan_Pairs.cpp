#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug1.cpp"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n;
    cin >> n;
    set<pair<ll, pair<ll, ll>>> X, Y;
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        X.insert({a, {b, i}});
        Y.insert({b, {a, i}});
    }

    ll sum = 0;
    vector<pair<ll, ll>> ans;

    auto find_distanceX = [&](pair<ll, pair<ll, ll>> a,
                              pair<ll, pair<ll, ll>> b) {
        auto [x1, it1] = a;
        auto [y1, i1] = it1;
        auto [x2, it2] = b;
        auto [y2, i2] = it2;
        return make_tuple((abs(x1 - x2) + abs(y1 - y2)), i1, i2, x1, y1, x2,
                          y2);
    };

    auto find_distanceY = [&](pair<ll, pair<ll, ll>> a,
                              pair<ll, pair<ll, ll>> f,
                              pair<ll, pair<ll, ll>> l) {
        auto [y1, it1] = a;
        auto [x1, i1] = it1;
        auto [y2, it2] = f;
        auto [x2, i2] = it2;
        auto [y3, it3] = l;
        auto [x3, i3] = it3;

        ll tempSum1 = abs(x1 - x2) + abs(y1 - y2);
        ll tempSum2 = abs(x1 - x3) + abs(y1 - y3);

        if (tempSum1 > tempSum2)
            return make_tuple(tempSum1, i1, i2, x1, y1, x2, y2, 0);
        else
            return make_tuple(tempSum2, i1, i3, x1, y1, x3, y3, 1);
    };

    while (X.size()) {
        dbg(X);
        dbg(Y);
        auto [sum1, i1, i2, x1, y1, x2, y2] =
            find_distanceX((*X.begin()), (*X.rbegin()));

        auto it = (Y.find({y1, {x1, i1}}));
        Y.erase(it);
        auto [sum2, i3, i4, x3, y3, x4, y4, f] =
            find_distanceY((*it), (*Y.begin()), (*Y.rbegin()));
        sum += max(sum1, sum2);
        Y.insert({y1, {x1, i1}});
        dbg(sum1, sum2);

        if (sum1 >= sum2) {
            ans.push_back({i1, i2});
            X.erase(X.begin());
            auto it = X.end();
            it--;
            X.erase(it);
            // akhn Y theke baad dite hobe
            Y.erase(Y.find({y1, {x1, i1}}));
            Y.erase(Y.find({y2, {x2, i2}}));
        }
        else {
            ans.push_back({i3, i4});
            auto it = (Y.find({y1, {x1, i1}}));
            Y.erase(it);
            X.erase(X.find({x1, {y1, i1}}));
            if (f == 0) {
                // begin remove korte hobe
                auto [y, temp] = *Y.begin();
                auto [x, ii] = temp;
                Y.erase({Y.begin()});
                X.erase(X.find({x, {y, ii}}));
            }
            else {
                auto it = Y.end();
                it--;
                auto [y, temp] = *it;
                auto [x, ii] = temp;
                Y.erase({it});
                X.erase(X.find({x, {y, ii}}));
            }
        }
        dbg(sum);
        dbg("--------------");
    }
    cout << sum << '\n';
    for (auto [x, y] : ans)
        cout << x + 1 << " " << y + 1 << '\n';
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