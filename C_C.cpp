//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 12|03|2024 22:07:09            !//
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
    string s;
    cin >> s;
    int f = s[0] == 'C' ? 1 : 0;
    string fn = "";
    s[0] == 'C' ? fn += 'C' : fn += s[0];
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i - 1])
            continue;
        else
            fn.push_back(s[i]);
    }
    // cout << fn << endl;
    // int f = 0;
    // for(int i = 0; i < s.size(); i++){
    //     if(s[i] == 'S')
    //         f = 1;
    //     else if(f == 1){
    //         cout << "no" << endl;
    //         return;
    //     }
    // }
    // cout << "yes" << endl;
    int c = -1, e = -1, S = -1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'C')
            c = i;
        else if (s[i] == 'E')
            e = i;
        else if (s[i] == 'S')
            S = i;
    }
    if (fn.size() == 3) {
        if (c < e && e < S)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    else {
        if (c != -1 && e != -1) {
            if (c < e)
                cout << "yes" << endl;
            else
                cout << "no" << endl;
        }
        else if (e != -1 && S != -1) {
            if (e < S)
                cout << "yes" << endl;
            else
                cout << "no" << endl;
        }
        else if (c != -1 && S != -1) {
            if (c < S)
                cout << "yes" << endl;
            else
                cout << "no" << endl;
        }
        else
            cout << "yes" << endl;
    }
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