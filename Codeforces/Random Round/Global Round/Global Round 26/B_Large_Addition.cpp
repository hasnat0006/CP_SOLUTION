//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 09|06|2024 20:50:30            !//
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
    string s;
    cin >> s;
    int n = s.size();
    if(s.front() > '1'){
        cout << "NO" << endl;
        return;
    }
    string ans1, ans2;
    int carry = 0;
    for (int i = n - 1; i > 0; i--){
        int x = s[i] - '0' - carry;
        if(x < 0 or x > 8){
            cout << "NO" << endl;
            return;
        }
        carry = 1;
        x = x + 10;
        int half = x / 2;
        ans1.insert(0, to_string(half));
        ans2.insert(0, to_string(x - half));
    }
    cout << "YES" << endl;
    // cout << ans1 << " " << ans2 << endl;
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