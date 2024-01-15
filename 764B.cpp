#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin>>arr[i];
    for (int i = 0; i < n/2; i++)
    {
        if(i%2==0)
            swap(arr[i],arr[n-1-i]);
    }
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
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