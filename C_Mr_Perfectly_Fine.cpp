//!................  CG o nai CP o nai :)  ................!//

#include <bits/stdc++.h>
#define int long long
#define float long double
#define pb push_back
#define endl "\n"
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

void solve()
{
    int n, x;
    cin >> n;
    string s;
    // map<int, int> skill1, skill2;
    set<int> st1, st2, st3;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> s;
        // skill1[s[0]] = x;
        // skill2[s[1]] = x;
        if (s[0] == '1')
            st1.insert(x);
        if (s[1] == '1')
            st2.insert(x);
        if (s[0] == '1' and s[1] == '1')
            st3.insert(x);
    }
    int ans = 0;
    if (st1.size() == 0 or st2.size() == 0)
    {
        cout << "-1\n";
        return;
    }
    for (auto it : st1)
    {
        ans += it;
        break;
    }
    for (auto it : st2)
    {
        ans += it;
        break;
    }
    int temp=INT_MAX;
    if (st3.size() != 0)
    {
        temp = 0;
        for (auto it : st3)
        {
            temp += it;
            break;
        }
    }
    cout << min(ans, temp) << endl;
}

int32_t main()
{
    fastio;
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}