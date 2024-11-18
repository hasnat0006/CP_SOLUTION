//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 18|11|2024 19:01:27            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n;
    cin >> n;

    auto ask = [](string s) {
        cout << 1 << " " << s << endl;
        int x;
        cin >> x;
        return x;
    };

    ll zero = ask("0");
    ll one = n - zero;
    if (zero == n) {
        cout << "0 1 0" << endl;
    }
    else if (zero == 0) {
        cout << "0 1 1" << endl;
    }
    else {
        ll oneZero = ask("10");
        if(oneZero == 0){
            cout << "0 " << n << " 1" << endl;
            return;
        }
        ll zeroOne = ask("01");
        if (zeroOne == 0) {
            cout << "0 " << n << " 0" << endl;
            return;
        }
        if (oneZero > zeroOne) {
            cout << "0 1 1" << endl;
        }
        else if (oneZero < zeroOne)
            cout << "0 1 0" << endl;
        else {
            if(zero > one)
                cout << "0 1 0" << endl;
            else
                cout << "0 1 1" << endl;
        }
    }
    
}

int32_t main() {
    // ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    ll t = 1;
    cin >> t;
    for (ll i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";
        solve();
        int x;
        cin >> x;
    }
    return 0;
}