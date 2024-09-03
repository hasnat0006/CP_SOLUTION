//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 09|06|2024 21:08:27            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

const int mod = 1e9 + 7;
const int inf = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int j = 0;
    while(j < n and v[j] <= 0){
        v[j] = abs(v[j]);
        j++;
    }
    int ans = 0, temp = 0;
    for (int i = 0; i < n; i++){
        if (v[i] <= 0) {
            temp += v[i];
        }
        else {
            ans = abs(ans + temp);
            ans += v[i];
            temp = 0;
        }
        // cerr << ans << " " << temp << endl;
    }
    ans = abs(ans + temp);
    cout << abs(ans) << endl;
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