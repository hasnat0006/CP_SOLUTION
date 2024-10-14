#include <bits/stdc++.h>
#define int long long
#define float double
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
using namespace std;
void solve()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << "1\n";
        return;
    }
    if (n == 2)
    {
        cout << "-1\n";
        return;
    }
    int c = 1;
    bool f = true;
    int arr[n][n];
    for (int i = 0; i < n; i++)
    {
        if (f == true)
        {
            for (int j = 0; j < n; j += 2)
            {
                arr[i][j] = c;
                c++;
            }
            f = false;
        }
        else
        {
            for (int j = 1; j < n; j += 2)
            {
                arr[i][j] = c;
                c++;
            }
            f = true;
        }
    }
    bool x=true;
    for (int i = 0; i < n; i++)
    {
        if (x == true)
        {
            for (int j = 1; j < n; j += 2)
            {
                arr[i][j] = c;
                c++;
            }
            x = false;
        }
        else
        {
            for (int j = 0; j < n; j += 2)
            {
                arr[i][j] = c;
                c++;
            }
            x = true;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << arr[i][j] << " ";
        cout << endl;
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