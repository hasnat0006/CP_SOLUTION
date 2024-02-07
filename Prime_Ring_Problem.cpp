//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
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
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)

int mod = 1000000007;
int inf = 1e18;

int n;
set<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

int NUM[20];
bool used[20];

void print__() {
    for (int i = 0; i < n; i++) {
        if (i)
            cout << " ";
        cout << NUM[i];
    }
    cout << endl;
}

void solve(int i) {
    // print__();
    if (i == n) {
        if (primes.find(NUM[n - 1] + 1) != primes.end()) {
            // cout << "----------------" << endl;
            for (int j = 0; j < n; j++) {
                if (j)
                    cout << " ";
                cout << NUM[j];
            }
            cout << endl;
        }
        return;
    }
    for (int j = 2; j <= n; j++) {
        if (!used[j] and primes.find(j + NUM[i - 1]) != primes.end()) {
            used[j] = true, NUM[i] = j;
            solve(i + 1);
            used[j] = false;
        }
    }
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    while (cin >> n) {
        if (t > 1)
            cout << endl;
        cout << "Case " << t++ << ":" << endl;
        memset(NUM, 0, sizeof NUM);
        NUM[0] = 1;
        memset(used, 0, sizeof used);
        solve(1);
    }
    return 0;
}