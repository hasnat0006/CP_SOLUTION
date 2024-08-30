//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 30|08|2024 22:27:22            !//
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

int findMax(int x, int a, int b){
    int dif = abs(a - b);
    int bagfol = x / a;
    int rem = x % a;
    int Badd = bagfol * 2;
    if(dif <= rem){
        int baki = rem % dif;
    }
}


void solve() {
    int n, a, b, A, B;
    cin >> n >> A >> B;
    a = min(A, B);
    b = max(A, B);
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    sort(vf(v));
    int ans = inf;
    for(int i = 0; i < n; i++){
        int val = findMax(v.back(), A, B);
    }

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