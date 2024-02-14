//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)

int mod = 1000000007;
int inf = 1e18;

/*

1.  (ai - aj) % y = 0 it can be written as ai % y = aj % y
2.  (ai + aj) % x = 0 it can be written as ai % x = (x - aj % x) % x
so we can use a map to store the frequency of the pair (ai % x, ai % y) and for each ai we can check how many pairs (xMod, yMod) are there such that xMod = (x - ai % x) % x and yMod = ai % y and add that to the answer and then increment the frequency of the pair (ai % x, ai % y) in the map.

*/

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int ans = 0;
    map<pair<int, int>, int> mp;
    for(auto i : v){
        int xMod = (x - i % x) % x;
        int yMod = i % y;
        ans += mp[{xMod, yMod}];
        mp[{i % x, i % y}]++;
    }
    cout << ans << endl;
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}
