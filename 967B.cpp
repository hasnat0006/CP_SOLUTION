#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n,a,b,s=0;
    cin >> n>>a>>b;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
        s+=arr[i];
    }
    sort(arr+1,arr+n);
    // for (int i = 0; i < n; i++)
    //     cout<<arr[i]<<" ";
    // cout<<endl;
    int c=0,f=0,count=0;
    for (int i = n-1; i > 0; i--)
    {
        int xx=(a*arr[0])/s;
        if(xx>=b)
        {
            f=1;
            break;
        }
        count++;
        s=s-arr[i];
        //cout<<xx<<" "<<count<<endl;
    }
    cout<<count<<endl;
}
int32_t main()
{
    int t=1;
    //cin >> t;
    while(t--)
        solve();
    return 0;
}