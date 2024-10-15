//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 15|10|2024 12:45:23            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

const int mod = 1e9 + 7;
const int inf = 1e18;

const int N = 3e7 + 5;
int prime[N];
vector<pair<int,int>>storing;
void sieveOfEratosthenes() {
    for (int i = 2; i < N; i++)
        prime[i] = 1;
    for (int i = 4; i < N; i += 2)
        prime[i] = 0;
    for (int i = 3; i * i < N; i++) {
        if (prime[i]) {
            for (int j = i * i; j < N; j += i * 2)
                prime[j] = 0;
        }
    }
    for(int i = 1; i < N - 2;i++){
        if(prime[i] and prime[i + 2])
            storing.push_back({i, i + 2});
    }
}

void solve() {
    sieveOfEratosthenes();
    int n;
    while(cin >> n){
        cout << "(" << storing[n - 1].first << ", " << storing[n - 1].second << ")" << endl;
    }    
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