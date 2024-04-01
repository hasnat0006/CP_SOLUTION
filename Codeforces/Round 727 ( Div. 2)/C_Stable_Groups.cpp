//!................  CG o nai CP o nai :)  ................!//

#include <bits/stdc++.h>
#define int long long
#define float long double
#define pb push_back
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
using namespace std;

void unsolve()
{
    int n, x, k;
    cin >> n >> x >> k;
    vector<int> v(n), dif;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    // for (auto it : v)
    //     cout << it << " ";
    // cout << endl;
    int c = 1;
    for (int i = 0; i < n - 1; i++)
    {
        int p = v[i + 1] - v[i];
        if (p > k)
        {
            dif.pb(p - 1);
            c++;
        }
    }
    // cout << c << endl;
    sort(dif.begin(), dif.end());
    // for (auto it : dif)
    //     cout << it << " ";
    // cout << endl;
    for (int i = 0; i < dif.size(); i++)
    {
        if (dif[i] >= k and x > 0)
        {
            // x -= (dif[i] / k) - 1;
            // c++;
            x -= (dif[i] / k);
            dif[i] = (dif[i] / k);
            c--;
            // cout << x << endl;
        }
    }
    if (x < 0)
        c++;
    // for (auto it : dif)
    //     cout << it << " ";
    // cout << endl;
    // reverse(dif.begin(), dif.end());
    // for (int i = 0; i < dif.size() - 1; i++)
    // {
    //     if (dif[i] > k)
    //         c++;
    //     else
    //         break;
    // }
    cout << c << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        unsolve();
    return 0;
}