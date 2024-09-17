//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 17|09|2024 21:24:48            !//
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

const int MAX = 1000005;
int factor[1000005];

void primeFactorSeive() {
    for (int i = 2; i <= MAX; i++) {
        if (factor[i] == 0) {
            for (int j = i; j <= MAX; j += i) {
                if (factor[j] == 0)
                    factor[j] = i;
            }
        }
    }
}

void solve() {
    for(int i = 0; i < 10; i++) {
        cout << factor[i] << " ";
    }
    cout << endl;

    int n;
    cin >> n;
    
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    primeFactorSeive();
    cin >> t;
    for (int i = 1; i <= t; i++){
        solve(); 
    }
    return 0;
}