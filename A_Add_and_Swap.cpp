//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 17|11|2024 18:52:13            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug.h"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const int mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    ll turn = 500000;
    vector<ll> ans; 

    ll mx = *max_element(vf(v));
    ll id = 0;
    while(v[id] != mx)
        id++;
    for(int i = id; i > 0; i--){
        ll a = v[i - 1], b = v[i];
        v[i - 1] = b + k;
        v[i] = a;
        turn--;
        ans.push_back(i);
    }
    dbg(v);

    while (!is_sorted(v.begin(), v.begin() + n - 1) and turn) {
        for (int i = 1; i < n - 1 and turn; i++) {
            while (v[i] < v[i - 1] and turn) {
                ll a = v[i], b = v[i + 1];
                v[i] = b + k;
                v[i + 1] = a;
                turn--;
                ans.push_back(i + 1);
            }
        }
                dbg(v);
    }
    if (n - 2 != 0) {
        while ((v[n - 2] < v[n - 3] or v[n - 1] < v[n - 3] or
                v[n - 2] > v[n - 1]) and
               turn) {
            ll a = v[n - 2], b = v[n - 1];
            v[n - 2] = b + k;
            v[n - 1] = a;
            turn--;
            ans.push_back(n - 1);
        }
    }
    while (v[n - 2] > v[n - 1] and turn) {
        ll a = v[n - 2], b = v[n - 1];
        v[n - 2] = b + k;
        v[n - 1] = a;
        turn--;
        ans.push_back(n - 1);
    }

    dbg(v);

    if (is_sorted(vf(v))) {
        cout << "Yes" << '\n';
        if (ans.size()) {
            cout << ans.size() << '\n';
            for (int i = 0; i < (int)ans.size(); i++) {
                cout << ans[i];
                if (i != (int)ans.size() - 1)
                    cout << ' ';
            }
            cout << '\n';
        }
    }
    else
        cout << "No" << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        //  cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}