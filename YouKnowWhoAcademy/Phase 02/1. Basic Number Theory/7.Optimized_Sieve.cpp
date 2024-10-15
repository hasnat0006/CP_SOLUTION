//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 11|10|2024 23:18:51            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
#define endl "\n"

const int N = 1e8 + 5;
bool prime[N];
void solve() {
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
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (prime[i]) {
            if (cnt == 0)
                cout << i << endl;
            cnt++;
            cnt %= 100;
        }
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