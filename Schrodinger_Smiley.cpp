//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#include <bits/stdc++.h>
// #include "debug.h"
using namespace std;

#define int long long
#define float long double
#define pb push_back
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)

int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
int inf = 1e18;

void print(stack<char> s)
{
    while (!s.empty())
        cout << s.top(), s.pop();
}

int ans(string &s)
{
    stack<char> st;
    int c = 0;
    for (int i = 0; i < s.size(); i++)
    {
        cout << i << " ";
        if (s[i] == ':' and st.empty())
            st.push(s[i]),
                print(st);
        else if (s[i] == ')' and (st.top() == ':' or st.top() == ')'))
            st.push(s[i]),
                print(st);
        else if (s[i] == ':' and st.top() == ')')
        {
            print(st);
            c++;
            i--;
            while (!st.empty())
                st.pop();
        }
        else
        {
            print(st);
            while (!st.empty())
                st.pop();
            if (s[i] == ':')
                st.push(s[i]);
        }
        // cout << endl;
        cout << "   C: " << c << endl;
    }
    return c;
}

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int c = 0, f = 0;
    map<int, vector<char>> mp;
    // cout << ans(s) << endl;
    vector<char> v;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == ':' and f == 0)
            v.pb(s[i]), f = 1;
        else if (s[i] == ')' and f == 1)
            v.pb(s[i]);
        else if (s[i] == ':' and f == 1 and v.back() == ')')
            v.pb(s[i]), mp[++c] = v, v.clear(), v.pb(s[i]);
        else
        {
            f = 0, v.clear();
            if (s[i] == ':')
                v.pb(s[i]), f = 1;
        }
        // debug(i);
        // debug(v);
    }
    // debug(mp)
    cout << mp.size() << endl;
}

int32_t main()
{
    // YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}