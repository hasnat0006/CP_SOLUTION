//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 29|03|2024 22:20:02            !//
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
    int boy, girl, g;
    cin >> boy >> girl >> g;
    int gcd = (g, (1000000000 - g));
    cout << ((g / gcd)) << "/" << (1000000000 - g) / gcd << endl;    
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++){
        cout << "Case " << i << ": ";
        solve(); 
    }
    return 0;
}