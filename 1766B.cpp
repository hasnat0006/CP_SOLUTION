#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n,f=0;
    cin >> n;
    string s;
    cin>>s;
    //cout<<x<<endl;
    //sort(s.begin(),s.end());
    //cout<<s<<endl;
    for (int i = 0; s[i]; i++)
    {
        string sub=s.substr(i,2);
        int x=s.rfind(sub);
        //cout<<x<<" "<<i<<endl;
        if(x==i || x==i+1)
            continue;
        else if(x>=0 && x<=n)
        {
            f=1;
            break;
        }
    }
    if(f==1) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    //cout<<endl;

}
int32_t main()
{
    int t=1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}