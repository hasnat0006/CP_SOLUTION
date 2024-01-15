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

bool com(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first and a.second > b.second)
        return true;
    if (a.first < b.first)
        return true;
    return false;
}

void solve() {
    int n, king;
    cin >> n >> king;
    vector<pair<int, int>> hasu(n);
    for (int i = 0; i < n; i++)
        cin >> hasu[i].second;
    for (int i = 0; i < n; i++)
        cin >> hasu[i].first;
    sort(vf(hasu), com);
    int result = 0;
    result += king;
    int baki_ase = n - 1;
    for (int i = 0; (i < n and baki_ase > 0); i++) {
        if (hasu[i].first < king) {
            int temp = baki_ase;
            baki_ase -= min(baki_ase, hasu[i].second);
            result += (hasu[i].first * min(temp, hasu[i].second));
        }
    }
    result += (baki_ase * king);
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