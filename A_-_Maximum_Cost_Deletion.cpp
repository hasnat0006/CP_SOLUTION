#include <bits/stdc++.h>
#define int long long
#define float double
using namespace std;
void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    string str;
    cin >> str;
    int ans[3] = {0}, zero = 0, one = 0;
    for (int i = 0; str[i]; i++)
    {
        if (str[i] == '0')
            zero++;
        else
            one++;
    }
    int id;
    ans[0] = (a + b) * n;
    for (int i = 0; i<n; i++)
    {
        if (str[i] == '0')
        {
            id = i;
            int cnt = 0, j;
            for (j = id; str[j]; j++)
            {
                if (str[j] == '0')
                    cnt++;
                else
                    break;
            }
            i = j;
            ans[1] += (cnt * a) + b;
        }
    }
    if (one != 0)
        ans[1] += (one * a) + b;
    for (int i = 0; i<n; i++)
    {
        if (str[i] == '1')
        {
            id = i;
            int cnt = 0, j;
            for (j = id; str[j]; j++)
            {
                if (str[j] == '1')
                    cnt++;
                else
                    break;
            }
            i = j;
            ans[2] += (cnt * a) + b;
        }
    }
    if (zero != 0)
        ans[2] += (zero * a) + b;
    sort(ans, ans + 3);
    cout << ans[2] << endl;
}
int32_t main()
{
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}