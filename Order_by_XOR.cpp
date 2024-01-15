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
    int a, b, c;
    cin >> a >> b >> c;
    if (a > b and b > c)
        cout << a + 1 << endl;
    else if (a < b and b < c)
        cout << "0" << endl;
    else if ((a > b and b > c) or (a > b and b < c))
        cout << a << endl;
    else if (a > b and b < c)
    {
        if (min({a, b, c}) == 1)
            cout << "-1" << endl;
        else
            cout << min({a, b, c}) - 1 << endl;
    }
    else
        cout << "-1" << endl;
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