
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

    auto ask1 = [n](ll x) {
        cout << "? " << x << " " << n;
        for (int i = 1; i <= n; i++)
            cout << " " << i;
        cout << endl;
        ll reply;
        cin >> reply;
        return reply;
    };

    map<ll, ll> mp;
    for (int i = 0; i < n; i++) {
        mp[i + 1] = ask1(i + 1);
    }
    ll mxNum = 1, mx = 1;
    for (auto [num, cnt] : mp) {
        if (cnt > mx) {
            mxNum = num, mx = cnt;
        }
    }
    // dbg(mxNum, mx);

    vector<pair<ll, ll>> v;
    for (auto [num, cnt] : mp) {
        if (mxNum != num)
            v.push_back({cnt, num});
    }
    sort(vr(v));

    // dbg(v);

    vector<ll> ans = {mxNum};
    auto ask2 = [&](ll y) {
        cout << "? " << mxNum;
        cout << " " << ans.size() + 1;
        for (auto i : ans) {
            cout << " " << i;
        }
        cout << " " << y;
        cout << endl;
        ll reply;
        cin >> reply;
        return reply;
    };

    ll i = 0;
    while (i < v.size()) {
        ll j = i;
        vector<pair<ll, ll>> temp = {
            {ask2(v[j].second) + mp[v[j].second] - 1, v[j].second}};
        while (j + 1 < v.size() and v[j].first == v[j + 1].first) {
            // dbg(j);
            temp.push_back({ask2(v[j + 1].second) + mp[v[j + 1].second] - 1,
                            v[j + 1].second});
            j++;
        }
        sort(vf(temp));
        // dbg(temp);
        if (temp.back().first > ans.size())
            ans.push_back(temp.back().second);
        // dbg(i, j);
        i = j;
        i++;

        // dbg(i, j);
    }

    // dbg(ans);
    cout << "! " << ans.size();
    for (int i : ans)
        cout << " " << i;
    cout << endl;
    cout.flush();
    return;
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}