//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 20|09|2024 20:04:10            !//
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

bool hasZero(string &s) {
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            return true;
        }
    }
    return false;
}

vector<int> primes;
bool prime[1000005];
bool isGood(int n) {
    string s = to_string(n);
    if (hasZero(s))
        return false;
    while (s.size() > 1) {
        s.erase(s.begin());
        if (!prime[stoi(s)])
            return false;
    }
    return true;
}

void sieve(int n) {
    for (int i = 2; i <= n; i++)
        prime[i] = 1;
    for (int i = 4; i <= n; i += 2)
        prime[i] = 0;
    for (int i = 3; i * i <= n; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= n; j += i * 2)
                prime[j] = 0;
        }
    }
    for (int i = 2; i <= n; i++) {
        if (prime[i]) {
            if (isGood(i))
                primes.push_back(i);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    int id = upper_bound(vf(primes), n) - primes.begin();
    cout << id << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    sieve(1000005);
    // for (int i = 0; i < 10; i++) {
    //     cout << primes[i] << " ";
    // }
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}