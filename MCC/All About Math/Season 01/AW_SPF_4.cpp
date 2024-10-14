//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 11|10|2024 12:39:45            !//
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

const int N = 1e7 + 100;
int factor[N];
void SmallestPrimeFactorSeive() {
    for (int i = 2; i < N; i++) {
        factor[i] = i;
    }

    for (int i = 2; i * i < N; i++) {
        if (factor[i] == i) {
            for (int j = i * i; j < N; j += i) {
                if (factor[j] == j) {
                    factor[j] = i;
                }
            }
        }
    }
}
vector<int> cntA(N, 0), cntB(N, 0);

void solve() {
    int a, b;
    cin >> a >> b;
    vector<int> A(a), B(b);
    for (int i = 0; i < a; i++) {
        int x;
        cin >> x;
        A[i] = x;
        while (x > 1) {
            int spf = factor[x];
            cntA[spf]++;
            x /= spf;
        }
    }
    for (int i = 0; i < b; i++) {
        int x;
        cin >> x;
        B[i] = x;
        while (x > 1) {
            int spf = factor[x];
            cntB[spf]++;
            x /= spf;
        }
    }
    cout << a << " " << b << endl;
    for (int i = 0; i < a; i++) {
        int num = 1;
        while (A[i] > 1) {
            int spf = factor[A[i]];
            if (cntB[spf] > 0)
                cntB[spf]--;
            else
                num *= spf;
            A[i] /= spf;
        }
        cout << num << " ";
    }
    cout << endl;
    for (int i = 0; i < b; i++) {
        int num = 1;
        while (B[i] > 1) {
            int spf = factor[B[i]];
            if (cntA[spf] > 0)
                cntA[spf]--;
            else
                num *= spf;
            B[i] /= spf;
        }
        cout << num << " ";
    }
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    SmallestPrimeFactorSeive();
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}