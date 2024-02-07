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

vector<int> v;
set<int> st;

void minimumDiff(int i, vector<int> &a, vector<int> &b) {
    if (i == -1) {
        int sumA = 0, sumB = 0;
        for (auto x : a)
            sumA += x;
        for (auto x : b)
            sumB += x;
        dbg(a, b);
        st.insert(abs(sumA - sumB));
        return;
    }
    a.push_back(v[i]);
    minimumDiff(i - 1, a, b);
    a.pop_back();
    b.push_back(v[i]);
    minimumDiff(i - 1, a, b);
    b.pop_back();
}

void solve() {
    int n;
    cin >> n;
    v.resize(n, 0);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<int> a, b;
    minimumDiff(n - 1, a, b);
    cout << *st.begin() << endl;

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