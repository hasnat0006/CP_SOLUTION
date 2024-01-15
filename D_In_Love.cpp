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

multimap<pair<int, int>, int> mp;
bool check() {
    int a = 0, b = 0;
    for (auto i : mp) {
        if ((i.first.first <= a and i.first.second  >= b) ) {
            return false;
        }
        a = i.first.first;
        b = i.first.second;
    }
    return true;
}

void solve() {
    mp.clear();
    int n;
    cin >> n;
    while (n--) {
        char x;
        int l, r;
        cin >> x >> l >> r;
        if (x == '+') {
            mp.insert({{l, r}, 1});
            if (check()) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
        }
        else {
            auto it = mp.find({l, r});
            int x = it->second;
            if (it->second == 1) {
                mp.erase(it);
            }
            else {
                mp.erase(it);
                mp.insert({{l, r}, x - 1});
            }
            if (check()) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
        }
        dbg(mp);
        if (check()) {
            dbg("YES")
        }
        else {
            dbg("NO");
        }
    }
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