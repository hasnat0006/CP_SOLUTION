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
    map<string, int> mp;
    for (int i = 0; i < n; i++) {
        string x;
        cin >> x;
        mp[x]++;
    }
    int a = mp["A"];
    int o = mp["O"];
    int b = mp["B"];
    int ab = mp["AB"];
    int ans = 1;
    for (auto x : mp) {
        if (x.first == "O") {
            ans = max(ans, o + max(a, b) + ab);
        }
        else if (x.first == "A") {
            ans = max(ans, a + ab);
        }
        else if (x.first == "B") {
            ans = max(ans, b + ab);
        }
        else if (x.first == "AB") {
            ans = max(ans, ab);
        }
    }
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