//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 22|09|2024 15:37:15            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

const int mod = 1e9 + 7;
const int inf = 1e18;

vector<int> divisor(int n) {
    vector<int> div;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            div.push_back(i);
            div.push_back(n / i);
        }
    }
    return div;
}


int lcm(int a, int b) {
    return (a * b) / __gcd(a, b);
}

void solve() {
    int n;
    cin >> n;
    vector<int> v = divisor(n);
    int mn = inf;
    pair<int, int> ans;
    for(int i = 0; i < v.size() ; i++){
        int x = v[i], y = n / x;
        if(max(x, y) < mn and lcm(x, y) == n){
            mn = max(x, y);
            ans = {x, y};
        }
    }
    cout << ans.first << " " << ans.second << endl;
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