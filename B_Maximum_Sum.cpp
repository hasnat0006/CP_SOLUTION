#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> v(n), pre(n + 1), suf(n + 1);
        int total_sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        pre[1] = v[0];
        for (int i = 2; i <= n; i++)
            pre[i] = (pre[i - 1] + v[i - 1]);
        reverse(v.begin(), v.end());
        suf[1] = v[0];
        for (int i = 2; i <= n; i++)
            suf[i] = (suf[i - 1] + v[i - 1]);
        // for (auto it : pre)
        //     cout << it << " ";
        // cout << endl;
        // for (auto it : suf)
        //     cout << it << " ";
        // cout << endl;
        int ans = -1;
        string s = "*";
        for (int i = 0; i <= k; i++)
        {
            // if ((i + 1) * 2 - 1 >= 0 and (i + 1) * 2 - 1 < n and n - (k - (i + 1)) >= 0 and (k - (i + 1)) < n)
            {
                ans = max(ans, suf[n] - (pre[i * 2] + suf[k - i]));
                // cout << pre[(i + 1) * 2 - 1] << " " << suf[(k - (i + 1)) - 1] << endl;
                // cout << "remain " << suf[0] - (pre[(i + 1) * 2 - 1] + suf[n - (k - (i + 1))]) << endl;
            }
            // cout << ans << endl;
        }
        cout << ans << endl;
    }
}