#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int n;
        cin >> n;
        vector<int> ami(n);
        for (int i = 0; i < n; i++)
            cin >> ami[i];
        sort(ami.begin(), ami.end());
        int x = max((ami[0] * ami[1]), (ami[n - 1] * ami[n - 2]));
        cout << x << endl;
    }
    return 0;
}