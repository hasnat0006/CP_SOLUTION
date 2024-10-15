//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 13|10|2024 22:36:57            !//
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

const int N = 1e6 + 5;
int divisorCnt[N], ans[N], cnt[N];

void solve() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        cnt[x]++;
    }    
    for(int i = 1; i < N; i++){
        for(int j = i; j < N; j+= i){
            ans[i] += cnt[j];
        }
    }
    for(int i = 1; i <= 1e6; i++)   
        cout << ans[i] << " ";
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++){
        solve(); 
    }
    return 0;
}