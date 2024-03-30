//!................  CG o nai CP o nai :)  ................!//
#include <bits/stdc++.h>
#define int long long
#define float long double
#define pb push_back
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
using namespace std;
void solve()
{
    int n, q, sum = 0;
    cin >> n >> q;
    vector<int> v(n), pre(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        sum += v[i];
        pre[i] = sum;
    }
    // for (auto it : pre)
    //     cout << it << " ";
    // cout << endl;
    while (q--)
    {
        int l, r, k, ase;
        cin >> l >> r >> k;
        if (l > 1)
            ase = pre[r - 1] - pre[l - 2];
        else
            ase = pre[r - 1];
        int baki = sum - ase;
        int x = r - l + 1;
        int y = x * k;
        // cout << baki << " " << x << " " << y << endl;
        baki += y;
        // cout << baki << endl;
        if (baki % 2 == 1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}