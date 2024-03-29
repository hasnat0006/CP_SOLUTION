#include <bits/stdc++.h>
#define int long long
#define float double
#define pb push_back
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    string s, copy;
    cin >> s;
    copy = s;
    for (int i = 0; s[i]; i++)
    {
        if (s[i] == '*')
        {
            s[i] = 'x';
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == '*')
        {
            s[i] = 'x';
            break;
        }
    }
    int id = -1;
    int aaa = 0;
    bool f = false;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (s[i] == 'x' and s[j] == 'x')
            {
                if ((j - i) > k)
                {
                    f = true;
                    aaa = 0;
                    for (int p = i; p < n; p++)
                    {
                        if ((p - i) > k)
                        {
                            s[id] = 'x';
                            aaa++;
                            break;
                        }
                        if (s[p] == '*')
                        {
                            id = p;
                        }
                    }
                }
            }
        }
    }
    int c = 0;
    if (f and aaa == 0)
    {
        c++;
    }
    // cout << id << endl;
    // cout << s << endl;
    for (int i = 0; i < n; i++)
        if (s[i] != copy[i])
            c++;
    cout << c << endl;
    // cout<<"\n";
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