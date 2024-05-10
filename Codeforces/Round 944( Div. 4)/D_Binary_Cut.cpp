//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 10|05|2024 21:07:51            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

#define int   long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

const int mod = 1e9 + 7;
const int inf = 1e18;

void solve() { string s;
    cin >> s;
    set<char> st;
    for (int i = 0; i < s.size(); i++)
        st.insert(s[i]);
    if(st.size() == 1){
        cout << 1 << endl;
        return;
    }
    int n = s.size();
    int cnt = 0;
    for (int k = 1; k < n; k++){
        if(s[k] != s[k - 1])
            cnt++;
    }
    if(s.find(("01")) != string::npos)
        cnt--;
    cout << cnt + 1 << endl;
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