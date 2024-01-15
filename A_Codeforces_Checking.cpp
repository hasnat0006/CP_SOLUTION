#include <bits/stdc++.h>
#define int long long
#define float double
using namespace std;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        string s = "codeforces";
        char p;
        cin >> p;
        int x = s.find(p);
        if (x >= 0 and x <= s.length())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}