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
    string copy = s;
    sort(vf(copy));
    map<char, deque<int>> mp;
    for (int i = 0; i < s.size(); i++) {
        mp[s[i]].push_back(i);
    }
    vector<int> vis(s.size());
    for (int i = 0; i < s.size(); i++) {
        char mn = copy[i];
        int id = mp[mn].front();
        mp[mn].pop_front();
        vis[id] = 1;
        for (int i = id - 1; i >= 0; i--) {
            if (!vis[i]) {
                if (s[i] != '9')
                    s[i]++;
                vis[i] = 1;
            }
            else
                break;
        }
        dbg(mn, id, s);
    }
    sort(vf(s));
    cout << s << endl;
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