//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 03|04|2024 01:42:38            !//
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

// #define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

#define mod 1000000007;
#define inf 1000000000000000000;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<int> seq;
    /*
    here we basically check is the current element from v is greater than the last element of the sequence. 
    if it is then push it to the seq array and if not then replace that index value.
    let's take an example:
    v = 7 3 5 3 6 2 9 8
    1st iteration seq = 7;
    2nd iteration seq = 3;
    3rd iteration seq = 3 5;
    4th iteration seq = 3 3;
    5th iteration seq = 3 3 6;
    6th iteration seq = 2 3 6;
    7th iteration seq = 2 3 6 9;
    8th iteration seq = 2 3 6 8;
    */
    for(auto i : v){
        auto id = lower_bound(seq.begin(), seq.end(), i);
        if(id == seq.end())
            seq.push_back(i);
        else
            seq[id - seq.begin()] = i;
    }
    cout << seq.size() << endl;
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