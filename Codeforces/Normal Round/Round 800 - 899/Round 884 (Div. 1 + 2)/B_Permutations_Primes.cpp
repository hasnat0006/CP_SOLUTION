//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#include <bits/stdc++.h>
// #include "debug.h"
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
{
    int n;
    cin >> n;
    vector<int> pupil, jabo;
    if (n > 2)
        for (int i = 3; i <= n; i += 2)
            pupil.pb(i);
    for (int i = 2; i <= n; i += 2)
        jabo.pb(i);
    for (auto it : jabo)
        cout << it << " ";
    cout << "1 ";
    reverse(vf(pupil));
    for (auto it : pupil)
        cout << it << " ";
    cout << endl;
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