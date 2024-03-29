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
    int n, k;
    string s;
    cin >> n >> k >> s;
    if (k % 2 == 0) {
        sort(s.begin(), s.end());
        cout << s << endl;
        return;
    }
    priority_queue<char, vector<char>, greater<char> > odd, even;
    for (int i = 0; i < n; i++) {
        if (i % 2)
            even.push(s[i]);
        else
            odd.push(s[i]);
    }
    int c = 1;
    while (even.size() or odd.size()) {
        if (c % 2 and odd.size())
            cout << odd.top(), odd.pop();
        else if (even.size())
            cout << even.top(), even.pop();
        c++;
    }
    cout << endl;
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        // case(i)
        solve();
    return 0;
    // write a lower bound binary search function
    
}