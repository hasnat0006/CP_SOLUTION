//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "C:\Users\Yusuf Reza Hasnat\OneDrive\Desktop\CP\debug.h"
#else
#define dbg(x...)
#define dbgc(x...)
#endif

using namespace std;

#define int long long
#define float long double
#define pb push_back
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define dosomic(x) fixed << setprecision(x)
#define endl "\n"
#define case(x) cout << "Case " << x << ": "
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)

int mod = 1000000007;
float pi = acos(-1);
int inf = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    int even = 0, odd = 0;
    int lcm = 1, gcd = 1;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        // lcm = lcm * v[i] / __gcd(lcm, v[i]);
        if (v[i] % 2 == 0)
            even++;
        else
            odd++;
    }
    gcd = v[0];
    // for (int i = 1; i < n; i++)
    //     gcd = __gcd(gcd, v[i]);
    // dbg(gcd);
    if (even and odd) {
        cout << 2 << endl;
        return;
    }
    int ans = 2;
    for (int i = 2; ; i++) {
        set<int> st;
        for (int j = 0; j < n; j++) {
            st.insert(v[j] % ans);
            if(st.size() > 2)
                break;
        }
        if (st.size() == 2) {
            dbg(st);
            cout << ans << endl;
            return;
        }
        ans *= 2;
    }
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // case(i)
        solve();
    }
    return 0;
}