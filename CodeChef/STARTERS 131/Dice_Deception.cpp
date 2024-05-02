//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 24|04|2024 20:39:33            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

#define int   long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

const int mod = 1e9 + 7;
const int inf = 1e18;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(vf(v));
    map<int,int> mp;
    mp[1] = 6;
    mp[6] = 1;
    mp[2] = 5;
    mp[5] = 2;
    mp[3] = 4;
    mp[4] = 3;
    for(int i = 0; i < k; i++){
        if(v[i] < mp[v[i]])
            v[i] = mp[v[i]];
    }
    int sum = accumulate(vf(v), 0ll);
    cout << sum << endl;
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