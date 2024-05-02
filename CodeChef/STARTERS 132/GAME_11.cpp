//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 01|05|2024 20:35:38            !//
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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> bat(n), bol(m);
    for(int i = 0; i < n; i++)
        cin >> bat[i];
    for(int i = 0; i < m; i++)
        cin >> bol[i];
    if(n < 4 or m < 4 or (n + m) < 11){
        cout << -1 << endl;
        return;
    }
    sort(vf(bat));
    sort(vf(bol));
    int ans = 0;
    int t = 4;
    while(t--){
        ans += bat.back();
        bat.pop_back();
    }
    t = 4;
    while(t--){
        ans += bol.back();
        bol.pop_back();
    }
    for(int i = 9; i <= 11; i++){
        if(bat.size() and bol.size()){
            int BAT = bat.back();
            int BOL = bol.back();
            if(BAT > BOL){
                ans += BAT;
                bat.pop_back();
            }
            else{
                ans += BOL;
                bol.pop_back();
            }
        }
        else if(bat.size()){
            ans += bat.back();
            bat.pop_back();
        }
        else if(bol.size()){
            ans += bol.back();
            bol.pop_back();
        }
        // cerr << ans << endl;
    }
    cout << ans << endl; 
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