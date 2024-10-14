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
    string s;
    cin >> s;
    int n = s.size();
    deque<pair<char, int>> lower, upper;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'b' and lower.size()) {
            lower.pop_back();
        }
        else if (s[i] == 'B' and upper.size()) {
            upper.pop_back();
        }
        if (s[i] == 'b' or s[i] == 'B')
            continue;
        if (islower(s[i]))
            lower.pb({s[i], i});
        else
            upper.pb({s[i], i});
        dbg(lower, upper);
    }

    vector<pair<int, char>> ans;
    while (lower.size()) {
        ans.pb({lower.front().second, lower.front().first});
        lower.pop_front();
    }
    while (upper.size()) {
        ans.pb({upper.front().second, upper.front().first});
        upper.pop_front();
    }
    sort(vf(ans));
    for (auto i : ans) {
        cout << i.second;
    }
    cout << endl;
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // case(i)
        dbg("------------------");
        solve();
    }
    return 0;
}