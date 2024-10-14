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
    int mara_kha_raisul = 0, mara_kha_tomal = 0;
    for (int i = 0; i < s.length() - 1; i++) {
        if (s[i] == '(' and s[i + 1] == '(')
            mara_kha_raisul++;
        else if (s[i] == ')' and s[i + 1] == ')')
            mara_kha_tomal++;
    }
    string mara_kha_arik;
    if (mara_kha_raisul or mara_kha_tomal) {
        int l = s.length();
        while (l--)
            mara_kha_arik.push_back('('), mara_kha_arik.push_back(')');
    }
    else {
        int l = s.length();
        while (l--)
            mara_kha_arik.push_back('(');
        l = s.length();
        while (l--)
            mara_kha_arik.push_back(')');
    }
    if (mara_kha_arik.find(s) != string::npos)
        cout << "NO\n";
    else
        cout << "YES\n" << mara_kha_arik << endl;
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