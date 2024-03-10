//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 03|03|2024 21:54:39            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

int mod = 1000000007;
int inf = 1e18;

string s;
set<string> uni;

void Knapsack(int i, int baad = 0, string str = "") {
    if (i == -1) {
        if(str.size() + 2 == s.size())
        uni.insert(str);
        return;
    }
    if (baad < 2) {
        Knapsack(i - 1, baad + 1, str);
        Knapsack(i - 1, baad, str + s[i]);
    }
    else
        Knapsack(i - 1, baad, str + s[i]);
}

void solve() {
    cin >> s;
    Knapsack(s.size() - 1);
    for (auto i : uni)
        cout << i << endl;
    cout << uni.size() << endl;
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