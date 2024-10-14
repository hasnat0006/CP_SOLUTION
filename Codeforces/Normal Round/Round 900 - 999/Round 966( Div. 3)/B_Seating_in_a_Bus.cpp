//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 13|08|2024 20:52:26            !//
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

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    map<int, int> mp;
    mp[v[0]] = 1;
    for (int i = 1; i < n; i++){
        int num = v[i];
        if(v[i] == n){
            if(mp[v[i] - 1] == 1){
                mp[v[i]] = 1;
            }
            else{
                cout << "NO" << endl;
                return;
            }
        }
        else if(v[i] == 1){
            if(mp[v[i] + 1] == 1){
                mp[v[i]] = 1;
            }
            else{
                cout << "NO" << endl;
                return;
            }
        }
        else{
            if(mp[v[i] - 1] == 1 or mp[v[i] + 1] == 1){
                mp[v[i]] = 1;
            }
            else{
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
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