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
    vector<int> a(n), b(n), a_cpy, b_cpy;
    vector<pair<int, int>> ans;
    for (auto &i : a)
        cin >> i;
    for (auto &i : b)
        cin >> i;
    a_cpy = a;
    b_cpy = b;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (a[j] < a[i]) {
                ans.emplace_back(i, j);
                swap(a[i], a[j]);
                swap(b[i], b[j]);
            }
        }
    }
    dbg(a, b);
    dbg(ans);
    if (is_sorted(vf(a)) and is_sorted(vf(b))) {
        cout << ans.size() << endl;
        for (auto i : ans)
            cout << i.first + 1 << " " << i.second + 1 << endl;
        return;
    }
    ans.clear();
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (b_cpy[j] < b_cpy[i]) {
                ans.emplace_back(i, j);
                swap(b_cpy[i], b_cpy[j]);
                swap(a_cpy[i], a_cpy[j]);
            }
        }
    }
    if (is_sorted(vf(a_cpy)) and is_sorted(vf(b_cpy))) {
        cout << ans.size() << endl;
        for (auto i : ans)
            cout << i.first + 1 << " " << i.second + 1 << endl;
        return;
    }
    cout << - 1 << endl;
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