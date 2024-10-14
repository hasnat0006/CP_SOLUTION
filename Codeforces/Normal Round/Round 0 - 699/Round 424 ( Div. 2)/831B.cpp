#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    string key1, key2, text;
    getline(cin, key1);
    getline(cin, key2);
    getline(cin, text);
    string key1up = key1;
    string key2up = key2;
    transform(key1up.begin(), key1up.end(), key1up.begin(), ::toupper);
    transform(key2up.begin(), key2up.end(), key2up.begin(), ::toupper);
    //cout << key1up << endl;
    for (int i = 0; text[i]; i++)
    {
        int x = key1.find(text[i]);
        if (x >= 0 && x <= 26)
        {
            cout << key2[x];
        }
        else
        {
            int X = key1up.find(text[i]);
            if (X >= 0 && X <= 26)
            {
                cout << key2up[X];
            }
            else
                cout << text[i];
        }
    }
}
    int32_t main()
    {
        int t = 1;
        // cin >> t;
        while (t--)
            solve();
        return 0;
    }