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
    int arr[n + 1];
    int c = 0;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 1; i <= n; i++)
        for (int j = arr[i] - i; j <= n; j += arr[i])
            if (j >= 0 and arr[i] * arr[j] == i + j and i < j)
                c++;
    cout << c << endl;
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