#include <bits/stdc++.h>
#define int long long
#define float double
#define pb push_back
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
using namespace std;
void solve()
{
    string s;
    cin >> s;
    if (s.size() % 2 == 1 or s[0] == ')' or s[s.size() - 1] == '(')
    {
        cout << "NO\n";
        return;
    }
    int open = 0, ques = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            open++;
        else if (ques == 0 and open == 0 and s[i] == '?')
            ques++;
        else
        {
            if (open > 0)
                open--;
            else if (ques > 0)
                ques--;
            else
            {
                break;
            }
        }
        // cout << "OPEN-> " << open << " QUES-> " << ques << endl;
    }
    // cout << "OPEN-> " << open << " QUES-> " << ques << endl;
    if (open == 0 and ques == 0)
        cout << "YES\n";
    else
        cout << "NO\n";
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