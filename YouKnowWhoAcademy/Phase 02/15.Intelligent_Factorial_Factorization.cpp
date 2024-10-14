//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 14|10|2024 20:04:02            !//
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

// smallest prime factor of a number.
int factors(int n) {
    if (n % 2 == 0)
        return 2;
    for (int a = 3; a <= sqrt(n); a++) {
        if (n % a == 0)
            return a;
    }
    return n;
}

void solve() {
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 2; i <= n; i++) {
        int num = i;
        while (num > 1) {
            int r = factors(num);
            num /= r;
            mp[r]++;
        }
    }
    cout << n << " = ";
    string s = "";
    for (auto i : mp) {
        s += to_string(i.first);
        s += " (";
        s += to_string(i.second);
        s += ") * ";
    }
    s.pop_back();
    s.pop_back();
    cout << s << endl;
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