//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 16|10|2024 00:38:45            !//
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
    string s1, s2;
    cin >> s1 >> s2;
    string fin = "", temp;
    for (auto i : s1) {
        if (i == '.') {
            bitset<8> t = stoll(temp);
            fin += (t.to_string());
            fin.push_back('.');
            temp = "";
        }
        else
            temp.push_back(i);
    }
    bitset<8> t = stoll(temp);
    fin += (t.to_string());
    cout << (fin == s2 ? "Yes" : "No") << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}