//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

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
    int h, w, n;
    cin >> h >> w >> n;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    int c = 0;
    int temp = w;
    while (c != h) {
        for (int i = 0; i < n; i++) {
            temp -= v[i];
            if (temp < 0) {
                cout << "NO\n";
                return;
            }
            if (temp == 0)
                temp = w, c++;
            if (c == h) {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        // case(i)
        solve();
    }
    return 0;
}