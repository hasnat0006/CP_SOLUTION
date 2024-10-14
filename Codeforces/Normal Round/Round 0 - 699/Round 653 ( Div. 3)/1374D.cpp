//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 18|03|2024 01:35:13            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

#define int   long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

int mod = 1000000007;
int inf = 1e18;

void solve() {
    int n, k, x;
    cin >> n >> k;
    map<int,int> mp;
    for(int i = 0; i < n; i++){
        cin >> x;
        mp[x % k]++;
    }    
    int ans = 0;
    for(auto i : mp){
        if(i.first == 0) continue;
        ans = max(ans, (i.second - 1) * k + (k - i.first + 1));
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