//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 12|10|2024 22:57:17            !//
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

char a[16] = {'0', '1', '2', '3', '4', '5', '6', '7',
              '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
string tenToM(int n, int m) {
    int temp = n;
    string result = "";
    while (temp != 0) {
        result = a[temp % m] + result;
        temp /= m;
    }
    return result;
}

string num = "0123456789ABCDE";
int mToTen(string n, int m) {
    int multi = 1;
    int result = 0;
    for (int i = n.size() - 1; i >= 0; i--) {
        result += num.find(n[i]) * multi;
        multi *= m;
    }
    return result;
}

void solve() {
    int base, num;
    cin >> base >> num;
    string s = to_string(num);
    cout << mToTen(s, base) << endl;
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