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

bool isPossible = 0;

void possibleToMake23(int i, vector<int> &v, int sum) {
    if (i == 5) {
        if (sum == 23)
            isPossible = 1;
        return;
    }
    possibleToMake23(i + 1, v, sum + v[i]);
    possibleToMake23(i + 1, v, sum - v[i]);
    possibleToMake23(i + 1, v, sum * v[i]);
}

void solve() {
    isPossible = 0;
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    if (!a && !b && !c && !d && !e) {
        exit(0);
    }
    vector<int> v = {a, b, c, d, e};
    sort(v.begin(), v.end());
    possibleToMake23(1, v, v[0]);
    if (isPossible) {
        cout << "Possible" << endl;
        return;
    }
    while (next_permutation(v.begin(), v.end())) {
        possibleToMake23(1, v, v[0]);
        if (isPossible) {
            cout << "Possible" << endl;
            return;
        }
    }
    cout << "Impossible" << endl;
}

int32_t main() {
    YUSUF REZA HASNAT;
    while (1)
        solve();
    return 0;
}