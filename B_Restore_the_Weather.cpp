#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> v(n), output, temp, exact(n);
        map<int, vector<int>> hasu;
        for (int i = 0; i < n; i++)
            cin >> v[i];
        for (int i = 0; i < n; i++)
            cin >> exact[i];
        temp = v;
        sort(temp.begin(), temp.end());
        sort(exact.begin(), exact.end());
        for (int i = 0; i < n; i++)
            hasu[temp[i]].push_back(exact[i]);
        for (int i = 0; i < n; i++)
        {
            output.push_back(hasu[v[i]][hasu[v[i]].size() - 1]);
            hasu[v[i]].pop_back();
        }
        for (auto it : output)
            cout << it << " ";
        cout << endl;
    }
    return 0;
}