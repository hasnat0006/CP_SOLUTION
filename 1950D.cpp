//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 28|03|2024 21:21:18            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug.h"
#else 
#define dbg(x...)
#define dbgc(x...)
#endif
using namespace std;

#define int   long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

int mod = 1000000007;
int inf = 1e18;

vector<int> num;
void precal(){
    for(int i = 2; i <= 100000; i++){
        int n = i;
        bool flag = true;
        while(n){
            if(n % 10 != 0 and n % 10 != 1){
                flag = false;
                break;
            }
            n /= 10;
        }
        if(flag)
            num.push_back(i);
    }
}

void solve() {
    int n;
    cin >> n;
    if(n == 1 or n == 10){
        cout << "YES" << endl;
        return;
    }
    while(n > 0){
        int id = lower_bound(vf(num), n) - num.begin();
        dbg(id, num[id]);
        int f = 0;
        for(int i = id; i >= 0; i--){
            if(n % num[i] == 0){
                n /= num[i];
                f = 1;
                break;
            }
        }
        if(f == 0)
            break;
        if(n == 1){
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    precal();
    for (int i = 1; i <= t; i++){
        solve(); 
    }
    return 0;
}