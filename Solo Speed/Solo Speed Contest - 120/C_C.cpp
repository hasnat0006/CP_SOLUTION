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

bool check(int x, int y) {
    if (x > 0 and y < 0)
        return true;
    if (x < 0 and y > 0)
        return true;
    return false;
}

void solve() {
    int n, c = 1, id = -1;
    cin >> n;
    vector<int> v(n), ans(n, 1);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (int i = 0; i < n - 1; i++) {
        if (check(v[i], v[i + 1])) {
            if (c == 1)
                id = i;
            c++;
        }
        else if (c > 1) {
            // dbg(id, i, c);
            for (int j = id; j < i; j++)
                ans[j] = c--;
            dbg(c);
        }
    }
    if (c > 1) {
        for (int j = id; j < n; j++)
        ans[j] = c--;
        dbg(c);
    }
    for (auto i : ans)
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