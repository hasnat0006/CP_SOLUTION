//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 20|03|2024 01:15:18            !//
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
    int in, ex,bo;
    cin >> in >> ex >> bo;
    int needEx = (ex % 3) != 0 ? 3 - (ex % 3) : 0;
    if(needEx > bo){
        cout << -1 << endl;
        return;
    }
    int ans = in;
    ans += (ex + needEx) / 3;
    ans += (bo - needEx) / 3;
    if((bo - needEx) % 3 != 0){
        ans++;
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