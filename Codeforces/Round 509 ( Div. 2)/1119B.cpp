//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 14|03|2024 02:57:18            !//
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

int n, h, x;
vector<int> v;
bool isPossible(int k) {
    vector<int> a = v;
    sort(a.begin(), a.begin() + k);
    int H = 0;
    for (int i = k - 1; i >= 0; i -= 2)
        H += a[i];
    return H <= h;
}

void solve() {
    cin >> n >> h;
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int low = 1, high = n;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (isPossible(mid))
            low = mid + 1;
        else
            high = mid - 1;
    }
    cout << high << endl;
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