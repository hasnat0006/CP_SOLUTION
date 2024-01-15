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
    int n, same = 0;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    if (n % 2 == 0)
    {
        cout << "YES\n";
        return;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (v[i] >= v[i + 1])
        {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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