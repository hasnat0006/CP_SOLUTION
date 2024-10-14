//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 13|10|2024 19:45:46            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug.h"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

const int mod = 1e9 + 7;
const int inf = 1e18;

const int N = 1e6 + 10;
int spf[N];

void smallestPrimeFactor() {
    for (int i = 2; i < N; i++) {
        spf[i] = i;
    }
    for (int i = 2; i < N; i++) {
        if (spf[i] == i) {
            for (int j = i; j < N; j += i)
                spf[j] = min(spf[j], i);
        }
    }
}

void solve() {
    smallestPrimeFactor();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cout << spf[x] << " ";
        int greatest_prime_factor = 0;
        int number_of_distinct_factor = 0;
        int number_of_factor = 0;
        int sum_of_divisor = 1;
        int number_of_divisor = 1;
        while (x > 1) {
            int factor = spf[x];
            number_of_distinct_factor++;
            greatest_prime_factor = factor;
            int power_of_k = 0;
            int prime_power = 1;
            while (x % factor == 0) {
                power_of_k++;
                number_of_factor++;
                prime_power *= factor;
                x /= factor;
            }
            number_of_divisor *= (power_of_k + 1);
            sum_of_divisor *= (prime_power * factor - 1) / (factor - 1);
        }
        cout << greatest_prime_factor << " ";
        cout << number_of_distinct_factor << " ";
        cout << number_of_factor << " ";
        cout << number_of_divisor << " ";
        cout << sum_of_divisor << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}