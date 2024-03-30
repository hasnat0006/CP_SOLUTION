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

vector<int> primes = {1,  2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31,
                      37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79};
int x;
bool f = false;
vector<int> final;

void findSum(int i, int sum = 0, vector<int> v = {}) {
    if (sum == x and final.empty()) {
        for (auto i : v)
            final.push_back(i);
        f = true;
        return;
    }
    if (i == -1 or f or sum > x)
        return;
    findSum(i - 1, sum, v);
    v.push_back(primes[i]);
    findSum(i - 1, sum + primes[i], v);
}

void solve(int nn) {
    f = false;
    final.clear();
    int n = nn;
    cin >> n;
    x = n * n;
    findSum(primes.size() - 1);
    sort(final.begin(), final.end());
    int ans[n + 1][n + 1];
    memset(ans, -1, sizeof(ans));
    for (auto i : final) {
        int cnt = i;
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (__gcd(i, j) == 1 and __gcd(i, k) == 1 and cnt > 0 and
                    ans[j][k] == -1)
                    ans[j][k] = i, cnt--;
                if (cnt < 1)
                    break;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i][1];
        for (int j = 2; j <= n; j++) {
            cout << " " << ans[i][j];
        }
        cout << endl;
    }
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
    return 0;
}