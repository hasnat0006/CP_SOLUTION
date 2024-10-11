//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 10|10|2024 17:42:46            !//
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

int prime[10000005];
void sieve(int n) {
    for (int i = 2; i <= n; i++)
        prime[i] = 1;
    for (int i = 4; i <= n; i += 2)
        prime[i] = 0;
    for (int i = 3; i * i <= n; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= n; j += i * 2)
                prime[j] = 0;
        }
    }
}

int binaryExp(int base, int power) {
    int res = 1;
    while (power) {
        if (power & 1)
            res = (res * base);
        base = ((base) * (base));
        power /= 2;
    }
    return res;
}

vector<int> ans(1e7 + 1, 0);

void solve() {
    int n;
    cin >> n;
    cout << ans[n] << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    vector<int> visited(1e7 + 1, 0);
    for (int i = 1;; i++) {
        int x = binaryExp(i, 2);
        if(x > (int)1e7){
            break;
        }
        for (int j = 1;; j++) {
            int num = x + binaryExp(j, 4);
            if(num > (int)1e7){
                break;
            }
            visited[num] = 1;
        }
    }
    sieve(1e7);
    for(int i = 1; i <= (int) 1e7; i++){
        ans[i] = ans[i - 1] + (visited[i] == 1 && prime[i]); ;
    }
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}