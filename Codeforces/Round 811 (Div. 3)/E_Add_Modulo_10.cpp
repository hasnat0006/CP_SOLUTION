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

/*
observation:
consider the last digit
0 -> 0;
1 -> 1,2,4,8,6; 1 + 20;
2 -> 2,4,8,6; 20;
3 -> 3, 6, 2, 4, 8; 3 + 20;
4 -> 4, 8, 6, 2; 20;
5 -> 5, 0; 5 + 0;
6 -> 6, 2, 4, 8; 20;
7 -> 7, 4, 8, 6, 2; 7 + 20;
8 -> 8, 6, 2, 4; 20;
9 -> 9, 8, 6, 2, 4; 9 + 20;
*/

bool is_possible(int x, int y) {
    if (x == y)
        return true;
    vector<int> temp;
    int xx = x;
    while (xx - x <= 20) {
        xx += xx % 10;
        if (xx == y)
            return true;
        if (xx % 10 == 0)
            break;
        temp.pb(xx);
    }
    for (auto i : temp) {
        if ((y - i) % 20 == 0)
            return true;
    }
    return false;
}

void solve() {
    int n, x;
    cin >> n;
    set<int> st;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x % 2)
            x += (x % 10);
        st.insert(x);
    }
    for (auto i : st)
        v.pb(i);
    int mx = v.back();
    for (auto i : v) {
        if (!is_possible(i, mx)) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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