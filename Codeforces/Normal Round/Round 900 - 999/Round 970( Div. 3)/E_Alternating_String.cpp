//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 01|09|2024 21:42:32            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug.h"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
using namespace std;

#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

const int mod = 1e9 + 7;
const int inf = INT_MAX;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    if (n < 3 and n % 2 == 1) {
        cout << n << endl;
        return;
    }
    if (n % 2) {
        vector<vector<int>> vOdd(n, vector<int>(26, 0)),
            vEven(n, vector<int>(26, 0));
        for (int i = 0; i < n; i++) {
            i % 2 ? vOdd[i][s[i] - 'a']++ : vEven[i][s[i] - 'a']++;
        }
        vector<vector<int>> dpOddSuff(n, vector<int>(26, 0)),
            dpEvenSuff(n, vector<int>(26, 0));
        dpOddSuff[n - 1] = vOdd[n - 1];
        dpEvenSuff[n - 1] = vEven[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < 26; j++) {
                dpOddSuff[i][j] += dpOddSuff[i + 1][j] + vOdd[i][j];
                dpEvenSuff[i][j] = dpEvenSuff[i + 1][j] + vEven[i][j];
            }
        }
        vector<vector<int>> dpOddPre(n, vector<int>(26, 0)),
            dpEvenPre(n, vector<int>(26, 0));

        dpOddPre[0] = vOdd[0];
        dpEvenPre[0] = vEven[0];

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 26; j++) {
                dpOddPre[i][j] += dpOddPre[i - 1][j] + vOdd[i][j];
                dpEvenPre[i][j] = dpEvenPre[i - 1][j] + vEven[i][j];
            }
        }

        int ans = inf;
        for (int i = 1; i < n - 1; i++) {
            vector<int> EVEN(26, 0), ODD(26, 0);
            for (int j = 0; j < 26; j++) {
                EVEN[j] = dpEvenPre[i - 1][j] + dpOddSuff[i + 1][j];
                ODD[j] = dpOddPre[i - 1][j] + dpEvenSuff[i + 1][j];
            }
            int mx1 = *max_element(vf(EVEN));
            int mx2 = *max_element(vf(ODD));
            ans = min(ans, (n - mx1 - mx2));
        }
        vector<int> EVEN(26, 0), ODD(26, 0);
        if (n >= 2) {
            EVEN = dpOddSuff[1];
            ODD = dpEvenSuff[1];
        }
        int mx1 = *max_element(vf(EVEN));
        int mx2 = *max_element(vf(ODD));
        ans = min(ans, (n - mx1 - mx2));
        EVEN.clear();
        ODD.clear();
        if (n >= 2) {
            EVEN = dpEvenPre[n - 2];
            ODD = dpOddPre[n - 2];
        }
        mx1 = *max_element(vf(EVEN));
        mx2 = *max_element(vf(ODD));
        ans = min(ans, (n - mx1 - mx2));
        cout << ans << endl;
    }
    else {
        vector<int> vOdd(26, 0), vEven(26, 0);
        for (int i = 0; i < n; i++) {
            if (i % 2) {
                vOdd[s[i] - 'a']++;
            }
            else {
                vEven[s[i] - 'a']++;
            }
        }
        int maxOdd = *max_element(vOdd.begin(), vOdd.end());
        int maxEven = *max_element(vEven.begin(), vEven.end());
        int ans = n - maxOdd - maxEven;
        cout << ans << endl;
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