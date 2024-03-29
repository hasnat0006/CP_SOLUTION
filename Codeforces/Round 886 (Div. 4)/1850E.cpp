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
#define endl "\n"
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)
#define dosomic(x) fixed << setprecision(x)

int mod = 1000000007;
float pi = acos(-1);
float inf = 1000000;

float ans(float a, float b, float c)
{
    float ans1 = ((-1 * b) + sqrt((pow(b, 2)) - 4 * a * c)) / (2 * a);
    float ans2 = ((-1 * b) - sqrt((pow(b, 2)) - 4 * a * c)) / (2 * a);
    return max(ans1, ans2);
}

void solve()
{
    float n, c;
    cin >> n >> c;
    int nn = n;
    n /= inf, c /= inf;
    dbg(nn, n, c);
    float aa, bb, cc;
    vector<float> v(nn);
    float sum1 = 0, sum2 = 0;
    for (int i = 0; i < nn; i++)
    {
        cin >> v[i];
        // v[i] /= inf;
        sum1 += v[i];
        sum2 += pow(v[i], 2);
    }
    sum1 /= inf, sum2 /= inf;
    dbg(v);
    aa = 4 * n;
    cc = sum2 - c;
    bb = 4 * sum1;
    dbg(aa, bb, cc);
    // int ansss = ceil(ans(aa, bb, cc));
    // cout << ansss << endl;
    cout << dosomic(0) << ans(aa, bb, cc) << endl;
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