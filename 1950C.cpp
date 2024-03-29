//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 28|03|2024 21:11:15            !//
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

void convert24hourto12hour(string str) {
    int h1 = (int)str[0] - '0';
    int h2 = (int)str[1] - '0';
    int hh = h1 * 10 + h2;
    string time;
    if (hh < 12) {
        time = "AM";
        if (hh == 0) {
            cout << "12";
            for (int i = 2; i < 5; i++)
                cout << str[i];
        }
        else {
            if(hh < 10)
                cout << "0" << hh;
            else
                cout << hh;
            for (int i = 2; i < 5; i++)
                cout << str[i];
        }
    }
    else {
        time = "PM";
        if (hh == 12) {
            cout << "12";
            for (int i = 2; i < 5; i++)
                cout << str[i];
        }
        else {
            if(hh - 12 < 10)
                cout << "0" << hh - 12;
            else
                cout << hh - 12;
            for (int i = 2; i < 5; i++)
                cout << str[i];
        }
    }
    cout << " " << time << endl;
    
}

void solve() {
    string s;
    cin >> s;
    convert24hourto12hour(s);
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