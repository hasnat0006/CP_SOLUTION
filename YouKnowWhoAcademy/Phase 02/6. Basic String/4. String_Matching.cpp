#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;


vector<ll> createLPS(string &pattern) {
    vector<ll> lps(pattern.length());
    ll index = 0;
    for (ll i = 1; i < pattern.length();) {
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
ll kmp(string &text, string &pattern) {
    ll cnt_of_match = 0;
    vector<ll> lps = createLPS(pattern);
    ll i = 0, j = 0;
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
    string text, pattern;
    cin >> text >> pattern;
    cout << kmp(text, pattern) << '\n';
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