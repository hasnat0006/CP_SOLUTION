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
    deque<int> even, odd;
    for (int i = 1; i <= n; i++) {
        if (i % 2)
            odd.push_back(i);
        else
            even.push_back(i);
    }
    int f = 0;
    if (n % 2)
        f = 1;
    while (odd.size() or even.size()) {
        if (f) {
            if (odd.size())
                cout << odd.back() << " ", odd.pop_back();
            if (odd.size())
                cout << odd.front() << " ", odd.pop_front();
            if (even.size())
                cout << even.back() << " ", even.pop_back();
            if (even.size())
                cout << even.front() << " ", even.pop_front();
        }
        else {
            if (even.size())
                cout << even.back() << " ", even.pop_back();
            if (even.size())
                cout << even.front() << " ", even.pop_front();
            if (odd.size())
                cout << odd.back() << " ", odd.pop_back();
            if (odd.size())
                cout << odd.front() << " ", odd.pop_front();
        }
    }
    cout << endl;
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