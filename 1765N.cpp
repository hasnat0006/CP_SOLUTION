#include<bits/stdc++.h>
#define int long long
#define float double
using namespace std;
void solve()
{
    // int k=stoi("252525");
    string temp,s;//?987654321

    cin>>s;
    int k;
    cin>>k;
    temp=s;
    sort(temp.begin(),temp.end());
    temp=temp.substr(0,(s.length()-k));
    cout<<temp<<endl;
}
int32_t main()
{
    int t=1;//todo-> ami kiso pari na keno??????????
    cin >> t;
    while(t--)
        solve();
    return 0;
}