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

class Info {
   public:
    int first, last, cnt;
    Info() {}
    Info(int first, int last, int cnt) {
        this->first = first;
        this->last = last;
        this->cnt = cnt;
    }
    void print() { cout << first << " " << last << " " << cnt << endl; }
};

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    map<int, Info> mp;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int ans = n;
    vector<int> dis;
    int mn = inf;
    for (auto &it : v) {
        if (it <= mn) {
            dis.pb(it);
            mn = it;
        }
    }
    reverse(vf(dis));
    for (int i = 0; i < dis.size(); i++) {
        ans = min(ans, n - i - 1 + dis[i]);
    }
    cout << ans << endl;
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