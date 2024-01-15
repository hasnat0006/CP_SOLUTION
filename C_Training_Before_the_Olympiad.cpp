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

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    int even = 0, odd = 0, kombe = 0;
    vector<int> odd_index(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] % 2)
            odd_index[i] = 1;
    }
    vector<int> prefix(n);
    prefix[0] = v[0];
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + v[i];
    }
    dbg(prefix);
    int number_of_odd = 0;
    for (int i = 0; i < n; i++) {
        number_of_odd += odd_index[i];
        if (i == 0) {
            cout << prefix[i] << " ";
            continue;
        }
        int possible_ans = number_of_odd / 3;
        if (number_of_odd % 3 == 0 or number_of_odd % 3 == 2) {
            cout << prefix[i] - possible_ans << " ";
        }
        else {
            cout << prefix[i] - possible_ans - 1 << " ";
        }
        dbg(number_of_odd, possible_ans);
    }
    cout << endl;
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // case(i)
        solve();
    }
    return 0;
}