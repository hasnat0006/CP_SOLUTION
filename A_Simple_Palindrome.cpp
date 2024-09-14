//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 14|09|2024 20:37:21            !//
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
    int count = n / 5;
    int rem = n % 5;
    char arr[5] = {'a', 'e', 'i', 'o', 'u'};
    string ans;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < count; j++){
            ans += arr[i];
        }
    }
    for(int i = 0; i < rem; i++){
        ans += arr[i];
    }
    sort(vf(ans));
    cout << ans << endl;
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