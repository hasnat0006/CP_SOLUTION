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
    string s;
    cin >> n >> s;
    int zero = 0;
    for (int i = 0; i < n; i++)
        if (s[i] == '0')
            zero++;
    if (zero == 1 or zero % 2 == 0)
        cout << "BOB\n";
    else
        cout << "ALICE\n";
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