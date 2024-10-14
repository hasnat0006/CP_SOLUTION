#include<bits/stdc++.h>
#define int long long
using namespace std;
int power(int i);
int32_t main()
{
    int n,l,r,temp;
    cin>>n>>l>>r;
    int min=0;
    int max=0;
    for(int i=0;i<n;i++)
    {
        if(i<r)
            temp=i;
        max+=power(temp);
    }
    for(int i=1;i<=n;i++)
    {
        if(i<=(n-l+1)) temp=0;
        else ++temp;
        min+=power(temp);
    }
    cout<<min<<" "<<max<<endl;
    return 0;
}
int power(int i)
{
    int m=1;
    for(int j=0;j<i;j++)
        m*=2;
    return m;
}