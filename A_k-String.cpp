#include <bits/stdc++.h>
#define int long long
#define float double
#define pb push_back
using namespace std;
void solve()
{
    int n, x;
    bool f = true;
    cin >> n;
    string s, pair, ans;
    cin >> s;
    sort(s.begin(), s.end());
    int freq[27] = {0};
    for (int i = 0; i < s.length(); i++)
        freq[s[i] - 96]++;
    for (int i = 1; i < 27; i++)
        if (freq[i] > 0 and freq[i] % n != 0 and f == true)
            f = false;
    if (f == false)
    {
        cout << "-1\n";
        return;
    }
    for (int i = 0; i < 27; i++)
    {
        if (freq[i] > 0)
        {
            if (freq[i] == s.length())
            {
                cout << s << endl;
                return;
            }
            if (freq[i] >= n)
                x = freq[i] / n;
            else
                x = freq[i];
            while (x--)
            {
                int temp = 96 + i;
                pair.pb(char(temp));
            }
        }
    }
    // cout << "pair: " << pair << endl;
    int koybar = (s.length()) / pair.length();
    while (koybar--)
        ans += pair;
    cout << ans << endl;
}
int32_t main()
{
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}