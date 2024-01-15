//!................  CG o nai CP o nai :)  ................!//

#include <bits/stdc++.h>
#define int long long
#define float long double
#define pb push_back
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;

using namespace std;

int convert(int x)
{
    int ans = 0, gun = 1;
    while (x > 0)
    {
        int temp = x % 9;
        ans += (temp * gun);
        gun *= 10;
        x /= 9;
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    int x = convert(n);
    string s = to_string(x);
    for (int i = 0; i < s.size(); i++)
        if (s[i] >= '4' and s[i] <= '8')
            s[i] = s[i] + 1;
    cout << s << endl;
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