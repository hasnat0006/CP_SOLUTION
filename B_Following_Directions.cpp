#include <bits/stdc++.h>
#define int long long
#define float double
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
using namespace std;
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int x = 0, y = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'U')
            y++;
        else if (s[i] == 'D')
            y--;
        else if (s[i] == 'R')
            x++;
        else if (s[i] == 'L')
            x--;
        if(x==1 and y==1)
        {
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
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