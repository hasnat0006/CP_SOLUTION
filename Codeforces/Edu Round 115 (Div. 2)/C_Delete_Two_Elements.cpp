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
    int n;
    cin >> n;
    vector<int> v(n);
    map<int, int> m;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        m[v[i]]++;
        sum += v[i];
    }
    // sort(v.begin(), v.end());
    // cout << sum << endl;
    float mean = sum / (n * 1.0);
    float drkr = mean * (n - 2);
    float bad = sum - drkr;
    // cout << mean << endl;
    // cout << drkr << endl;
    if (bad - (int)bad != 0)
    {
        cout << "0\n";
        return;
    }
    // cout << "Bad-> " << bad << endl;
    int c = 0;
    for (auto it : m)
    {
        if (m[bad - it.first] != 0)
        {
            // cout << "-> " << m[bad - it.first] << endl;
            if (it.first == (bad - it.first))
                c += ((it.second - 1) * it.second);
            else
                c += (it.second * m[bad - it.first]);
        }
    }
    // cout << "ans-> " << c << endl;
    cout << c / 2 << endl;
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