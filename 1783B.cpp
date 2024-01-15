#include<bits/stdc++.h>
#define int long long
#define float double
using namespace std;
void solve()
{
    int n;
    cin >> n;
    int arr[n],freq[n];
    for (int i = 0; i < n; i++)
    {
        freq[i]=0;
    }
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
        freq[arr[i]]++;
    }
    sort(arr,arr+n);
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
    int cnt=0,person=0;
    // for (int i = 0; i < n; i++)
    // {
    //     if(freq[i]!=0)
    //     {
    //         if(freq[i+1]==0)
    //             cnt++;
    //     }
    // }
    
    for (int i = 0; i < n; i++)
    {
        // if(arr[i]==0)
        //     cnt++;
        if(arr[i]<=i and arr[i+1]>i+1)
            cnt++;
    }
    if(arr[0]!=0)
        cnt++;
    cout<<cnt<<endl;
}
int32_t main()
{
    int t=1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}