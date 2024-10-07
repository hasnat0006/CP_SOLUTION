//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 06|10|2024 10:16:33            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

int mod = 1000000007;
int inf = 1e18;

void solve() {
    int n, m;
    string a, b, s;
    set<string> ans;
    cin >> a >> b;
    n = a.size(), m = b.size();
    if (n <= m)
        s = a;
    else {
        s = b;
        swap(a, b);
        swap(n, m);
    }
    for (int i = 0; i < m; i++)
        s.push_back('?');
    ans.insert(s);
    int cnt = 0;
    for (int len = n; len >= 0; len--) {
        for (auto st : ans) {
            string temp = st;
            for (int cholbe = 0; cholbe < m; cholbe++) {
                for (int i = n - 1 + cholbe; i >= n - len; i--)
                    swap(temp[i], temp[i + 1]);
                int id = 0;
                for (int j = 0; j < temp.size(); j++)
                    if (temp[j] == a[id])
                        id++;
                if (id == n)
                    ans.insert(temp);
            }
        }
    }
    for (int len = n; len >= 0; len--) {
        for (auto st : ans) {
            string temp = st;
            for (int cholbe = 0; cholbe < m; cholbe++) {
                for (int i = n - 1 + cholbe; i >= n - len; i--)
                    swap(temp[i], temp[i + 1]);
                int id = 0;
                for (int j = 0; j < temp.size(); j++)
                    if (temp[j] == a[id])
                        id++;
                if (id == n)
                    ans.insert(temp);
            }
        }
    }
    set<string> paisi;
    for (auto st : ans) {
        int id = 0;
        for (int j = 0; j < st.size(); j++)
            if (st[j] == a[id])
                id++;
        if (id == n)
            paisi.insert(st);
    }
    set<string> finalAns;
    for (auto st : paisi) {
        int id = 0;
        for (int i = 0; i < st.size(); i++) {
            if (st[i] == '?') {
                st[i] = b[id++];
            }
        }
        finalAns.insert(st);
    }
    for (auto i : finalAns) {
        cout << i << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
        cout << endl;
    }
    return 0;
}