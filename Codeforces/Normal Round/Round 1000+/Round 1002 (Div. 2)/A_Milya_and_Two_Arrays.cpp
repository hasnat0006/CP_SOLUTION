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
    vector<ll> a(n), b(n);
    map<int, int> A, B;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        A[a[i]]++;
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        B[b[i]]++;
    }
    ll sz = A.size() + B.size();
    // cout << sz << endl;
    cout << (sz <= 3 ? "NO" : "YES") << "\n";
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