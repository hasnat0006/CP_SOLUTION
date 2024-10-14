
#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
void solve()
{
    float n, m;
    int x;
    cin >> n >> m;
    vector<int> val;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        val.pb(x);
    }
    sort(val.begin(), val.end());
    while (m--)
    {
        float a, b, c;
        cin >> a >> b >> c;
        if (c < 0)
        {
            cout << "NO\n";
        }
        else
        {
            int high = n - 1;
            int low = 0, mid, ans = -1;
            bool f = false;
            while (low <= high)
            {
                mid = (low + high) / 2;
                int ac = 4 * a * c;
                if ((b - val[mid]) * (b - val[mid]) < ac)
                {
                    ans = val[mid];
                    f = true;
                    break;
                }
                else if (b < val[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            if (f)
            {
                cout << "YES\n"
                    << ans << "\n";
            }
            else
                cout << "NO\n";
        }
    }
    cout << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        solve();
    }
    return 0;
}