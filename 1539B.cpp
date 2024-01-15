#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
    int t, n;
    cin >> n >> t;
    string s;
    cin >> s;
    int arr[n+1];
    int sum=0;
    arr[0]=0;
    for (int i = 0; s[i]; i++)
        {
            int temp;
            temp=s[i]-'a'+1;
            sum+=temp;
            arr[i+1]=sum;
        }
    while (t--)
    {
        int l,r,ans;
        cin>>l>>r;
        ans=arr[r]-arr[l-1];
        cout<<ans<<endl;
    }
    return 0;
}