//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 03|03|2024 21:36:11            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

int mod = 1000000007;
int inf = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<int> even, odd;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        (x % 2 == 0) ? even.push_back(x) : odd.push_back(x);
    }
    if(even.size() == 0 or odd.size() == 0) {
        cout << "-1" << endl;
        return;
    }
    for(auto i : even) 
        cout << i << " ";
    for(auto i : odd) 
        cout << i << " ";
    cout << endl;
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