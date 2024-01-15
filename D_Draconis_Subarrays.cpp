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
#define fl(i, n) for (int i = 0; i < n; i++)
#define rl(i, m, n) for (int i = n; i >= m; i--)
#define endl "\n"
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)

int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
int inf = 1e18;

using namespace std;
vector<int> lps;
void createLPS(vector<int> &diff2)
{
    lps.resize(diff2.size());
    int index = 0;
    for (int i = 1; i < diff2.size();)
    {
        if (diff2[index] == diff2[i])
        {
            lps[i] = index + 1;
            index++, i++;
        }
        else
        {
            if (index != 0)
                index = lps[index - 1];
            else
                lps[i] = index, i++;
        }
    }
    // debug(lps);
}

int kmp(vector<int> &diff1, vector<int> &diff2)
{
    int cnt_of_match = 0;
    createLPS(diff2);
    // debug(lps);
    int i = 0, j = 0; // i -> diff1, j -> diff2
    while (i < diff1.size())
    {
        if (diff1[i] == diff2[j])
            i++, j++;
        else
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
        if (j == diff2.size())
        {
            cnt_of_match++;
            // the index where match found -> (i - diff2.size());
            j = lps[j - 1];
        }
    }
    return cnt_of_match;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    map<int, int> mp;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i], mp[b[i]]++;
    if (n == 1)
    {
        cout << m << endl;
        return;
    }
    // debug(b);
    vector<int> diff1, diff2;
    for (int i = 0; i < n - 1; i++)
        diff1.pb(a[i] - a[i + 1]);
    for (int i = 0; i < m - 1; i++)
        diff2.pb(b[i] - b[i + 1]);
    // debug(diff1);
    // debug(diff2);
    cout << kmp(diff2, diff1) << endl;
}

int32_t main()
{
    YUSUF REZA HASNAT;
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}