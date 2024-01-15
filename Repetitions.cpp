#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int c = 1, ans = -1;
    for (int i = 1; s[i]; i++)
    {
        if (s[i] == s[i - 1])
            c++;
        else
        {
            ans = max(ans, c);
            c = 1;
        }
        // cout << "c-> " << c << "ans-> " << ans << endl;
    }
    ans = max(ans, c);
    cout << ans << endl;
    return 0;
}