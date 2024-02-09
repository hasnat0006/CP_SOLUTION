//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)

int mod = 1000000007;
int inf = 1e18;

bool isPrime(int n) {
    if (n < 4)
        return true;
    if (n % 2 == 0)
        return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0)
            return false;
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    bool one = false;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 1)
            one = true;
    }
    if (one) {
        cout << n << '\n';
        return;
    }
    sort(a.begin(), a.end());
    map<int, int> mp;
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        if (mp[a[i]] < 0)
            continue;
        if (isPrime(a[i])) {
            v.push_back(a[i]);
            mp[a[i]] = -a[i];
            continue;
        }
        bool found = false;
        for (int j = 0; j < v.size(); ++j) {
            if (a[i] % v[j] == 0) {
                // a[i] = v[j];
                mp[a[i]] = -v[j];
                found = true;
                break;
            }
        }
        if (!found) {
            v.push_back(a[i]);
            mp[a[i]] = -a[i];
        }
    }
    long long res = 0;
    for (int i : a)
        res += -mp[i];
    cout << res << endl;
}
int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}