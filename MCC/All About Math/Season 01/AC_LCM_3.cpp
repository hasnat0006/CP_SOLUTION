//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 22|09|2024 15:20:52            !//
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

int sumOfLcm(vector<int> &a) {
    int n = a.size();
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        int lcm = (i * a[i - 1]) / __gcd(i, a[i - 1]);
        sum += lcm;
    }
    return sum;
}

void solve() {
    int n;
    cin >> n;
    // vector<int> a(n);
    // for (int i = 1; i <= n; i++) {
    //     a[i - 1] = i;
    // }
    // map<int, vector<int>> mp;
    // do {
    //     int sum = sumOfLcm(a);
    //     mp[sum] = a;
    // } while (next_permutation(vf(a)));
    // for(auto x: mp){
    //     cout << x.first << " : ";
    //     for(auto y: x.second){
    //         cout << y << " ";
    //     }
    //     cout << endl;
    // }
    if (n % 2) {
        cout << 1 << " ";
        for (int i = 2; i <= n; i++) {
            cout << i + (i % 2 == 0 ? 1 : -1) << " ";
        }
    }
    else {
        for (int i = 1; i <= n; i++) {
            cout << i + (i % 2 ? 1 : -1) << " ";
        }
    }
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