//!................  CG o nai CP o nai :)  ................!//

#include <bits/stdc++.h>
#define int long long
#define float long double
#define pb push_back
#define endl "\n"
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

bool areBracketsBalanced(string &s)
{
    stack<char> temp;
    for (int i = 0; i < s.length(); i++)
    {
        if (temp.empty())
            temp.push(s[i]);
        else if ((temp.top() == '(' && s[i] == ')'))
            temp.pop();
        else
            temp.push(s[i]);
    }
    if (temp.empty())
        return true;
    return false;
}

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    string rev = s;
    reverse(rev.begin(), rev.end());
    int cgreat = 0, cless = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == ')')
            cgreat++;
        else
            cless++;
    }
    if (cgreat != cless)
    {
        cout << -1 << endl;
        return;
    }
    if (areBracketsBalanced(s) or areBracketsBalanced(rev))
    {
        cout << 1 << endl;
        while (n--)
            cout << 1 << " ";
        cout << endl;
        return;
    }
    stack<int> stk;
    vector<int> ans(n, 1);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            stk.push(i);
        else if (stk.size())
            ans[stk.top()] = 2, stk.pop(), ans[i] = 2;
    }
    cout << 2 << endl;
    for (auto it : ans)
        cout << it << " ";
    cout << endl;
}

int32_t main()
{
    fastio;
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}