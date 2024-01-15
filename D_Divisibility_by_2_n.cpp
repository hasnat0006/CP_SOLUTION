//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

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
    int baki = n;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        while (v[i] % 2 == 0) {
            v[i] /= 2;
            baki--;
        }
    }
    vector<int> temp;
    for (int i = 1; i <= n; i++) {
        int z = i, c = 0;
        while (z % 2 == 0) {
            z /= 2;
            c++;
        }
        temp.pb(c);
    }
    sort(vf(temp));
    int ans = 0;
    while (temp.size() and baki > 0) {
        baki -= temp.back();
        temp.pop_back();
        ans++;
    }
    if (baki > 0)
        cout << -1 << endl;
    else
        cout << ans << endl;
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        // case(i)
        solve();
    return 0;
}