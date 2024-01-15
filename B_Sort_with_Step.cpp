//!................  CG o nai CP o nai :)  ................!//

#include <bits/stdc++.h>
#define int long long
#define float long double
#define pb push_back
#define endl "\n"
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;

using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if ((v[i] - (i + 1)) % k != 0)
            c++;
    }
    // cout << c << endl;
    if (c == 0)
        cout << "0\n";
    else if (c <= 2)
        cout << "1\n";
    else
        cout << "-1\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}