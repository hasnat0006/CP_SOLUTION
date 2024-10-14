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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i], sum1 += a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i], sum2 += b[i];
    sort(vf(a));
    sort(vf(b));
    int result = 0;
    if (k % 2) {
        if (b.back() >= a.front())
            result = sum1 - a.front() + b.back();
        else
            result = sum1;
    }
    else {
        if (b.back() >= a.front()) {
            result = sum1 - a.front() + b.back();
            int x = a.front();
            a.erase(a.begin());
            a.push_back(b.back());
            b.pop_back();
            b.push_back(x);
            sort(vf(b));
            sort(vf(a));
            sum1 = result;
        }
        if (a.back() >= b.front())
            result = sum1 - a.back() + b.front();
    }
    cout << result << endl;
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