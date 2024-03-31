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
    if (n == 1)
    {
        cout << "1\n";
        return;
    }
    if (n % 2 == 1)
    {
        cout << "-1\n";
        return;
    }
    vector<int> a, b;
    for (int i = n; i > 0; i -= 2)
        a.pb(i);
    for (int i = 1; i < n; i += 2)
        b.pb(i);
    int a1 = 0, b1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            cout << a[a1++] << " ";
        else
            cout << b[b1++] << " ";
    }
    cout << endl;
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