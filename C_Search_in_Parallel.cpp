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
    int n, s1, s2;
    cin >> n >> s1 >> s2;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> a, b;
    if (max(s1, s2) >= n)
    {
        if (s1 == max(s1, s2))
        {
            for (int i = 0; i < n; i++)
            {
                b.pb(i + 1);
            }
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                a.pb(i + 1);
            }
        }
    }
    else if (s1 == s2)
    {
        for (int i = 0; i < n / 2; i++)
            b.pb(i + 1);
        for (int i = n / 2; i < n; i++)
            a.pb(i + 1);
    }
    else
    {
        int x = max(s1, s2);
        if (s1 == x)
        {
            // int c = 1;
            int temp = n / x;
            for (int i = 0; i < temp; i++)
                a.pb(i + 1);
            for (int i = temp; i < n; i++)
                b.pb(i + 1);
        }
        else
        {
            int temp = n / x;
            for (int i = 0; i < temp; i++)
                b.pb(i + 1);
            for (int i = temp; i < n; i++)
                a.pb(i + 1);
        }
    }
    cout << a.size() << " ";
    for (auto it : a)
        cout << it << " ";
    cout << endl;
    cout << b.size() << " ";
    for (auto it : b)
        cout << it << " ";
    cout << endl;
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