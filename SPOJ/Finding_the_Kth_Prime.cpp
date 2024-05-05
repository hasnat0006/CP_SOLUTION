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

const int MX = 86200005;
vector<int> nth_prime;
bitset<MX> visited;
void optimized_prime() {
    nth_prime.push_back(2);
    for (int i = 3; i < MX; i += 2) {
        if (visited[i])
            continue;
        nth_prime.push_back(i);
        if (1ll * i * i > MX)
            continue;
        for (int j = i * i; j < MX; j += i + i)
            visited[j] = true;
    }
}

void solve() {
    optimized_prime();
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        cout << nth_prime[x - 1] << endl;
    }
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}