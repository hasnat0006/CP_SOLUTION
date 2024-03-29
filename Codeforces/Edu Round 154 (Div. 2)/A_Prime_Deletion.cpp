//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "C:\Users\Yusuf Reza Hasnat\OneDrive\Desktop\CP\debug.h"
#else
#define dbg(x...)
#define dbgc(x...)
#endif

using namespace std;

#define int long long
#define float long double
#define pb push_back
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define dosomic(x) fixed << setprecision(x)
#define endl "\n"
#define case(x) cout << "Case " << x << ": "
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)

int mod = 1000000007;
float pi = acos(-1);
int inf = 1e18;

vector<int> prime(101);
void primes() {
    for (int i = 11; i <= 100; i++) {
        int f = 1;
        for (int j = 2; j < i; j++) {
            if (i % j == 0)
                f = 0;
        }
        if (f)
            prime[i] = 1;
    }
}

void solve() {
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        int pari_na_keno = s[i] - '0';
        pari_na_keno *= 10;
        for (int j = pari_na_keno; j < pari_na_keno + 10; j++) {
            if (prime[j]) {
                string x = to_string(j);
                if (x[0] == x[1])
                    continue;
                cout << j << endl;
                return;
            }
        }
    }
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    primes();
    for (int i = 1; i <= t; i++)
        // case(i)
        solve();
    return 0;
}