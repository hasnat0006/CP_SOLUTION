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
    int n;
    cin >> n;
    int ans = 1;
    for (int i = 1; i <= (n + 1); i++)
        ans *= 2;
    cout << ans - 2 << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        unsolve();
    return 0;
}