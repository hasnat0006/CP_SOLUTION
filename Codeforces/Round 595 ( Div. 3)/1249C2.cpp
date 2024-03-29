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

int n;
vector<int> valuesOfThree(39), valuesOfSum(39);

int findGoodNumber(int i, int nn, int sum) {
    if (i == -1)
        return 0;
    if (sum - valuesOfThree[i] >= nn)
        return findGoodNumber(i - 1, nn, sum - valuesOfThree[i]);
    return findGoodNumber(i - 1, nn, sum) + valuesOfThree[i];
}

void solve() {
    cin >> n;
    int j = lower_bound(vf(valuesOfSum), n) - valuesOfSum.begin();
    cout << findGoodNumber(j, n, valuesOfSum[j]) << endl;
}

int32_t main() {
    YUSUF REZA HASNAT;
    int mul = 1;
    valuesOfThree[0] = 1, valuesOfSum[0] = 1;
    for (int i = 1; i < 39; i++) {
        valuesOfThree[i] = 3 * valuesOfThree[i - 1];
        valuesOfSum[i] += valuesOfSum[i - 1] + valuesOfThree[i];
    }
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}