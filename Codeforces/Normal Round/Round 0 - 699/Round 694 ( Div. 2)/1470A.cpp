//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 12|03|2024 16:19:08            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

int mod = 1000000007;
int inf = 1e18;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n), cost(m);
    for (int &i : v)
        cin >> i;
    multiset<int> st;
    for (int &i : cost)
        cin >> i, st.insert(i);
    sort(vr(v));
    int ans = 0;
    for(int i = 0; i < n; i++){
        int cst = cost[v[i] - 1];
        if(cst > *st.begin()){
            ans += *st.begin();
            st.erase(st.begin());
        }
        else{
            ans += cst;
        }
    }
    cout << ans << endl;
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