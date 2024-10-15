//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 15|10|2024 21:07:48            !//
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
int prime[N];
vector<int> storing;
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
    for (int i = 2; i < N; i++)
        if (prime[i])
            storing.push_back(i);
}

void solve() {
    int n;
    cin >> n;
    int cnt = 1;
    for (auto prime : storing) {
        if (prime * prime > n)
            break;
        int power = 0;
        while (n % prime == 0) {
            n /= prime;
            power++;
        }
        cnt *= (power + 1);
    }
    if (n > 1) {
        cnt *= 2;
    }
    cout << cnt - 1 << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    sieveOfEratosthenes();
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}