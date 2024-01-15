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
    string s;
    cin >> s;
    vector<int> a, b;
    int left_sum = 0, right_sum = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L')
            a.pb(i), left_sum += i;
        else
            b.pb(i), right_sum += n - i - 1;
    }
    reverse(vf(a));
    int leftase = a.size(), rightase = b.size();
    vector<int> ans;
    while (a.size() and b.size()) {
        int l = a.back(), r = b.back();
        if(l > r)
            break;
        int lpabo = left_sum - (a.size() - 1) + (n - l - 1);
        int rpabo = right_sum - (b.size() - 1) + (r);
        if (lpabo >= rpabo) {
            right_sum += rightase;
            ans.push_back(lpabo + right_sum);
            left_sum = lpabo;
            a.pop_back();
        }
        else {
            left_sum += leftase;
            ans.push_back(rpabo + left_sum);
            right_sum = rpabo;
            b.pop_back();
        }
        dbg(lpabo, rpabo, left_sum, right_sum)
    }
    // while (a.size()) {
    //     int l = a.back();
    //     int lpabo = left_sum - (a.size() - 1) + (n - l - 1);
    //     ans.push_back(lpabo + right_sum);
    //     left_sum = lpabo;
    //     a.pop_back();
    // }
    // while (b.size()) {
    //     int r = b.back();
    //     int rpabo = right_sum - (b.size() - 1) + (r);
    //     ans.push_back(rpabo + left_sum);
    //     right_sum = rpabo;
    //     b.pop_back();
    // }
    for (auto i : ans)
        cout << i << " ";
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