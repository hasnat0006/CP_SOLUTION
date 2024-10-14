//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 12|10|2024 21:25:44            !//
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
    int n, b;
    cin >> n >> b;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int m, c;
    cin >> m >> c;
    vector<int> d(m);
    for (int i = 0; i < m; i++) {
        cin >> d[i];
    }
    reverse(vf(a));
    reverse(vf(d));
    auto calculation = [](int n, int b, vector<int> &a) {
        int num = 0, power = 1;
        for (int i = 0; i < n; i++) {
            int x = a[i];
            num += x * power;
            power *= b;
        }
        return num;
    };
    int num1 = calculation(n, b, a);
    int num2 = calculation(m, c, d);
    if (num1 > num2) {
        cout << ">" << endl;
    }
    else if (num1 < num2) {
        cout << "<" << endl;
    }
    else {
        cout << "=" << endl;
    }
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