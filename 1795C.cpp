//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 22|03|2024 03:10:27            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

int mod = 1000000007;
int inf = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 5), b(n + 5);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    vector<int> pre(n + 5, 0);
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + b[i];
    vector<int> times(n + 5, 0), extra(n + 5, 0);
    for (int i = 1; i <= n; i++) {
        if (pre[n] - pre[i - 1] <= a[i]) {
            times[i]++;
            times[n + 1]--;
            continue;
        }
        int low = i, high = n, ans = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (pre[mid] - pre[i - 1] <= a[i]) {
                ans = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        // cout<< i << " " << ans << endl;
        if (ans == -1)
            extra[i] += a[i];
        else {
            times[i]++;
            times[ans + 1]--;
            extra[ans + 1] += a[i] - (pre[ans] - pre[i - 1]);
        }
    }
    for (int i = 1; i <= n; i++)
        times[i] += times[i - 1];
    for (int i = 1; i <= n; i++)
        cout << times[i] * b[i] + extra[i] << " ";
    cout << endl;
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