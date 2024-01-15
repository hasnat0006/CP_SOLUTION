
#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        string str;
        cin >> str;
        int id = -1;
        int min = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if ((str[i] - 'a') <= min)
            {
                min = str[i] - 'a';
                id = i;
            }
        }
        cout << str[id];
        str.erase(str.begin() + id);
        cout << str << endl;
        // cout << id << endl;
    }

    return 0;
}