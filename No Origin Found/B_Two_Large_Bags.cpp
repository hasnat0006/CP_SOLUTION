    #pragma GCC optimize("O3")
    #include <bits/stdc++.h>
    #ifndef ONLINE_JUDGE
    #include "D:\Documents\debug1.cpp"
    #else
    #define dbg(x...)
    #define dbgc(x...)
    #endif
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
        map<ll, ll> cnt;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            cnt[v[i]]++;
        }
        sort(vf(v));
        if (cnt[v[0]] == 1) {
            cout << "No" << '\n';
            return;
        }
        map<int, int> store;
        ll pre = 0;
        for (auto [a, b] : cnt) {
            store[a] = pre;
            pre += b;
        }
        cnt.erase(v[0]);
        for (auto [a, b] : cnt) {
            if (b % 2 == 0)
                continue;
            ll diff = abs(a - v[0]);
            ll need = (2 * diff + 1) - (cnt.count(a - 1) ? b - 1 : 0);
            dbg(diff, store[a], need);
            if (store[a] < need) {
                cout << "No" << '\n';
                return;
            }
        }
        cout << "Yes" << '\n';
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