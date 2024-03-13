//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 11|03|2024 21:00:50            !//
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
    int n;
    cin >> n;
    string s;
    cin >> s;
    s.push_back('x');
    s.push_back('x');
    int ans = 0;
    string a = "map", b = "pie", c = "mapie";
    for(int i = 0; i < n - 2; i++){
        string temp = s.substr(i, 5);
        if(temp == c){
            ans++;
            s[i + 2] = 'x';
            continue;
        }
        temp = s.substr(i, 3);
        // cout << temp << endl;
        if(temp == a or temp == b){
            ans++;
            s[i + 1] = 'x';
        }
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