// Author:           Syed Tamal
// Created:          04 Feb 2024  01:40:56

#include <bits/stdc++.h>
using namespace std;
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int ans = 1;
    for (int i = 2; i <= 10; i++) {
        int gcd = __gcd(ans, i);
        ans *= i;
        ans /= gcd;
    }
    int n;
    cin >> n;
    cout << n / ans << "\n";
}