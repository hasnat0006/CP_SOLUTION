#include <bits/stdc++.h>
#define int long long
#define float long double
#define pb push_back
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
using namespace std;
void solve()
{
    string s;
    cin >> s;
    int c = 0;
    vector<int> freq(27);
    for (int i = 0; i < s.length(); i++)
        freq[s[i] - 'A']++;
    int odd = 0, id = -1;
    for (int i = 0; i < 27; i++)
    {
        if (freq[i] % 2)
        {
            odd++;
            id = i;
        }
    }
    string ans1 = "", ans2 = "", final;
    // cout << ans1 << " " << ans2 << endl;
    if ((s.length() % 2 == 1 and odd > 1) or (s.length() % 2 == 0 and odd > 0))
        cout << "NO SOLUTION\n";
    else
    {
        for (int i = 0; i < 27; i++)
        {
            int x = freq[i] / 2;
            // cout << x << endl;
            while (x--)
            {
                ans1 += i + 'A';
                ans2 += i + 'A';
                // cout << ans1 << " " << ans2 << endl;
            }
        }
        // cout << ans1 << " " << ans2 << endl;
        if (s.length() % 2 == 1)
            ans1 += id + 'A';
        reverse(ans2.begin(), ans2.end());
        // cout << ans1 << " " << ans2 << endl;
        final = ans1 + ans2;
        cout << final << endl;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}