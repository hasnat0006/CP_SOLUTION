//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 15|10|2024 00:14:50            !//
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


const int N = 1e5 + 5;
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
    int m, n;
    cin >> m >> n;
    map<int, int> factorOfM;
    int num = m;
    while(num > 1){
        int r = spf[num];
        factorOfM[r]++;
        num /= r;
    }
    map<int,int> factorsTillN;
    for(int i = 1; i <= n; i++){
        num = i;
        while (num > 1) {
            int r = spf[num];
            factorsTillN[r]++;
            num /= r;
        }
    }
    int ans = inf;
    for(auto i : factorOfM){
        ans = min(ans, (int)factorsTillN[i.first] / i.second);
    }
    if (ans == inf or ans == 0) {
        cout << "Impossible to divide" << endl;
        return;
    }
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    smallestPrimeFactorUsingSeive();
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ":\n";
        solve();
    }
    return 0;
}