//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 12|03|2024 01:31:15            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

#define int   long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

int mod = 1000000007;
int inf = 1e18;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int &i : v)
        cin >> i;
    sort(vf(v));
    multiset<int> st;
    for (int i = 0; i < n; i++)
        st.insert(v[i]);    
    int cnt = 0;
    while(st.size()){
        int x = *st.rbegin();
        st.erase(st.find(x));
        int total = x;
        while(st.size() and total <= m){
            auto it = st.upper_bound(m - total);
            if(it == st.begin())
                break;
            it--;
            total += *it;
            st.erase(it);
        }
        cnt++;
    }
    cout << cnt << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++){
        solve(); 
    }
    return 0;
}