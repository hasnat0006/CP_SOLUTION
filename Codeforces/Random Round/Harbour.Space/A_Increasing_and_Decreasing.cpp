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
    int suru, sesh, len;
    cin >> suru >> sesh >> len;
    vector<int> v(len);
    v[0] = suru;
    v[len - 1] = sesh;
    int c = 1;
    for (int i = len - 2; i > 0; i--) {
        v[i] = v[i + 1] - c;
        c++;
    }
    if (v[1] <= suru) {
        cout << -1 << endl;
        return;
    }
    dbg(v);
    set<int> st;
    for (int i = 1; i < len; i++) {
        st.insert(v[i] - v[i - 1]);
    }
    if (st.size() != len - 1) {
        cout << -1 << endl;
        return;
    }
    for (auto i : v)
        cout << i << " ";
    cout << endl;
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