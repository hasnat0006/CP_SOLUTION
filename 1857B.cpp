//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "C:\Users\Yusuf Reza Hasnat\OneDrive\Desktop\CP\debug.h"
#else
#define dbg(x...)
#define dbgc(x...)
#endif

using namespace std;

#define int long long
#define float long double
#define pb push_back
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define dosomic(x) fixed << setprecision(x)
#define endl "\n"
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)

int mod = 1000000007;
float pi = acos(-1);
int inf = 1e18;

void solve()
{
    string hasu;
    cin >> hasu;
    int id = -1;
    for (int i = hasu.size() - 1; i >= 0; i--)
    {
        if (hasu[i] - '0' >= 5)
        {
            if (i != 0)
                hasu[i - 1] = hasu[i - 1] + 1, hasu[i] = '0';
            id = i;
        }
    }
    if (hasu[0] >= '5')
    {
        cout << 1;
        for (auto i : hasu)
            cout << 0;
        cout << endl;
        return;
    }
    if (id != -1)
        for (int i = id + 1; i < hasu.size(); i++)
            hasu[i] = '0';
    cout << hasu << endl;
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