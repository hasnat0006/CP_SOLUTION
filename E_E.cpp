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

void solve() {
    int pos, cir, people;
    cin >> pos >> cir >> people;
    int ans = 0;
    // if(people < pos){
    //     int p = pos - cir, q = people;
    //     if (__gcd(p, q) != 1) {
    //         int g = __gcd(p, q);
    //         p /= g;
    //         q /= g;
    //     }
    //     cout << p << "/" << q << endl;
    //     return;
    // }
    if (cir < pos)
        ans = pos - cir;
    if (pos % 2 == 0) {
        int p = ans, q = people - cir + 1;
        if (__gcd(p, q) != 1) {
            int g = __gcd(p, q);
            p /= g;
            q /= g;
        }
        ans == 0 ? cout << "0/1" << endl : cout << p << "/" << q << endl;
        return;
    }
    if (pos == 1) {
        ans += (log2(people)) - (log2(cir)) + 1;
        int p = ans, q = people - cir + 1;
        if (__gcd(p, q) != 1) {
            int g = __gcd(p, q);
            p /= g;
            q /= g;
        }
        cout << ans << "/" << q << endl;
        return;
    }
    int right = log2(people);
    // cout << right << endl;
    right -=(int) log2(pos);
    int left = log2(pos);
    ans += right;
    // cout << left << " " << right << " " << ans << endl;
    int p = ans, q = people - cir + 1;
    if (left <= right) {
        if (((people - pow(2, right)) * 2 + 1) >= pos)
            ans++;
        p = ans;
    }
    // cout << left << " " << right << " " << ans << endl;
    if (__gcd(p, q) != 1) {
        int g = __gcd(p, q);
        p /= g;
        q /= g;
    }
    cout << p << "/" << q << endl;
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}