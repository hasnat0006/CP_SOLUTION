//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 08|04|2024 20:36:32            !//
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
    int n, a, b;
    cin >> n >> a >> b;
    if(2 * a <= b){
        cout << a * n << endl;
        return;
    }    
    int x = n / 2;
    int rem = n - 2 * x;
    cout << x * b + rem * a << endl;
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