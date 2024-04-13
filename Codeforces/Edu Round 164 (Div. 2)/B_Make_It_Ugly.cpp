//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 12|04|2024 21:18:32            !//
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

const int mod = 1e9 + 7;
const int inf = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    set<int> s;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        s.insert(v[i]);
    }
    if(s.size() == 1) {
        cout << -1 << endl;
        return;
    }
    vector<int> id;
    for(int i = 1; i < n - 1; i++){
        if(v[i - 1] == v[i + 1] and v[i] != v[i - 1] and v[i] != v[i + 1]){
            id.push_back(i);
        }
    }
    dbg(id);
    int ans = inf;
    for(int i = 0; i < id.size(); i++){
        int left = id[i] - 1, right = id[i] + 1;
        dbg(left, right);
        while(v[left] == v[id[i] - 1] and left >= 0){
            left--;
        }
        while(v[right] == v[id[i] + 1] and right < n){
            right++;
        }
        left++, right--;
        dbg(left, right);
        dbg(id[i] - left, right - id[i]);
        ans = min({ans, id[i] - left, right - id[i]});
        dbg(left, right, ans);
    }
    cout << ans << endl;
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