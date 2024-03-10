//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 03|03|2024 21:15:30            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

int mod = 1000000007;
int inf = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<int> v;
    set<int> s;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }
    if (s.size() == 1) {
        cout << "YES" << endl;
        return;
    }
    for (auto i : s) {
        v.push_back(i);
    }
    n = v.size();
    if (n % 2 == 1) {
        int mid = v[n / 2];
        set<int> s;
        for (int i = 0; i < n; i++) {
            s.insert(abs(v[i] - mid));
        }
        (s.size() < 3) ? cout << "YES" << endl : cout << "NO" << endl;
    }
    else {
        int mid = v[n / 2];
        int mid1 = v[n / 2 - 1];
        set<int> s1, s2;
        for (int i = 0; i < n; i++) {
            s1.insert(abs(v[i] - mid));
            s2.insert(abs(v[i] - mid1));
        }
        (s1.size() < 3 or s2.size() < 3) ? cout << "YES" << endl : cout << "NO" << endl;
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