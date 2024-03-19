//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 20|03|2024 01:45:41            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug.h"
#else 
#define dbg(x...)
#define dbgc(x...)
#endif
using namespace std;

#define int   long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

int mod = 1000000007;
int inf = 1e18;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    // dbg(s);
    vector<int> left(n), right(n + 5);
    int cntLeft = count(vf(s), '0');
    int cntRight = count(vf(s), '1');
    cntLeft = ceil(cntLeft / 2.0);
    cntRight = ceil(cntRight / 2.0);
    left[0] = s[0] == '0';
    for(int i = 1; i < n; i++){
        left[i] = left[i - 1] + (s[i] == '0');
    }
    right[n - 1] = s[n - 1] == '1';
    for(int i = n - 2; i >= 0; i--){
        right[i] = right[i + 1] + (s[i] == '1');
    }
    if(left.back() == n){
        cout << n << endl;
        return;
    }
    if(right[0] == n){
        cout << 0 << endl;
        return;
    }
    dbg(cntLeft, cntRight);
    dbg(left);
    dbg(right);
    vector<pair<float, int>> p;
    // n = n + 1;
    for(int i = 0; i < n; i++){
        if(left[i] >= cntLeft or right[i + 1] >= cntRight){
            p.push_back({abs((n / 2) - (i + 1)), i + 1});
        }
    }
    // line before the start of the string
    if(right[0] >= cntRight){
        p.push_back({abs(n / 2 - 0), 0});
    }
    // line after the end of the string
    if(left[n - 1] >= cntLeft){
        p.push_back({abs(n / 2 - n), n});
    }
    sort(vf(p));
    dbg(p);
    cout << p[0].second << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++){
        solve(); 
    }
    return 0;
}