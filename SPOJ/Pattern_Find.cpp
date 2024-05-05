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

vector<int> ans;

vector<int> createLPS(string pattern) {
    vector<int> lps(pattern.length());
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
    return lps;
}
void kmp(string text, string pattern) {
    int cnt_of_match = 0;
    vector<int> lps = createLPS(pattern);
    // debug(lps);
    int i = 0, j = 0;
    // i -> text, j -> pattern
    while (i < text.length()) {
        if (text[i] == pattern[j])
            i++, j++;
        else {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
        if (j == pattern.length()) {
            cnt_of_match++;
            ans.pb(i - pattern.length());
            // the index where match found -> (i - pattern.length());
            j = lps[j - 1];
        }
    }
    // return cnt_of_match;
}

void solve() {
    ans.clear();
    string text, pat;
    cin >> text >> pat;
    int n = text.size(), m = pat.size();
    kmp(text, pat);
    if (ans.size() == 0) {
        cout << "Not Found" << endl << endl;
        return;
    }
    cout << ans.size() << endl;
    for (auto i : ans)
        cout << i + 1 << " ";
    cout << endl << endl;
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // case(i)
        solve();
    }
    return 0;
}