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
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)

int mod = 1000000007;
float pi = acos(-1);
int inf = 1e18;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first > b.first)
        return true;
    if (a.first == b.first and a.second < b.second)
        return true;
    return false;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> ans;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x % k == 0)
            ans.pb(i + 1);
        else
            v.pb({x % k, i + 1});
    }
    sort(v.begin(), v.end(), cmp);
    dbg(v);
    for (auto it : ans)
        cout << it << " ";
    for (auto it : v)
        cout << it.second << " ";
    cout << endl;
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}