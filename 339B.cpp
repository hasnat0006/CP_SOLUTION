#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,m,i;
    cin>>n>>m;
    long long arr[m];
    for ( i = 0; i < m; i++)
    {
        cin>>arr[i];
    }
    long long ans=0;
    for ( i = 0; i < m; i++)
    {
        if(i==0)
            ans=arr[i]-ans;
        else if(arr[i]<arr[i-1])
            ans=ans+(arr[i]+n-arr[i-1]);
        else if (arr[i]>arr[i-1])
            ans=ans+(arr[i]-arr[i-1]);
    }
    cout<<(ans-1);

    return 0;
}