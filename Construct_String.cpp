//!................  CG o nai CP o nai :)  ................!//

#include <bits/stdc++.h>
#define int long long
#define float long double
#define pb push_back
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
using namespace std;

void unsolve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int c = 1;
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == s[i - 1])
        {
            c++;
            if (c == 3)
            {
                s.erase(s.begin() + (i - 2), s.begin() + (i));
                // cout << c << " " << i << endl;
                // cout << s << endl;
                c = 1;
                i -= 2;
            }
        }
        else
            c = 1;
    }
    cout << s << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        unsolve();
    return 0;
}