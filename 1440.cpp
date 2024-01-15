#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n, c0, c1, h, c = 0;
    string s;
    int ans = 0;
    cin >> n >> c0 >> c1 >> h;
    cin >> s;
    if (c0 == c1 && c1 ==h)
        ans = ((s.length()) * c0);
    else if (h<=c0 || h<=c1)
    {
        if(c0>c1)
        {
            c=0;
            for (int i = 0; s[i]; i++)
            {
                if(s[i]=='0')
                {
                    s[i]='1';
                    c++;
                }
            }
            //cout<<c<<endl;
            ans=((s.length()*c1)+(c*h));
        }
        else if(c1>c0)
        {
            c=0;
            for (int i = 0; s[i]; i++)
            {
                if(s[i]=='1')
                {
                    s[i]='0';
                    c++;
                }
            }
            //cout<<c<<endl;
            ans=((s.length()*c0)+(c*h));
        }
        else
        {
            ans = ((s.length()) * c0);
        }
    }
    else
    {
        int x=0,y=0;
        for (int i = 0; s[i]; i++)
        {
            if(s[i]=='0')
                x++;
            else
                y++;
        }
        ans=(x*c0)+(y*c1);
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