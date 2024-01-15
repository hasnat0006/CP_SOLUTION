#include <iostream>
#include <string>
#include <cstring>
#define ll long long
using namespace std;
int32_t main()
{
    ll n, k, i, max = 0, c = 0;
    cin >> n >> k;
    ll a[n];
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i == 0)
            c++;
        else if (a[i] != a[i - 1])
            c++;
        else if (a[i] == a[i - 1])
        {
            if (c > max)
                max = c;
            c = 1;
        }
    }
    cout << max;
    return 0;
}