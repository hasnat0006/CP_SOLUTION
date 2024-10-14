//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 01|03|2024 11:17:52            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

int mod = 1000000007;
int inf = 1e18;

char query(int a, int b, int c, int d) {
    cout << "? " << a << " " << b << " " << c << " " << d << endl;
    char ch;
    cin >> ch;
    return ch;
}

void solve() {
    int n;
    char c;
    cin >> n;
    int mx_pos = 0;
    for (int i = 1; i < n; i++) {
        if (query(mx_pos, mx_pos, i, i) == '<')
            mx_pos = i;
    }
    int second_mx = -1;
    for (int i = 0; i < n; i++) {
        if (i == mx_pos)
            continue;
        if (second_mx == -1)
            second_mx = i;
        else {
            char ch = query(second_mx, mx_pos, i, mx_pos);
            if (ch == '<')
                second_mx = i;
            else if (ch == '=') {
                if (query(second_mx, second_mx, i, i) == '>')
                    second_mx = i;
            }
        }
    }
    cout << "! " << mx_pos << " " << second_mx << endl;
}

int32_t main() {
    // ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}