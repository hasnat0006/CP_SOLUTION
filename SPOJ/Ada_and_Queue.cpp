//!................  CG o nai CP o nai :)  ................!//

#include <bits/stdc++.h>
#define int long long
#define float long double
#define pb push_back
#define endl "\n"
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;

using namespace std;

void solve()
{
    int n;
    cin >> n;
    deque<int> dq;
    int f = 1;
    while (n--)
    {
        string s;
        cin >> s;
        if (s == "toFront")
        {
            int x;
            cin >> x;
            if (f)
                dq.push_front(x);
            else
                dq.push_back(x);
        }
        else if (s == "push_back")
        {
            int x;
            cin >> x;
            if (f)
                dq.push_back(x);
            else
                dq.push_front(x);
        }
        else if (s == "reverse")
        {
            if (dq.size() >= 1)
            {
                if (f)
                    f = 0;
                else
                    f = 1;
            }
        }
        else if (s == "front")
        {
            if (dq.empty())
                cout << "No job for Ada?\n";
            else
            {
                if (f)
                    cout << dq.front() << endl, dq.pop_front();
                else
                    cout << dq.back() << endl, dq.pop_back();
            }
        }
        else if (s == "back")
        {
            if (dq.empty())
                cout << "No job for Ada?\n";
            else
            {
                if (f)
                    cout << dq.back() << endl, dq.pop_back();
                else
                    cout << dq.front() << endl, dq.pop_front();
            }
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}