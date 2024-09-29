//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 29|09|2024 23:22:41            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

#define int   long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

const int mod = 1e9 + 7;
const int inf = 1e18;

int findA(int b, int c, int d) {
    int a = 0;
    for (int i = 0; i < 62; i++) {  // 62 bits to cover up to 2^61
        int bit = 1LL << i;
        if ((d & bit) != 0) {
            if ((b & bit) == 0) {
                a |= bit;
            }
        }
        else {
            if ((c & bit) != 0) {
                a |= bit;
            }
        }
    }
    if (((a | b) - (a & c)) == d) {
        return a;
    }
    return -1;
}

void solve() {
    int t;
    cin >> t;
    vector<int> results;
    results.reserve(t);
    while (t--) {
        int b, c, d;
        cin >> b >> c >> d;
        results.push_back(findA(b, c, d));
        
    }
    for (int result : results) {
        cout << result << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    solve();
    return 0;
}
