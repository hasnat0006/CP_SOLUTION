#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n, f = 1, c = 0;
    cin >> n;
    getchar();
    string s, finals;
    getline(cin, s);
    int l = s.length();
    while (l--)
    {
        int ff = 0;
        if (f == 0)//logva-->volga //abba-->baba
        {           /// olg
            f = 1;
            if (ff == 1)
            {
                finals = s[c];
                ff = 0;
            }
            else
            {
                ff=1;
                string temp,temp2;
                temp=s[c];
                temp2=finals;
                finals=temp+temp2;
            }
            s.erase(0, 1);
        }
        else
        {
            f = 0;
            finals.push_back(s[0]);
            s.erase(0, 1);
        }
        //cout << finals<<" "<<s<<endl;
    }
    cout<<finals<<endl;
    finals.pop_back();
    cout<<finals<<endl;
    //if(n%2==0) reverse(finals.begin(),finals.end());
    //cout << finals << endl;
}
int32_t main()
{
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}