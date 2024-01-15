//!................  CG o nai CP o nai :)  ................!//

#include <bits/stdc++.h>
#define int long long
#define float long double
#define pb push_back
#define endl "\n"
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;

using namespace std;

void solve()
{
    int n, x;
    cin >> n;
    map<int, int> mp;
    set<int> st;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        st.insert(x);
        mp[x]++;
    }
    int ans = 0;
    for (auto it : st)
    {
        for (int i = 2; i * i <= it; i++)
        {
            if (it % (i * i) == 0)
            {
                int a = it;
                int b = a / i;
                int c = a / (i * i);
                ans += mp[a] * mp[b] * mp[c];
            }
        }
        if (mp[it] > 2)
        {
            ans += mp[it] * (mp[it] - 1) * (mp[it] - 2);
        }
    }
    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}