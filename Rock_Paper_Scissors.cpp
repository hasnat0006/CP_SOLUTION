//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "C:\Users\Yusuf Reza Hasnat\OneDrive\Desktop\CP\debug.h"
#else
#define dbg(x...)
#define dbgc(x...)
#endif

using namespace std;

#define int long long
#define float long double
#define pb push_back
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define dosomic(x) fixed << setprecision(x)
#define endl "\n"
#define case(x) cout << "Case " << x << ": "
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)

int mod = 1000000007;
float pi = acos(-1);
int inf = 1e18;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string ans = "";
    int win = (n / 2) + 1;
    int go = n - win;
    // P R S
    for (int i = 0; i < go and i < n; i++) {
        if (s[i] != 'P') {
            ans.push_back('P');
            if (s[i] == 'R')
                go++, win--;
        }
        else if (s[i] != 'R') {
            ans.push_back('R');
            if (s[i] == 'S')
                go++, win--;
        }
        else if (s[i] != 'S') {
            ans.push_back('S');
            if (s[i] == 'P')
                go++, win--;
        }
    }
    dbg(go, win);
    for (int i = go; i < n; i++) {
        if (n - i - 1 <= win) {
            if (s[i] == 'P')
                ans.push_back('S');
            else if (s[i] == 'R')
                ans.push_back('P');
            else if (s[i] == 'S')
                ans.push_back('R');
            dbg("here");
        }
        else {
            if (s[i] != 'P') {
                ans.push_back('P');
                if (s[i] == 'R')
                    go++, win--;
            }
            else if (s[i] != 'R') {
                ans.push_back('R');
                if (s[i] == 'S')
                    go++, win--;
            }
            else if (s[i] != 'S') {
                ans.push_back('S');
                if (s[i] == 'P')
                    go++, win--;
            }
        }
    }
    cout << ans << endl;
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // case(i)
        solve();
    }
    return 0;
}