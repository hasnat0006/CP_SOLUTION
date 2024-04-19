//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 19|04|2024 21:32:00            !//
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

bool prime[1000001];
vector<int> v;
void sieve() {
    int n = 1000000;
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
        if (prime[i])
            v.push_back(i);
    }
}

void solve() {
    int n;
    cin >> n;
    if (n % 2) {
        cout << 1 << " ";
        n--;
    }
    for(int i = 0; i < n / 2; i++) {
        cout << v[i] << " " << v[i] << " ";
    }
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    sieve();
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}