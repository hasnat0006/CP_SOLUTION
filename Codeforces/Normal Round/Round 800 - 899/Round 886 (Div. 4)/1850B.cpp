#include <bits/stdc++.h>
// #include "debug.h"
using namespace std;
#define int long long
#define float long double
#define endl "\n"
const int INFI = 1e18;
const int MOD = 1e9 + 7;
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int test_case = 1;
    cin >> test_case;
    // cin.ignore();
    while (test_case--)
    {
        int n, duru;
        cin >> n >> duru;
        vector<int> v(n);
        for (auto &i : v)
            cin >> i;
        sort(v.begin(), v.end());
        int paiei = 0, balll = 1;
        for (int i = 1; i < n; i++)
        {
            if (v[i] - v[i - 1] <= duru)
            {
                balll++;
            }
            else
            {
                paiei = max(paiei, balll);
                balll = 1;
            }
        }
        paiei = max(paiei, balll);
        cout << n - paiei << endl;
    }
    return 0;
}