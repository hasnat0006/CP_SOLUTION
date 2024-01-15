#include <bits/stdc++.h>
#define int long long
#define float long double
#define pb push_back
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
using namespace std;
void solve()
{
    int x, y;
    char c;
    cin >> x >> y >> c;
    char arr[x][y];
    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            cin >> arr[i][j];
    set<char> s;
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            if (arr[i][j] == c)
            {
                if (j != y - 1)
                    if (arr[i][j + 1] != '.' and arr[i][j + 1] != c)
                        s.insert(arr[i][j + 1]);
                if (j != 0)
                    if (arr[i][j - 1] != '.' and arr[i][j - 1] != c)
                        s.insert(arr[i][j - 1]);
                if (i != 0)
                    if (arr[i - 1][j] != '.' and arr[i - 1][j] != c)
                        s.insert(arr[i - 1][j]);
                if (i != x - 1)
                    if (arr[i + 1][j] != '.' and arr[i + 1][j] != c)
                        s.insert(arr[i + 1][j]);
            }
        }
    }
    // for (auto it : s)
    //     cout << it << endl;
    cout << s.size() << endl;
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