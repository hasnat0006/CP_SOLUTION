//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 07|03|2024 21:20:33            !//
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
    int n, w, wr;
    cin >> n >> w >> wr;
    vector<int> v(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++)
        cin >> v[i], mp[v[i]]++;
    if (wr >= w) {
        cout << "YES" << endl;
        return;
    }
    w -= wr;
    for (auto x : mp) {
        if (x.second % 2 == 0)
            w -= x.first * x.second;
        else
            w -= x.first * (x.second - 1);
    }
    if (w <= 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

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