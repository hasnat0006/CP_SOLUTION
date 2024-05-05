//!................  CG o nai CP o nai :)  ................!//

#include <bits/stdc++.h>
#define int long long
#define float long double
#define pb push_back
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;

using namespace std;

void solve()
{
    int n, x;
    cin >> n;
    deque<int> dq;
    stack<int> stk;
    char c;
    while (n--)
    {
        cin >> c;
        if (c == 'A')
        {
            cin >> x;
            if (dq.empty())
            {
                dq.push_back(x);
                stk.push(1);
            }
            else if (dq.back() > x)
            {
                dq.push_front(x);
                stk.push(0);
            }
            else
            {
                dq.push_back(x);
                stk.push(1);
            }
        }
        else if (c == 'R')
        {
            if (!dq.empty())
            {
                if (stk.top())
                {
                    dq.pop_back();
                    stk.pop();
                }
                else
                {
                    dq.pop_front();
                    stk.pop();
                }
            }
        }
        else
        {
            if (dq.empty())
                cout << "Empty\n";
            else
                cout << dq.back() << "\n";
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cout << "Case " << i << ":\n";
        solve();
    }
    return 0;
}