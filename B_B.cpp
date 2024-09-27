//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 19|08|2024 21:02:38            !//
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
    string s = "";
    for(int i = 0; i < n; i++){
        s.push_back('z');
    }
    cout << "? " << s << endl;
    int x;
    cin >> x;
    string ans = "";
    for(int i = 0; i < n; i++){
        s[i] = 'a';
        cout << "? " << s << endl;
        int y;
        cin >> y;
        int temp = (25 - (x - y)) / 2;
        s[i] = 'a' + temp;
        x = x - 25 + temp;
    }
    cout << "! " << s << endl;

}

int32_t main() {
    // ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}