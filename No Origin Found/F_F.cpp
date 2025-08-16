#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug1.cpp"
#else 
#define dbg(x...)
#define dbgc(x...)
#endif
#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    double d, t, k, v, lemda;
    cin >> d >> t >> k >> v >> lemda;
    double time = 0, l = lemda, av = v;
    ll cnt = 0;
    while (time < t) {
        dbg(v, l);
        double remTime = t - time;
        double addedDisAfter1s = v * min(remTime, 1.0);
        dbg(time, t, remTime, addedDisAfter1s);
        if (k + addedDisAfter1s <= d) {
            k += addedDisAfter1s;
            time += min(remTime, 1.0);
            dbg("1");
        }
        else {
            dbg("2");
            double remDis = d - k;
            double timeNeeded = remDis / v;
            time += timeNeeded;
            k = 0;
            cnt++;
            v = av * l;
            l *= lemda;
        }
        dbg(k, v, l, time);
        dbg("-----------");
    }
    dbg(cnt);
    if(cnt % 2)
        k = d - k;
    cout << fixed << setprecision(10) << k << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}