//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 07|03|2024 01:25:30            !//
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

int binaryExp(int base, int power, int MOD = mod) {
    int res = 1;
    while (power) {
        if (power & 1)
            res = (res * base);
        base = ((base) * (base));
        power /= 2;
    }
    return res;
}

void solve() {
    int x, y, r;
    cin >> x >> y >> r;
    if (x < y)
        swap(x, y);
    int diffXY = abs(x - y);
    string a = bitset<64>(max(x, y)).to_string();
    string b = bitset<64>(min(x, y)).to_string();
    // dbg(a);
    // dbg(b);
    reverse(vf(a)), reverse(vf(b));
    int lastOne = -1;
    for (int i = a.size() - 1; i >= 0; i--) {
        if (a[i] == '1') {
            lastOne = i;
            break;
        }
    }
    vector<int> id;
    int isDiff = false;
    for (int i = 0; i < 64; i++) {
        int num = binaryExp(2, i);
        if (num > r)
            break;
        if (a[i] == '1' and b[i] == '0' and i != lastOne)
            id.push_back(i);
        else if(a[i] == '0' and b[i] == '1')
            isDiff = !isDiff;
        // dbg(i, num);
    }
    if (id.size() == 0) {
        cout << diffXY << endl;
        return;
    }
    // dbg(id);
    int ans = 0;
    int finalAns = LLONG_MAX;
    vector<int> temp;
    for (int i = id.size() - 1; i >= 0; i--) {
        int power = binaryExp(2, id[i]);
        if(ans + power <= r) {
            ans += power;
            temp.push_back(id[i]);
        }
    }
    if(!isDiff){
        for(int i = 0; i < id.size(); i++){
            int power = binaryExp(2, id[i]);
            if(power <= r){
                ans = min(ans, abs(x - y - 2 * power));
            }
        }
    }
    cout << min(ans, diffXY) << endl;
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