//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 20|04|2024 18:01:03            !//
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
    string s;
    cin >> s;
    if(s == "ABC316"){
        cout << "No" << endl;
        return;
    }
    string t = "";
    t.push_back(s[3]);
    t.push_back(s[4]);
    t.push_back(s[5]);
    int x = stoi(t);
    if(x > 0 and x < 350)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;    
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++){
        solve(); 
    }
    return 0;
}