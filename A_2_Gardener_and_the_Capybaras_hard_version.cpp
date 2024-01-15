#include<bits/stdc++.h>
#define int long long
#define float double
using namespace std;
void solve()
{
    string s;
    // getline(cin,s);
    cin>>s;
    // cout<<s;
    bool f=true;
    int l=s.length();
    // if(count(s.begin(),s.end(),'a')==l or count(s.begin(),s.end(),'b')==l)
    //     cout<<s[0]<<" "<<s.substr(1,l-2)<<" "<<s[l-1]<<endl;
    // else if(s[0]=='a')
    // {
    //     if(s[1]=='a')
    //         cout<<s[0]<<" "<<s[1]<<" "<<s.substr(2,l-1)<<endl;
    //     else
    //     {
    //         int index=-1;
    //         for (int i = 2; s[i]; i++)
    //         {
    //             if(s[i]=='a')
    //             {
    //                 index=i;
    //                 break;
    //             }
    //         }
    //         if(index==-1)
    //             cout<<s[0]<<" "<< s.substr(1,l-2)<<" "<<s[l-1]<<endl;
    //         else
    //             cout<<s[0]<<" "<<s.substr(1,index-1)<<" "<<s.substr(index,l-1)<<endl;
    //     }
    // }
    // else
    // {
    //     if(s[1]=='b')
    //         cout<<s[0]<<" "<<s[1]<<" "<<s.substr(2,l-1)<<endl;
    //     else
    //     {
    //         int index=-1;
    //         for (int i = 2; s[i]; i++)
    //         {
    //             if(s[i]=='b')
    //             {
    //                 index=i;
    //                 break;
    //             }
    //         }
    //         if(index==-1)
    //             cout<<s[0]<<" "<< s.substr(1,l-2)<<" "<<s[l-1]<<endl;
    //         else
    //             cout<<s[0]<<" "<<s.substr(1,index-1)<<" "<<s.substr(index,l-1)<<endl;
    //     }
    // }
    int find_a=-1;
    for (int i = 1; i < l; i++)
    {
        if(s[i]=='a')
        {
            find_a=i;
            break;
        }
    }
    //cout<<"leg: "<<l<<endl;
    cout<<"*"<<find_a<<endl;
    if(find_a<l-2 and find_a>0)
        cout<<s.substr(0,find_a)<<" "<<s[find_a]<<" "<<s.substr(find_a+1,l-1)<<endl;
    else
        cout<<s[0]<<" "<<s.substr(1,l-2)<<" "<<s[l-1]<<endl;
}
int32_t main()
{
    int t=1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}