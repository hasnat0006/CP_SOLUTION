#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        stack<int> id;
        bool f = false;
        int c = 0;
        while (s[c] == '?')
            s[c++] = '0';
        for (int i = 0; i < s.size(); i++)
        {
            // cout << i << " " << s[i] << endl;
            if (s[i] == '0')
            {
                for (int j = i + 1; j < s.size(); j++)
                {
                    if (s[j] == '?')
                        id.push(j);
                    else if (s[j] == '1')
                    {
                        i = j;
                        f = true;
                        break;
                    }
                }
                while (!id.empty())
                {
                    s[id.top()] = '0', id.pop();
                }
            }
            else if (s[i] == '?')
                s[i] = '1';
        }
        cout << s << endl;
    }
    return 0;
}