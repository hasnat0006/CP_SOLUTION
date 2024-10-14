#include <bits/stdc++.h>
#define int long long
#define float long double
#define pb push_back
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int freq_up[27] = {0}, freq_low[27] = {0};
    for (int i = 0; i < n; i++)
    {
        if (s[i] >= 'a' and s[i] <= 'z')
            freq_low[s[i] - 'a']++;
        else
            freq_up[s[i] - 'A']++;
    }
    int c = 0, extra = 0;
    for (int i = 0; i < 27; i++)
    {
        c += min(freq_low[i], freq_up[i]);
        extra += (max(freq_low[i], freq_up[i]) - min(freq_low[i], freq_up[i])) / 2;
    }
    c += min(extra, k);
    cout << c << endl;
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