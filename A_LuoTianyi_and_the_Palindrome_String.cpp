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
// check a string is palindrome or not
bool isPalindrome(string S)
{
    for (int i = 0; i < S.length() / 2; i++)
    {
        if (S[i] != S[S.length() - i - 1])
        {
            return false;
        }
    }
    return true;
}
void solve()
{
    string s;
    cin >> s;
    if (s.length() == 1)
        cout << "-1\n";
    else if (!isPalindrome(s))
        cout << s.length() << endl;
    else
    {
        s.pop_back();
        if (!isPalindrome(s))
            cout << s.size() << endl;
        else
            cout << "-1\n";
    }
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