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
    while (cin >> n and n)
    {
        while (1)
        {
            int f = 0;
            int x;
            stack<int> stk;
            vector<int> v(n);
            for (int i = 0; i < n; i++)
            {
                cin >> x;
                v[i] = x;
                if (!x)
                {
                    f = 1;
                    cout << endl;
                    break;
                }
            }
            if (f)
                break;
            int a = 1;
            f = 0;
            for (int i = 0; i < n; i++)
            {
                for (; a <= v[i]; a++)
                    stk.push(a);
                if (v[i] != stk.top())
                    f = 1;
                stk.pop();
            }
            if (!f)
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }
}

int32_t main()
{
    fastio;
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}