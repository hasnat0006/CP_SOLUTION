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
    vector<int> arr(n);
    int ajke = 0, pupil = 0, jabo = -1 * inf;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    // debug(arr);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= 0)
            jabo = max(jabo, arr[i]);
        else if (i % 2 == 0)
            ajke += arr[i];
        else
            pupil += arr[i];
    }
    if (!ajke and !pupil)
        cout << jabo << endl;
    else
        cout << max(ajke, pupil) << endl;
    // cout << ajke << " " << pupil << endl;
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