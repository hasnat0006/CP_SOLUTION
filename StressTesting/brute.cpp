#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, i, j, mex = 0, tmp;
        cin >> n;
        vector<long long> a(n), dp(n, 1e18);
        map<int, int> mp;
        for (long long &x : a) {
            cin >> x;
            mp[x]++;
        }

        sort(a.begin(), a.end());
        for (i = 0; i < n; i++) {
            if (a[i] <= mex)
                mex = a[i] + 1;
            else
                break;
        }

        for (i = n - 1; i >= 0; i--) {
            if (i < n - 1 && a[i] == a[i + 1]) {
                dp[i] = dp[i + 1];
                continue;
            }
            if (a[i] > mex) {
                dp[i] = mex;
                continue;
            }
            if (mp[a[i]] == 1)
                dp[i] = a[i];
            else
                dp[i] = (mex * (mp[a[i]] - 1)) + a[i];
            for (j = i + 1; j < n; j++) {
                dp[i] = min(dp[i], dp[j] + (a[j] * (mp[a[i]] - 1)) + a[i]);
            }
        }

        cout << dp[0] << "\n";
    }

    return 0;
}