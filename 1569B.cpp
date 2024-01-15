#include <bits/stdc++.h>
#define int long long
#define float double
#define pb push_back
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
using namespace std;
void solve()
{
    int n, f, equal, two = 0;
    cin >> n;
    string s;
    cin >> s;
    char ans[n][n];
    for (int i = 0; s[i]; ++i)
        if (s[i] == '2')
            two++;
    if (two == 1 or two == 2)
    {
        cout << "NO\n";
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                {
                    ans[i][j] = '=';
                    ans[j][i] = '=';
                }
                else
                    ans[i][j] = 'X';
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '2')
        {
            f = 0;
            for (int j = i; j < n; j++)
            {
                if (i == j)
                    ans[i][j] = 'X';
                else if (ans[i][j] != '=')
                {
                    if (f == 0)
                    {
                        ans[i][j] = '+';
                        ans[j][i] = '-';
                        f++;
                    }
                    else if (f == 1)
                    {
                        ans[i][j] = '-';
                        ans[j][i] = '+';
                        f++;
                    }
                    else
                    {
                        ans[i][j] = '=';
                        ans[j][i] = '=';
                        f++;
                    }
                }
            }
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << ans[i][j];
        cout << endl;
    }
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