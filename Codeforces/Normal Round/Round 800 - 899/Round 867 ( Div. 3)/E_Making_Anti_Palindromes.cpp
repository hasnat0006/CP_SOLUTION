//!................  CG o nai CP o nai :)  ................!//

#include <bits/stdc++.h>
#define int long long
#define float long double
#define pb push_back
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;

using namespace std;
bool isPalindrome(string str)
{
    int n = str.length();
    int c = 0;
    for (int i = 0; i < n / 2; i++)
    {
        if (str[i] != str[n - 1 - i])
        {
            c++;
        }
    }
    if (c == n / 2)
        return false;
    return true;
}

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n % 2 == 1)
    {
        cout << "-1\n";
        return;
    }
    int f = 1;
    if (!isPalindrome(s))
    {
        cout << "0\n";
        return;
    }
    map<char, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[s[i]]++;
        if (mp[s[i]] > n / 2)
        {
            cout << "-1\n";
            return;
        }
    }
    mp.clear();
    int c = 0, mx = 0;
    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] == s[n - 1 - i])
        {
            mp[s[i]]++;
            c++;
            mx = max(mx, mp[s[i]]);
        }
    }
    cout << max(mx, (++c) / 2) << endl;
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