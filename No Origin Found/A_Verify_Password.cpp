//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 30|05|2024 20:36:33            !//
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
    string s;
    cin >> s;
    string letter, num;
    int i = 0;
    if (s.front() >= '0' && s.front() <= '9') {
        for (i = 0; i < n; i++) {
            if (s[i] >= '0' && s[i] <= '9')
                num += s[i];
            else
                break;
        }
    }
    for(; i < n; i++)
        letter += s[i];
    if(is_sorted(vf(num)) && is_sorted(vf(letter)))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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