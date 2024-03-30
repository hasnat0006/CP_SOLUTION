#include <bits/stdc++.h>
#define int long long
#define float double
#define pb push_back
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
using namespace std;
void solve()
{
    int n;
    cin >> n;
    bool f;
    string s, copy;
    cin >> s;
    // cout << s << endl;
    // for (int i = 0; i <= n / 2; i++)
    // {
    //     if (s[i] == s[n - 1 - i])
    //         f = true;
    //     else
    //     {
    //         f = false;
    //         break;
    //     }
    // }
    // if (f)
    // {
    //     cout << "Yes\n";
    //     return;
    // }
    int c = 0, id1 = n, id2 = -1;
    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] != s[n - 1 - i])
        {
            if (c == 0)
                id1 = n - i - 1;
            else
                id2 = n - 1 - i;
            c++;
        }
        else if (c > 0 and s[i] == s[n - i - 1])
        {
            break;
        }
    }
    // cout << id1 << " " << id2 << endl;
    if (id2 == -1)
        id2 = id1;
    copy = s;
    // cout<<copy<<endl;
    // cout << id1 << " " << id2 << endl;
    for (int i = id2; i <= id1; i++)
    {
        if (copy[i] == '1')
            copy[i] = '0';
        else
            copy[i] = '1';
    }
    string temp;
    temp = copy;
    // cout << temp << endl;
    reverse(temp.begin(), temp.end());
    // cout << temp << endl;
    if (copy == temp)
        cout << "Yes\n";
    else
        cout << "No\n";
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}