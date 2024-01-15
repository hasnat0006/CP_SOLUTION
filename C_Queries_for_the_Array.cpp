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
    string s;
    cin >> s;
    int f = 0, minus = 0, plus = 0;
    vector<int> v;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '+') {
            if (i < s.size() - 1 and s[i + 1] == '0')
                v.push_back(1);
            else
                v.push_back(2);
        }
        else if (s[i] == '-')
            v.pop_back();
        else if (s[i] == '1') {
            if (!is_sorted(vf(v))) {
                cout << "NO\n";
                return;
            }
        }
        else if (s[i] == '0') {
            if (is_sorted(vf(v))) {
                cout << "NO\n";
                return;
            }
        }
        dbg(v);
    }
    cout << "YES\n";
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