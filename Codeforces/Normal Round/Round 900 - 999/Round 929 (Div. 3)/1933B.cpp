//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 27|02|2024 20:38:16            !//
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
    vector<int> a(n);
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] % 3 == 1)
            cnt1++;
        if (a[i] % 3 == 2)
            cnt2++;
    }
    int sum = accumulate(vf(a), 0LL);
    // cout << sum << endl;
    if(sum % 3 == 0){
        cout << 0 << endl;
        return;
    }
    if((sum + 1) % 3 == 0){
        cout << 1 << endl;
        return;
    }
    else{
        if(cnt1 >= 1)
            cout << 1 << endl;
        else
            cout << 2 << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}