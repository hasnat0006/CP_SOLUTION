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
    int n;
    cin >> n;
    vector<string> a(n), b(n), c(n);
    map<string, int> mpa, mpb, mpc;
    for (int i = 0; i < n; i++)
        cin >> a[i], mpa[a[i]]++;
    for (int i = 0; i < n; i++) {
        cin >> b[i], mpb[b[i]]++;
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i], mpc[c[i]]++;
    }
    int first = 0, second = 0, third = 0;
    for (int i = 0; i < n; i++) {
        if (mpb[a[i]] and mpc[a[i]])
            continue;
        if (mpb[a[i]] == 0 and mpc[a[i]] == 0)
            first += 3;
        if (mpb[a[i]])
            first++, mpb[a[i]]--;
        if (mpc[a[i]])
            first++, mpc[a[i]]--;
    }
    for (int i = 0; i < n; i++) {
        if (mpa[b[i]] and mpc[b[i]])
            continue;
        if (mpa[b[i]] == 0 and mpc[b[i]] == 0)
            second += 3;
        if (mpa[b[i]])
            second++, mpa[b[i]]--;
        if (mpc[b[i]])
            second++, mpc[b[i]]--;
    }
    for (int i = 0; i < n; i++) {
        if (mpa[c[i]] and mpb[c[i]])
            continue;
        if (mpa[c[i]] == 0 and mpb[c[i]] == 0)
            third += 3;
        if (mpa[c[i]])
            third++, mpa[c[i]]--;
        if (mpb[c[i]])
            third++, mpb[c[i]]--;
    }

    // for (int i = 0; i < n; i++) {
    //     if (a[i] == b[i] and b[i] == c[i])
    //         continue;
    //     if (a[i] == b[i]) {
    //         first++;
    //         second++;
    //     }
    //     if (b[i] == c[i]) {
    //         second++;
    //         third++;
    //     }
    //     if (a[i] == c[i]) {
    //         first++;
    //         third++;
    //     }
    //     else {
    //         first += 3;
    //         second += 3;
    //         third += 3;
    //     }
    // }
    cout << first << " " << second << " " << third << endl;
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