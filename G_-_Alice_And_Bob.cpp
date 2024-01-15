#include <bits/stdc++.h>
#define int long long
#define float double
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<int> v_gcd;
    int cnt = 0;
    sort(v.begin(), v.end());
    while (n--)
    {
        sort(v.rbegin(), v.rend());
        // for (int i = 0; i < v.size(); i++)
        //     cout << v[i] << " ";
        // cout << endl;
        for (int i = 0; i < v.size() - 1; i++)
        {
            for (int j = i + 1; j < v.size(); j++)
            {
                int x = __gcd(v[i], v[j]);
                if (x != 1)
                {
                    // cout<<"i "<<v[i]<<" j "<<v[j]<<endl;
                    v[i] /= x;
                    v[j] /= x;
                    // cout<<"i "<<v[i]<<" j "<<v[j]<<endl;
                    cnt++;
                    break;
                }
            }
        }
        cout<<endl;
        // sort(v.rbegin(), v.rend());
        // for (int i = n - 1; i >= 0; i--)
        // {
        //     if (v[i] == 1)
        //         v.pop_back();
        // }
        // if(v.size()==1)
        //     break;
    }
    cout << cnt << endl;
    if (cnt % 2 == 1)
        cout << "Alice\n";
    else
        cout << "Bob\n";
}
int32_t main()
{
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}