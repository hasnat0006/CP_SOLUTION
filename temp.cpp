//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 13|05|2024 00:18:39            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

const int mod = 1e9 + 7;
const int inf = 1e18;

int factor(int n){
    int a;
    if (n % 2 == 0)
        return 2;
    for (a = 3; a <= sqrtl(n); a += 2){
        if (n % a == 0)
            return a;
    }
    return n;
}


void solve() {
    int n;
    cin >> n;
    map<int,int> cnt;
    while(n > 1){
        int r = factor(n);
        cout << r << " ";
        cnt[r]++;
        n /= r;
    }
    int mx = 0;
    for(auto i : cnt)
        mx = max(mx, i.second);
    cout << mx << endl;
}

int32_t main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++){
        // cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}
