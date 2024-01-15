#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string str;
        cin >> str;
        string aa;
        aa.push_back(str[0]);
        char temp = str[0];
        for (int i = 1; i < n; i++)
        {
            // cout << i << " ";
            if (str[i] == temp)
            {
                i++;
                if (str[i] == temp)
                    i--;
                else if (i < n)
                {
                    aa.push_back(str[i]);
                    temp = str[i];
                }
                // cout << str[i] << endl;
            }
        }
        //     mmm[str[i]] = i;
        // while (1)
        // {
        //     int x = mmm[aa[aa.size() - 1]];
        //     cout << x << endl;
        //     if (x == n - 1)
        //         break;
        //     else
        //     {
        //         aa.push_back(str[x + 1]);
        //     }
        // }
        cout << aa << endl;
    }
    return 0;
}