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

vector<int> lps;

void createLPS(string pattern) {
    lps.resize(pattern.size());
    int index = 0;
    for (int i = 1; i < pattern.length();) {
        if (pattern[index] == pattern[i]) {
            lps[i] = index + 1;
            index++, i++;
        }
        else {
            if (index != 0)
                index = lps[index - 1];
            else
                lps[i] = index, i++;
        }
    }
    // return lps;
}

void solve() {
    string s;
    cin >> s;
    string text = s;
    int mx = 0;
    int n = s.size();
    reverse(vf(s));
    string pat = s + "_" + text;
    createLPS(pat);
    cout << 2 * n - lps[pat.size() - 1] << endl;
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        case(i);
        solve();
    }
    return 0;
}