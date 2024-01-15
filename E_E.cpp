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
    int n, k, l;
    cin >> n >> k >> l;
    int nn = n * k;
    vector<int> v(nn);
    for (int i = 0; i < nn; i++)
        cin >> v[i];
    sort(vf(v));
    int max_diff = v[n - 1] - v[0];
    if (max_diff > l) {
        cout << 0 << endl;
        return;
    }
    int ll = l + v.front();
    int id = upper_bound(vf(v), ll) - v.begin() - 1;
    int possible = id - (n - 1);
    dbg(id, possible);
    int ans = 0;
    int cnt = 0;
    map<int, int> freq;
    for (int i = 0; i < nn and cnt != n and i <= id; i += k) {
        ans += v[i];
        freq[i] = 1;
        cnt++;
    }
    for(int i = id; i >= 0 and cnt != n; i--){
        if(freq[i])
            continue;
        ans += v[i];
        cnt++;
    }
    cout << ans << endl;
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        // case(i)
        solve();
    }
    return 0;
}