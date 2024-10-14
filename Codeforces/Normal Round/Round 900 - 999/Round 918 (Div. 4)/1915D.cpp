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

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<string> ans;
    vector<int> id;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a' or s[i] == 'e')
            id.pb(i);
    }
    int c = 1;
    string temp = "";
    for (int i = 0; i < n; i++) {
        if ((s[i] == 'a' or s[i] == 'e') and id.back() > i) {
            int idx = lower_bound(id.begin() + c, id.end(), i + 1) - id.begin();
            c++;
            // dbg(id[idx], i);
            if (id[idx] - i > 2) {
                temp += s[i];
                if (i + 1 < n) {
                    i++;
                    temp += s[i];
                    temp += '.';
                    ans.push_back(temp);
                    temp = "";
                }
            }
            else if (id[idx] - i == 2) {
                temp += s[i];
                temp += '.';
                // dbg(temp);
                ans.push_back(temp);
                temp = "";
            }
        }
        else {
            temp += s[i];
        }
        // dbg(temp);
    }
    if (temp != "")
        ans.push_back(temp);
    if(temp.back() == '.')
        ans.pop_back();
    for (auto i : ans) {
        cout << i;
    }
    cout << endl;
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