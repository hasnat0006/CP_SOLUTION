//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 12|06|2024 22:24:53            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

int mod = 1000000007;
int inf = 1e18;

const int N = 1e7 + 5;
int factor[N];
void primeFactorSeive() {
    for (int i = 2; i < N; i++) {
        if (factor[i] == 0) {
            for (int j = i; j < N; j += i) {
                if (factor[j] == 0)
                    factor[j] = i;
            }
        }
    }
}

bool prime[N];
vector<int> primes;
void sieve() {
    for (int i = 2; i < N; i++) {
        prime[i] = 1;
    }
    for (int i = 4; i < N; i += 2) {
        prime[i] = 0;
    }
    for (int i = 3; i * i < N; i++) {
        if (prime[i]) {
            for (int j = i * i; j < N; j += i * 2)
                prime[j] = 0;
        }
    }
    for(int i = 2; i < N; i++)
        if(prime[i])
            primes.push_back(i);
}



void solve() {
    int n;
    cin >> n;
    set <int> st;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        while(x > 1){
            st.insert(factor[x]);
            x /= factor[x];
        }
    }
    for(auto i : primes){
        if(st.find(i) == st.end()){
            cout << i << endl;
            return;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    primeFactorSeive();
    sieve();
    for (int i = 1; i <= t; i++) {
        // cout << "Case " << i << ": " << endl;
        solve();
    }
    return 0;
}
