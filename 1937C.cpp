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

void solve() {
    int n;
    cin >> n;
    int mx_pos = 0;
    for (int i = 1; i <= n - 1; i++) {
        cout << "? " << mx_pos << " " << mx_pos << " " << i << " " << i << endl;
        cout << fflush;
        char ch;
        cin >> ch;
        if (ch == '<')
            mx_pos = i;
    }
    int j = 0;
    vector<int> isPossible;
    for (int i = 0; i < n; i++) {
        cout << "? " << mx_pos << " " << i << " " << mx_pos << " " << j << endl;
        cout << fflush;
        char ch;
        cin >> ch;
        if (ch == '>')
            isPossible.clear(), isPossible.push_back(i);
        else if (ch == '=')
            isPossible.push_back(i);
    }
    if (isPossible.size() == 1) {
        cout << "! " << mx_pos << " " << j << endl;
        cout << fflush;
    }
    else {
        int mn_pos = isPossible[0];
        for (int i = 1; i < isPossible.size(); i++) {
            cout << "? " << mn_pos << " " << mn_pos << " " << isPossible[i] << " " << isPossible[i] << endl;
            cout << fflush;
            char ch;
            cin >> ch;
            if (ch == '>')
                mn_pos = isPossible[i];
        }
        cout << "! " << mx_pos << " " << mn_pos << endl;
        cout << fflush;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}