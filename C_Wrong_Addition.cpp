//!................  CG o nai CP o nai :)  ................!//

#include <bits/stdc++.h>
#define int long long
#define float long double
#define pb push_back
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;

using namespace std;

void solve()
{
    string a, b, ans;
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int c = 0;
    // for (int i = b.size() - 1; i >= 0; i--)
    for (int i = 0; i < b.size(); i++)
    {
        if (b[i] < a[c])
        {
            string t1;
            if ((i + 1) != b.size())
                t1.pb(b[i + 1]);
            t1.pb(b[i]);
            int num1 = stoi(t1);
            int num2 = a[c] - '0';
            ans += (to_string(num1 - num2));
            i++;
            c++;
        }
        else
        {
            string t1;
            t1.pb(b[i]);
            int num1 = stoi(t1);
            int num2 = a[c] - '0';
            ans += (to_string(num1 - num2));
            c++;
        }
        if (c == a.size())
        {
            for (int j = i + 1; j < b.size(); j++)
                ans.pb(b[j]);
            break;
        }
    }
    // reverse(ans.begin(), ans.end());
    // reverse(ans.begin(), ans.end());
    // cout << ans << " " << a << endl;
    string temp;
    if (ans.size() > a.size())
    {
        c = 0;
        for (int i = 0; i < ans.size(); i++)
        {
            string t1;
            int num = (ans[i] - '0') + (a[c] - '0');
            t1 = to_string(num);
            reverse(t1.begin(), t1.end());
            temp += t1;
            c++;
            if (c == a.size())
            {
                for (int j = i + 1; j < ans.size(); j++)
                    temp.pb(ans[j]);
                break;
            }
        }
    }
    else
    {
        c = 0;
        for (int i = 0; i < a.size(); i++)
        {
            string t1;
            int num = (a[i] - '0') + (ans[c] - '0');
            t1 = to_string(num);
            reverse(t1.begin(), t1.end());
            temp += t1;
            c++;
            if (c == ans.size())
            {
                for (int j = i + 1; j < a.size(); j++)
                    temp.pb(a[j]);
                break;
            }
        }
    }
    // reverse(temp.begin(), temp.end());
    // cout << temp << endl;
    reverse(ans.begin(), ans.end());
    while (ans[0] == '0')
        ans.erase(ans.begin());
    if (temp == b)
        cout << ans << endl;
    else
        cout << "-1\n";
    // cout << endl;
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