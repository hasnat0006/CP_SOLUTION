//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)

int mod = 1000000007;
int inf = 1e18;

int prime[20000005];
void sieve(int n) {
    for (int i = 2; i <= n; i++) {
        prime[i] = 1;
    }
    for (int i = 4; i <= n; i += 2) {
        prime[i] = 0;
    }
    for (int i = 3; i * i <= n; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= n; j += i * 2)
                prime[j] = 0;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> ans;
    int cnt = 0;
    if (n % 2)
        ans.push_back(1), cnt = 1;
    for (int i = 2; cnt < n; i++)
        if (prime[i])
            ans.push_back(i), ans.push_back(i), cnt += 2;
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;
}

int32_t main() {
    YUSUF REZA HASNAT;
    sieve(1e6);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}