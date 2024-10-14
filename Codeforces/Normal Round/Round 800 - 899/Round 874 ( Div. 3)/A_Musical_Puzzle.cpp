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
    int n;
    cin >> n;
    set<string> st;
    string s;
    cin >> s;
    for (int i = 0; i < n - 1; i++)
    {
        string temp;
        temp.pb(s[i]);
        temp.pb(s[i + 1]);
        st.insert(temp);
    }
    // for (auto it : st)
    //     cout << it << " ";
    // cout << endl;
    cout << st.size() << endl;
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