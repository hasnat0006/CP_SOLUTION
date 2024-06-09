//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 09|06|2024 20:36:43            !//
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
    if (v.front() == v.back()) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    int f = 0;
    vector<char> ans(n, '.');
    for (int i = 1; i < n; i++) {
        if (v[i] == v[i - 1]) {
            ans[i] = 'R';
            f = 1;
            break;
        }
    }
    if(f == 0)
        ans[0] = 'R';
    for (int i = 0; i < n; i++){
        if(ans[i] == '.')
            ans[i] = 'B';
    }
    for(auto i : ans)
        cout << i;
    cout << endl;
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