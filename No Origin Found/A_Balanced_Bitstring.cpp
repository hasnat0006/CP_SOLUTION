//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 04|11|2024 15:16:05            !//
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

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const int mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    map<int, set<char>> mp;
    for (int i = 0; i < n; i++) {
        if (s[i] != '?')
            mp[i % k].insert(s[i]);
    }
    dbg(mp);
    for(auto &i : mp){
        if(i.second.size() > 1){
            cout << "NO" << '\n';
            return;
        }
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == '?' and mp[i % k].size() > 0)
            s[i] = *mp[i % k].begin();
    }
    dbg(s);
    deque<char> dq;
    int one = 0, zero = 0;
    for(int i = 0; s[i]; i++){
        if(s[i] == '0')
            zero++;
        else if(s[i] == '1')
            one++;
        dq.push_back(s[i]);
        if(dq.size() == k){
            int ques = k - one - zero;
            int need = k / 2;
            dbg(zero, one, need, ques);
            if(one > need or zero > need){
                cout << "NO" << '\n';
                return;
            }
            ques -= ((need - one) + (need - zero));
            dbg(ques);
            if(ques != 0){
                cout << "NO" << '\n';
                return;
            }
            if(dq.front() == '1')
                one--;
            else if(dq.front() == '0')
                zero--;
            dq.pop_front();
        }
    }
    cout << "YES" << '\n';
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