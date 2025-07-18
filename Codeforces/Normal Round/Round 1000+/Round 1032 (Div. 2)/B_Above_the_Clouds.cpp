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
    string s;
    cin >> s;
    map<char, ll> cnt;
    cnt[s[n - 1]]++;
    cnt[s[0]]++;
    for (int i = 1; i < n - 1; i++) {
        if (cnt[s[i]] != 0) {
            cout << "Yes" << "\n";
            return;
        }
        cnt[s[i]]++;
    }
    cout << "No" << "\n";
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