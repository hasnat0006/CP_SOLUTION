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

void solve() {
    // vector<int> v = {1, 2, 3, 4, 6, 7, 8, 9, 10, 5};
    // int mx = -1;
    // for (int i = 0; i < n; i++) {
    //     mx = max(mx, __gcd(v[i], v[(i % (n - 1)) + 1]));
    //     dbg(mx);
    // }
    int nnnn;
    cin >> nnnn;
    vector<int> tour;
    map<int, int> just_for_check;
    for (int i = nnnn; i > 0; i--) {
        int yooo = i;
        while (yooo > 1 and yooo % 2 == 0) {
            if (!just_for_check[yooo / 2])
                tour.push_back(yooo / 2), just_for_check[(yooo / 2)] = 1;
            if (!just_for_check[(yooo)])
                tour.push_back(yooo), just_for_check[(yooo)] = 1;
            yooo /= 2;
        }
    }
    for (int i = 1; i <= nnnn; i++)
        if (!just_for_check[i])
            tour.push_back(i), just_for_check[i] = 1;
    for (auto i : tour)
        cout << i << " ";
    cout << endl;
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        // case(i)
        solve();
    return 0;
}