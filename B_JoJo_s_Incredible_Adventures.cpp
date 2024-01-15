//!................  CG o nai CP o nai :)  ................!//

#include <bits/stdc++.h>
#define int long long
#define float long double
#define pb push_back
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;

using namespace std;

void solve()
{
    string str;
    cin >> str;
    int one = 0, porpor1 = 0;
    if (str.find('0') == string::npos)
    {
        cout << str.size() * str.size() << "\n";
        return;
    }
    int cnt = 0, f = 1, first = 0, last = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '1')
        {
            one++;
        }
        else
        {
            if (f)
            {
                f = 0;
                first = one;
            }
            porpor1 = max(porpor1, one);
            one = 0;
            cnt++;
        }
    }
    // cout<<one << endl;
    porpor1 = max(porpor1, one);
    last = one;
    porpor1 = max(porpor1, (first + last));
    // cout << "Porpor 1-> " << porpor1 << endl;
    int ans = 0;
    if (cnt == 0)
        ans = str.size() * str.size();
    else
    {
        int r = (porpor1 - 1) / 2;
        ans = (porpor1 - r) * (r + 1);
    }
    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}