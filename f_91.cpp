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

int McCarthy(int n) {
    if (n > 100)
        return n - 10;
    return McCarthy(McCarthy(n + 11));
}
int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    // cin >> t;
    for (int i = 1;; i++) {
        int a;
        cin >> a;
        if (a == 0)
            break;
        cout << "f91(" << a << ") = ";
        a > 100 ? cout << a - 10 << endl : cout << 91 << endl;
    }
    return 0;
}