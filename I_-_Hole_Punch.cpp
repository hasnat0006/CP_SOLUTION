#include<bits/stdc++.h>
#define int long long
#define float double
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
using namespace std;
void solve()
{
    int n;
    cin >> n;
    int cnt=0;
    vector<int>v;
    while(n>1)
    {
        cnt++;
        if(n%2==1)
            n=(n/2)+1;
        else
            n/=2;
        v.push_back(n);
    }
    sort(v.begin(),v.end());
    cout<<cnt<<endl;
    for (int i = 0; i < v.size(); i++)
        cout<<v[i]<<" ";
    cout<<endl;
}
int32_t main()
{
    int t=1;
    //cin >> t;
    while(t--)
        solve();
    return 0;
}