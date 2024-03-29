//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 14|03|2024 01:24:59            !//
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
    vector<int> zero(40,0);
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        bitset<33>b(x);
        for(int i = 0; i < 33; i++)
            zero[i] += b[i];
    }
    int gcd = 0;
    for(int i = 0; i < 40; i++)
        gcd = __gcd(gcd, zero[i]);
    for(int i = 1; i <= n; i++){
        if(gcd % i == 0)
            cout << i << " ";
    }
    cout << endl;
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