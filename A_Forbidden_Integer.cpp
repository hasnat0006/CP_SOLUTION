//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#include <bits/stdc++.h>
#include "debug.h"
using namespace std;

#define int long long
#define float long double
#define pb push_back
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)

int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
int inf = 1e18;

void solve()
{    int n, k, x;
    cin >> n >> k >> x;
    vector<int> ans;
    if ((x == 1 and k == 1))
        cout << "NO\n";
    else if (n % 2 == 1)
    {
        cout << "YES\n";
        if(x != 1)
        {
            while (n--)
                cout << "1 ";
        }
        else
        {
            cout << "3 ";
            n -= 3;
            while (n != 0)
            {
                cout << "2 ";
                n -= 2;
            }
        }
        cout << endl;
    }
    else if (x != 2 and n % 2 == 0)
    {
        cout << "YES\n";
        n /= 2;
        while (n--)
            cout << "2 ";
        cout << endl;
    }
    else
        cout << "NO\n";
}

int32_t main()
{
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}