//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 14|10|2024 01:08:07            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

const int mod = 1e9 + 7;
const int inf = 1e18;

const int N = 1e6 + 5;
int prime[N], actualPrime[N];
vector<int> store;

bool hasZero(string &s) {
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            return true;
        }
    }
    return false;
}

bool checkPrime(int n){
    string s = to_string(n);
    if(hasZero(s))
        return false;
    while ((int)s.size() > 0) {
        int num = stoll(s);
        if (!prime[num]) {
            return false;
        }
        s.erase(s.begin());
    }
    return true;
}

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
    for (int i = 2; i < N; i++) {
        if (prime[i]) {
            actualPrime[i] = checkPrime(i);
        }
    }
    for (int i = 2; i < N; i++) {
        if (actualPrime[i])
            store.push_back(i);
    }
}

void solve() {
    int n;
    cin >> n;
    cout << upper_bound(vf(store), n) - store.begin() << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    sieveOfEratosthenes();
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}