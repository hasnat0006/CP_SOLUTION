//!................  CG o nai CP o nai :)  ................!//

#include <bits/stdc++.h>
#define int long long
#define float long double
#define pb push_back
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
using namespace std;

void unsolve()
{
    int m, c = 0;
    cin >> m;
    int mm = m;
    vector<int> v[m];
    while (m--)
    {
        int n;
        cin >> n;
        vector<int> temp(n);
        for (int i = 0; i < n; i++)
        {
            cin >> temp[i];
        }
        sort(temp.begin(), temp.end());
        v[c] = temp;
        c++;
    }
    vector<int> freq(50001), ans;
    for (int i = mm - 1; i >= 0; i--)
    {
        bool f = true;
        for (int j = v[i].size() - 1; j >= 0; j--)
        {
            if (freq[v[i][j]] == 0)
            {
                if (f)
                {
                    ans.pb(v[i][j]);
                    f = false;
                }
                freq[v[i][j]] = 1;
            }
        }
    }
    if (ans.size() != mm)
    {
        cout << "-1\n";
        return;
    }
    for (int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i] << " ";
    cout << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        unsolve();
    return 0;
}