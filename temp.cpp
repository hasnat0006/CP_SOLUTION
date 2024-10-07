//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 06|10|2024 00:44:53            !//
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

int prime[10010105];
vector<int> allPrimes;
map<int, int> mp;
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
            allPrimes.push_back(i);
            mp[i] = 1;
        }
    }
}


void solve() {
    int n;
    cin >> n;
    int ans = 0;
    int id = upper_bound(vf(allPrimes), n) - allPrimes.begin();
    for (int i = id - 1; i > 0; i--) {
        if(mp[allPrimes[i] - allPrimes[i - 1]] == 1 or allPrimes[i] - allPrimes[i - 1] == 1) {
            ans++;
        }
    }
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    freopen("prime_subtractorization_input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    sieve(10010100);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
