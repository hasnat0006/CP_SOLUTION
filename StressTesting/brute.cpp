//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 02|11|2024 20:44:03            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const int mod = 1e9 + 7;
const ll inf = 1e18;

vector<int> createLPS(string &pattern) {
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
int kmp(string &text, string &pattern) {
    int cnt_of_match = 0;
    vector<int> lps = createLPS(pattern);
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
            // the index where match found -> (i - pattern.length());
            j = lps[j - 1];
        }
    }
    return cnt_of_match;
}

void solve() {
    string s;
    cin >> s;
    int q;
    cin >> q;
    string temp = "1100";
    while (q--) {
        int i, v;
        cin >> i >> v;
        if (s.size() < 4) {
            cout << "NO" << '\n';
            continue;
        }
        s[i - 1] = v + '0';
        int cnt = kmp(s, temp);
        cout << (cnt > 0 ? "YES" : "NO") << '\n';
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}