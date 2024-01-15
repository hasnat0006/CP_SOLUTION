#include <bits/stdc++.h>
#define int long long
#define float double
#define pb push_back
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
using namespace std;
void solve()
{
    int n, x, c = 0;
    cin >> n;
    vector<int> v(n);
    vector<int> freq(n + 1);
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        freq[v[i]]++;
    }
    // sort(v.rbegin(), v.rend());
    vector<pair<int, int>> vp(n);
    for (int i = n - 1; i >= 0; i--)
    {
        if (m[v[i]] == 1)
            break;
        m[v[i]] = 1;
        // cout << m[v[i]] << " ";
        c++;
    }
    // cout<<endl;
    if(c==n)
        cout<<"0\n";
    else
        cout<<n-c<<endl;
    
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