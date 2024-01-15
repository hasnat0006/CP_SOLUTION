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
    int ans=n*(n*n+1);
    cout<<ans/2<<endl;
}
int32_t main()
{
    int t=1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}