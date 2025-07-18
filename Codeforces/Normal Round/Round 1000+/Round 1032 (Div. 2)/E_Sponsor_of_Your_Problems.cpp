#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll l, r;
    cin >> l >> r;
    string sl, sr;
    sl = to_string(l);
    sr = to_string(r);
    ll n = sl.size();
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (sl[i] == sr[i])
            ans += 2;
        else {
            if (sr[i] - sl[i] > 1)
                break;
            else {
                ll tempAns1 = 1, tempAns2 = 1;
                for (int j = i + 1; j < n; j++) {
                    if (sl[j] == '9')
                        tempAns1++;
                    else
                        break;
                    if (sr[j] == sl[j])
                        tempAns1++;
                }
                for (int j = i + 1; j < n; j++) {
                    if (sr[j] == '0')
                        tempAns2++;
                    else
                        break;
                    if (sr[j] == sl[j])
                        tempAns2++;
                }
                ans += min(tempAns1, tempAns2);
            }
            break;
        }
    }
    cout << ans << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}