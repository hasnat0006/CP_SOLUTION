//!................  CG o nai CP o nai :)  ................!//

#include <bits/stdc++.h>
#define int long long
#define float long double
#define pb push_back
#define endl "\n";
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;

using namespace std;

void solve()
{
    int n;
    while (cin >> n)
    {
        stack<int> stk;
        queue<int> q;
        priority_queue<int> pq;
        int x, y;
        bool ss = 1;
        bool qq = 1;
        bool ppqq = 1;
        for (int i = 0; i < n; i++)
        {
            cin >> x >> y;
            if (x == 1)
            {
                if (ss)
                    stk.push(y);
                if (qq)
                    q.push(y);
                if (ppqq)
                    pq.push(y);
            }
            else
            {
                if (ss)
                {
                    if (!stk.empty() and stk.top() == y)
                        stk.pop();
                    else
                        ss = 0;
                }
                if (qq)
                {
                    if (!q.empty() and q.front() == y)
                        q.pop();
                    else
                        qq = 0;
                }
                if (ppqq)
                {
                    if (!pq.empty() and pq.top() == y)
                        pq.pop();
                    else
                        ppqq = 0;
                }
            }
        }
        if (ss and !qq and !ppqq)
            cout << "stack\n";
        else if (qq and !ss and !ppqq)
            cout << "queue\n";
        else if (ppqq and !ss and !qq)
            cout << "priority queue\n";
        else if (ss or qq or ppqq)
            cout << "not sure\n";
        else
            cout << "impossible\n";
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}