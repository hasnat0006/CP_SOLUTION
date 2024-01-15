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
    int n;
    cin >> n;
    string s, ans, copy;
    cin >> s;
    copy = s;
    // sort(copy.begin(), copy.end());
    set<char> set;
    vector<int> freq(26);
    for (int i = 0; i < n; i++)
    {
        set.insert(copy[i]);
        freq[copy[i] - 'a']++;
    }
    // cout << set.size() << endl;
    if (set.size() < 26)
    {
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] == 0)
            {
                char temp = i + 'a';
                cout << temp << endl;
                return;
            }
        }
    }
    // find lenght of 2
    string demo = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < demo.size(); i++)
    {
        for (int j = 0; j < demo.size(); j++)
        {
            string temp;
            temp.pb(demo[i]);
            temp.pb(demo[j]);
            if (s.find(temp) == string::npos)
            {
                cout << temp << "\n";
                return;
            }
        }
    }
    // find lenght of 3
    for (int i = 0; i < demo.size(); i++)
    {
        for (int j = 0; j < demo.size(); j++)
        {
            for (int k = 0; k < demo.size(); k++)
            {
                string temp;
                temp.pb(demo[i]);
                temp.pb(demo[j]);
                temp.pb(demo[k]);
                if (s.find(temp) == string::npos)
                {
                    cout << temp << "\n";
                    return;
                }
            }
        }
    }
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