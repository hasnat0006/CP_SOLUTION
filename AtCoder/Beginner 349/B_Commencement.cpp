//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 13|04|2024 18:12:29            !//
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
    map<char, int> mp;
    for (char c : s) {
        mp[c]++;
    }
    map<int, int> freq;
    for(auto i : mp){
        freq[i.second]++;
    }    
    for(auto i : freq){
        if(i.second != 2){
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
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