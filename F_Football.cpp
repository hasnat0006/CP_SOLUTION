#include<bits/stdc++.h>
#define int long long
#define float double
using namespace std;
void solve()
{
    int n,a,b;
    cin >> n>>a>>b;
    if(n==1)
    {
        if(a==b)
            cout<<"1\n"<<a<<":"<<b<<endl;
        else
            cout<<"0\n"<<a<<":"<<b<<endl;
    }
    else
    {
        vector<int>x(n+1);
        vector<int>y(n+1);
        for (int i = 1; i <=n; i++)
            x[i]=y[i]=0;
        int draw=0;
        int position =1;
        for (; position <= n; )
        {
            if(a>0)
            {
                x[position]++;
                a--;
                position++;
            }
            else
                break;
        }
        if(a>0)
            x[1]+=a;
        if(b)
        {
            if(position==n+1)
            {
                x[n]--;
                x[1]++;
                y[n]=b;
            }
            else
            {

                for ( ; position <= n;)
                {
                    if(b>0)
                    {
                        y[position]++;
                        b--;
                        position++;
                    }
                    else
                        break;
                }
                if(b>0)
                    y[n]+=b;
            }
        }
        for (int i = 1; i <=n; i++)
            if(x[i]==y[i])
                draw++;
        cout<<draw<<endl;
        for (int i = 1; i <= n; i++)
            cout<<x[i]<<":"<<y[i]<<endl;
    }
}
int32_t main()
{
    int t=1;
    //cin >> t;
    while(t--)
        solve();
    return 0;
}