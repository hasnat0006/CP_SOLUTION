//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 25|05|2024 21:16:25            !//
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
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    vector<int> temp;
    for (int i = 0; i < n; i++){
        if(v[i] % v[0] != 0 and v[i] % v[1] != 0)
            temp.push_back(v[i]);
    }
    if(temp.size() == 0){
        cout << "YES" << endl;
        return;
    }
    sort(temp.begin(), temp.end());
    int x = temp[0];
    temp.clear();
    for (int i = 0; i < n; i++){
        if(v[i] % v[0] != 0 and v[i] % x != 0)
            temp.push_back(v[i]);
    }
    if(temp.size() == 0){
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;

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