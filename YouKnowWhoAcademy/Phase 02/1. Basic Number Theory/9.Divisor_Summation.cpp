//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 14|10|2024 00:39:13            !//
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

const int N = 1e7 + 5;
int spf[N];
void smallestPrimeFactorUsingSeive() {
    for (int i = 2; i < N; i++) {
        if (spf[i] == 0) {
            for (int j = i; j < N; j += i) {
                if (spf[j] == 0)
                    spf[j] = i;
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;
    int store = n;
    int sum = 1;
    while (n > 1) {
        int factor = spf[n];
        int power_of_factor = 0;
        int power_cal = 1;
        while (n % factor == 0) {
            factor = spf[n];
            power_of_factor++;
            power_cal *= factor;
            n /= factor;
        }
        sum *= (power_cal * factor - 1) / (factor - 1);
    }
    cout << sum - store << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    smallestPrimeFactorUsingSeive();
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}