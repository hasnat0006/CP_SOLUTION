//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 04|03|2024 00:26:43            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug.h"
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

int mod = 1000000007;
int inf = 1e18;

struct Node {
    int diff, zero, one;
};

void solve() {
    int n;
    cin >> n;
    vector<Node> v;
    int allZero = 0, allOne = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int z = 0, o = 0;
        for (int j = 0; j < s.size(); j++)
            s[j] == '0' ? z++ : o++;
        allZero += z, allOne += o;
        v.push_back({z - o, z, o});
    }
    if(allZero == 0 or allOne == 0){
        cout << 0 << endl;
        return;
    }
    sort(vf(v), [](Node x, Node y) { return x.diff < y.diff; });
    // for(auto i : v){
    //     cout << i.diff << " " << i.zero << " " << i.one << endl;
    // }
    int ans = inf;
    vector<int> pref(n + 1), suff(n + 1);
    pref[0] = v[0].zero;
    for (int i = 1; i < n; i++) {
        pref[i] = pref[i - 1] + v[i].zero;
    }
    suff[n - 1] = v[n - 1].one;
    for (int i = n - 2; i >= 0; i--) {
        suff[i] = suff[i + 1] + v[i].one;
    }
    for(int i = 1; i < n; i++){
        ans = min(ans, pref[i - 1] + suff[i]);
    }
    cout << ans << endl;
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