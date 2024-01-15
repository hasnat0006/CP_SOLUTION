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

int cal(int f, int s, int k) {
    int sum = 0;
    sum += (f * k);
    sum += (s * k);
    sum += (f * f);
    sum += (s * s);
    return sum;
}

int binaryExponentiation(int base, int power)
{
    if (power == 0)
        return 1;
    int ans = binaryExponentiation(base, power / 2);
    if (power % 2 == 1)
        return (((ans * ans)) * base);
    return (ans * ans);
}

void solve() {
    int n, k;
    cin >> n >> k;
    int total_pro = n / k;
    int low = 0, high = n, mid, ans;
    while (low <= high) {
        mid = (low + high) / 2;
        int first_r = mid / 2;
        int second_r = mid - first_r;
        int total = cal(first_r, second_r, k);
        if(total <= n){
            low = mid + 1;
            ans = mid;
        }
        else
            high = mid - 1;
    }
    // cout << ans << endl;
    cout << binaryExponentiation(2, ans) << endl;
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