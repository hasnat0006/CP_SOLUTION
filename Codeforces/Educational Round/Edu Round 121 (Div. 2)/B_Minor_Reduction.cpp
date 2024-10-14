#include <bits/stdc++.h>
#define int long long
#define float double
using namespace std;
// int i=1;
void solve()
{
    // cout<<"* "<<i<<" ";
    // i++;
    string s;
    cin >> s;
    int paisi = -1;
    if (s.length() == 2)
    {
        int first = s[0] - '0';
        int second = s[1] - '0';
        int replace = first + second;
        ostringstream temp;
        temp << replace;
        string x = temp.str();
        cout << x << endl;
        return;
    }
    int mn = 999999999999999;
    for (int i = 0; i < s.length() - 1; i++){
        if (((s[i] - '0') + (s[i + 1] - '0')) >= 10)
        {
            int temp = ((s[i] - '0') + (s[i + 1] - '0'));
            // if (temp <= mn)
            {
                mn = temp;
                paisi = i;
            }
        }
    }
    // cout<<paisi<<endl;
    if (paisi == -1)
    {
        int first = s[0] - '0';
        int second = s[1] - '0';
        int replace = first + second;
        ostringstream temp;
        temp << replace;
        string x = temp.str();
        s.erase(0, 2);
        s = x + s;
        cout << s << endl;
        return;
    }
    int first = s[paisi] - '0';
    int second = s[paisi + 1] - '0';
    // cout<<"1st "<<first<<" "<<"2nd "<<second<<endl;
    int replace = first + second;
    ostringstream temp;
    temp << replace;
    string x = temp.str();
    // cout<<x;
    s[paisi] = x[0];
    s[paisi + 1] = x[1];
    cout << s << endl;
}
int32_t main()
{
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}