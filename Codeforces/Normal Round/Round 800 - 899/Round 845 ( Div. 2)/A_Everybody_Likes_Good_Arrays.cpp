#include <bits/stdc++.h>
#define int long long
#define float double
using namespace std;
void solve()
{
    {
        int n;
        cin >> n;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            v.push_back(temp);
        }
        int c = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (v[i] % 2 == 0 and v[i + 1] % 2 == 0)
            {
                int x = v[i];
                int y = v[i + 1];
                int gun = x * y;
                // cout<<"i "<<i<<endl;
                v.erase(v.begin() + i);
                // cout<<"gun: "<<gun<<endl;
                v[i] = 2;
                i = -1;
                n--;
                c++;
            }
            else if (v[i] % 2 == 1 and v[i + 1] % 2 == 1)
            {
                int x = v[i];
                int y = v[i + 1];
                int gun = x * y;
                v.erase(v.begin() + i);
                v[i] = 1;
                i = -1;
                n--;
                c++;
            }
        }
        cout << c << endl;
    }
}
int32_t main()
{
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}