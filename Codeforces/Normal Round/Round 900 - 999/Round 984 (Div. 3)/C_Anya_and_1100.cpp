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

set<int> st;

vector<int> createLPS(string &pattern) {
    vector<int> lps(pattern.length());
    int index = 0;
    int M = pattern.length();
    for (int i = 1; i < M;) {
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
    int N = text.length(), M = pattern.length();
    while (i < N) {
        if (text[i] == pattern[j])
            i++, j++;
        else {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
        if (j == M) {
            cnt_of_match++;
            st.insert(i - M);
            // the index where match found -> (i - pattern.length());
            j = lps[j - 1];
        }
    }
    return cnt_of_match;
}

void solve() {
    st.clear();
    string s;
    cin >> s;
    int q;
    cin >> q;
    string temp = "1100";
    int n = s.size();
    int cnt = kmp(s, temp);
    while (q--) {
        int i;
        char v;
        cin >> i >> v;
        if (v == s[i - 1]) {
            cout << (st.size() > 0 ? "YES" : "NO") << '\n';
            continue;
        }
        else {
            int id = i - 1, cnt = 4, start = id;
            for (int i = id; i >= 0 and cnt > 0; i--, cnt--) {
                if (st.find(i) != st.end()) {
                    st.erase(st.find(i));
                }
                start = i;
            }
            s[id] = v;
            for (int i = start; i <= id; i++) {
                int c = 0;
                for (int j = i; j < i + 4 and j < s.size(); j++) {
                    if (s[j] == temp[c])
                        c++;
                }
                if (c == 4) {
                    st.insert(i);
                    break;
                }
            }
            cout << (st.size() > 0 ? "YES" : "NO") << '\n';
        }
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