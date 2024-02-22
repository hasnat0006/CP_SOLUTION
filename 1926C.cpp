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
int sum[200005];

int DigitSum(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

void solve() {
    int n;
    cin >> n;
    cout << sum[n] << endl;
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    for(int i = 1; i <= 200000; i++)
        sum[i] = sum[i - 1] + DigitSum(i);
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}