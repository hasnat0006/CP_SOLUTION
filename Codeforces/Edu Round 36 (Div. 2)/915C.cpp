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
string a, b;

bool highestPossibleNumber(int i, vector<int> &cnt, string &ans, int flag) {
    if (i == a.size())
        return true;
    for (int j = 9; j >= 0; j--) {
        if (cnt[j] > 0) {
            if (flag) {
                ans += (char)(j + '0');
                cnt[j]--;
                if (highestPossibleNumber(i + 1, cnt, ans, 1))
                    return true;
                ans.pop_back();
                cnt[j]++;
            }
            else if (j <= b[i] - '0') {
                ans += (char)(j + '0');
                cnt[j]--;
                if (highestPossibleNumber(i + 1, cnt, ans, j < b[i] - '0'))
                    return true;
                ans.pop_back();
                cnt[j]++;
            }
        }
    }
    return false;
}

void solve() {
    cin >> a >> b;
    if (b.size() > a.size()) {
        sort(vr(a));
        cout << a << endl;
        return;
    }
    vector<int> cnt(10, 0);
    for (auto x : a)
        cnt[x - '0']++;
    string ans = "";
    highestPossibleNumber(0, cnt, ans, 0);
    cout << ans << endl;
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