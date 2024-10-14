//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 14|10|2024 10:57:39            !//
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

string num = "0123456789ACDEFHJKLMNPRTVWX";
int mToTen(string n, int m) {
    int multi = 1;
    int result = 0;
    for (int i = n.size() - 1; i >= 0; i--) {
        result += num.find(n[i]) * multi;
        multi *= m;
    }
    return result;
}

bool isOctal(string s) {
    for(auto i : s)
        if(i > '7')
            return false;
    return true;
}

void solve() {
    int n, num;
    cin >> n >> num;
    string s = to_string(num);
    cout << n << " ";
    if (isOctal(s))
        cout << mToTen(s, 8) << " ";
    else
        cout << 0LL << " ";
    cout << s << " ";
    cout << mToTen(s, 16) << "\n";
    cout << mToTen("12345678", 27) << endl;
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