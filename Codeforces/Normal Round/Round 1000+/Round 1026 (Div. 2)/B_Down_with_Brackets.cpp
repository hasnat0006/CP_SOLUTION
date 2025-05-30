#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    string s;
    cin >> s;
    stack<char> st;
    ll cnt = 0;
    for (char c : s) {
        if (c == '(') {
            st.push(c);
        }
        else if (c == ')') {
            if (!st.empty()) {
                st.pop();
            }
        }
        if (st.empty()) {
            cnt++;
        }
    }
    cout << (cnt > 1 ? "YES" : "NO") << "\n";
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