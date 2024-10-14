//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 04|08|2024 20:44:19            !//
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
    int n, x;
    cin >> n;
    vector<int> even, odd;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x % 2 == 0)
            even.push_back(x);
        else
            odd.push_back(x);
    }
    if(even.empty() or odd.empty()){
        cout << 0 << endl;
        return;
    }
    int ans = even.size();
    sort(vf(even));
    sort(vf(odd));
    int sum = 0, cur = odd.back();
    for (int i = 0; i < even.size(); i++) {
        if(even[i] > cur){
            ans += 1;
            break;
        }
        cur += even[i];
    }
    cout << ans << endl;
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