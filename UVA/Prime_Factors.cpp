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

bool prime[100005];
void sieve(int n = 100002) {
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

int factor(int n) {
    if (n % 2 == 0)
        return 2;
    for (int a = 3; a <= sqrt(n); a++) {
        if (n % a == 0)
            return a;
    }
    return n;
}

void solve() {
    int n;
    cin >> n;
    if (n == 0)
        exit(0);
    int r;
    if (n < 0)
        cout << n << " = " << -1 << " x ", n = -n;
    else
        cout << n << " = ";
    vector<int> v;
    while (n > 1) {
        r = factor(n);
        v.push_back(r);
        n /= r;
    }
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i < v.size() - 1)
            cout << " x ";
    }
    cout << endl;
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    // cin >> t;
    for (int i = 1;; i++) {
        solve();
    }
    return 0;
}