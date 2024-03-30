//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 26|02|2024 21:06:32            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

#define int   long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

int mod = 1000000007;
int inf = 1e18;

void solve() {
    string s;
    cin >> s;
    int left = 0, right = 0;
    int id = s.find('^');
    for (int i = 0; i < id; i++) {
        if (s[i] >= '0' && s[i] <= '9')
            left += (id - i) * (s[i] - '0');
    }
    for (int i = id + 1; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9')
            right += (i - id) * (s[i] - '0');
    }
    (left == right) ? cout << "balance" << endl : (left > right) ? cout << "left" << endl : cout << "right" << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++){
        solve(); 
    }
    return 0;
}