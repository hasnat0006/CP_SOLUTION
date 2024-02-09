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
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)

int mod = 1000000007;
int inf = 1e18;

int n, ans = 0;
vector<int> start;
int multiloop = 1, maxlimit = (pow(2, 32)) - 1;
int f = 0;
int cnt = 0;

void loop(int i) {
    if (i == n)
        return;
    string s;
    cin >> s;
    if (s == "for") {
        int x;
        cin >> x;
        if (cnt)
            cnt++;
        else {
            multiloop *= x;
            if (multiloop > maxlimit)
                cnt++, multiloop /= x;
        }
        start.push_back(x);
    }
    else if (s == "end") {
        cnt ? cnt-- : multiloop /= start.back();
        start.pop_back();
    }
    else if (s == "add") {
        if (cnt)
            f = 1;
        else {
            ans += multiloop;
            if (ans > maxlimit)
                f = 1;
        }
    }
    loop(i + 1);
}

void solve() {
    cin >> n;
    loop(0);
    f ? cout << "OVERFLOW!!!" << endl : cout << ans << endl;
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}