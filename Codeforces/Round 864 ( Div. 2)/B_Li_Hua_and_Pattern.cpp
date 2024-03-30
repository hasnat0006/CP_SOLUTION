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
    int n, k;
    cin >> n >> k;
    int arr[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    int diff = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] != arr[n - i - 1][n - j - 1])
                diff++;
            // cout << i << " " << j << "-> " << diff << endl;
        }
    }
    diff = diff / 2;
    if (diff / 2 <= k)
    {
        k -= diff;
        if (k < 0)
            cout << "NO" << endl;
        else if (k % 2 == 0 or (k % 2 == 1 and n % 2 == 1))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    else
        cout << "NO" << endl;
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