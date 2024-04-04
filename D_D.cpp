//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 04|04|2024 11:29:23            !//
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

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

#define mod 1000000007;
#define inf 1000000000000000000;

void solve() {
    string s;
    cin >> s;
    s += s;
    int n = s.size();
    int R = 0, G = 0, B = 0;
    int ans = inf;
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == 'R')
            R = i;
        if (s[i - 1] == 'G')
            G = i;
        if (s[i - 1] == 'B')
            B = i;
        // dbg(s[i - 1], R, G, B);
        if (R > 0 and G > 0 and B > 0) {
            int operation = 0;
            vector<int> v = {R, G, B};
            sort(v.begin(), v.end());
            if (v.back() <= n / 2) {
                if (v[2] - v[1] > 1)
                    operation += 2;
                if (v[1] - v[0] > 1)
                    operation += 2;
                if (v[0] != 1)
                    operation++;
                if (v[2] != n / 2)
                    operation++;
                // if(v[0] == n / 2 or v[1] == n / 2 or v[2] == n / 2)
                //     operation--;
                dbg(v);
                dbg(i, operation);
                ans = min(ans, operation);
            }
            else {
                if (v.front() > n / 2) {
                    break;
                }
                vector<int> first, second;
                for (auto &i : v) {
                    if (i > n / 2)
                        second.push_back(i - n / 2);
                    else
                        first.push_back(i);
                }
                if (second.size() == 1) {
                    if (second[0] != 1)
                        operation += 2;
                    else
                        operation++;
                    if (first[1] - first[0] > 1)
                        operation += 2;
                    else
                        operation++;
                    if(first[0] != 1)
                        operation++;
                }
                else {
                    if (first[0] != n / 2)
                        operation += 2;
                    else
                        operation++;
                    if (second[1] - second[0] > 1)
                        operation += 2;
                    else
                        operation++;
                    if (second[0] != 1)
                        operation++;
                    // if (second[1] != n / 2)
                    //     operation++;
                }
                dbg(first, second);
                dbg(i, operation);
                ans = min(ans, operation);
            }
        }
    }
    cout << ans << endl;
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