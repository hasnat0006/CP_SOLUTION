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

set<int> lucky;

void SUPER_LUCKY_NUMBER(string s, int four, int seven, int i = 0) {
    dbg(s, four, seven);
    if (four == seven and four + seven == s.size()) {
        lucky.insert(stoll(s));
        return;
    }
    if (i == s.size())
        return;
    int c = stoll(s);
    s[i] = '4';
    SUPER_LUCKY_NUMBER(s, four + 1, seven, i + 1);
    s[i] = '7';
    SUPER_LUCKY_NUMBER(s, four, seven + 1, i + 1);
}

void solve() {
    int n;
    cin >> n;
    string s = to_string(n);
    if (s.size() % 2)
        s.push_back('4');
    SUPER_LUCKY_NUMBER(s, 0, 0);
    auto it = lucky.lower_bound(n);
    if(it == lucky.end()){
        int n = s.size() / 2;
        for(int i = 0; i <= n; i++)
            cout << 4;
        for(int i = 0; i <= n; i++)
            cout << 7;
        cout << endl;
    }
    else
        cout << *it << endl;
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