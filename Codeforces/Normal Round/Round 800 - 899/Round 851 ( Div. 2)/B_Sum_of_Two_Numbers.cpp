#include <bits/stdc++.h>
#define int long long
#define float double
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
using namespace std;
int koyta(int x)
{
    int c = 0;
    while (x > 0)
    {
        x / 10;
        c++;
    }
    return c;
}
int digit(int x)
{
    int r, sum = 0;
    while (x > 0)
    {
        r = x % 10;
        x = x / 10;
        sum = sum + r;
    }
    return sum;
}
void solve()
{
    int n;
    cin >> n;
    if (n % 2 == 0)
    {
        cout << n / 2 << " " << n / 2 << endl;
        return;
    }
    if ((n + 1) % 20 == 0)
    {
        string s, a1, a2;
        s = to_string(n);
        bool f = true;
        for (int i = 0; i < s.length(); i++)
        {
            int temp = s[i] - '0';
            if (temp % 2 == 0)
            {
                int x = temp / 2;
                string y = to_string(x);
                a1 += y;
                a2 += y;
            }
            else
            {
                int x = (temp / 2) + 1;
                int z = temp / 2;
                string a = to_string(x);
                string b = to_string(z);
                if (f == true)
                {
                    a1 += a;
                    a2 += b;
                    f = false;
                }
                else
                {
                    a1 += b;
                    a2 += a;
                    f = true;
                }
            }
        }
        int zero = 1;
        string a2_final;
        for (int i = 0; i < a2.length(); i++)
        {
            if (a2_final.length() == 0 and a2[i] == '0')
            {
            }
            else
                a2_final += a2[i];
        }
        // if (a2[0] == '0')
        //     a2.erase(a2.begin(), a2.begin() + 1);
        // if (a1[0] == '0')
        //     a1.erase(a1.begin(), a1.begin() + 1);
        cout << a1 << " " << a2_final << endl;
    }
    else
        cout << n / 2 << " " << (n / 2) + 1 << endl;
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