//!................  CG o nai CP o nai :)  ................!//

#include <bits/stdc++.h>
#define int long long
#define float long double
#define pb push_back
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
using namespace std;

void unsolve()
{
    int n, m1 = -1, m2 = -1;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        if (b[i] < a[i])
            swap(b[i], a[i]);
    }
    m1 = *max_element(a.begin(), a.end());
    m2 = *max_element(b.begin(), b.end());
    if ((a[n - 1] == m1 and b[n - 1] == m2))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        unsolve();
    return 0;
}