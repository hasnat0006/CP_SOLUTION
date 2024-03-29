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

int max_rectangle_area(vector<int> &v)
{
    int n = v.size();
    vector<int> left(n), right(n);
    stack<int> stk;
    for (int i = 0; i < n; i++)
    {
        if (stk.empty())
            left[i] = 0, stk.push(i);
        else
        {
            while (!stk.empty() and v[stk.top()] >= v[i])
                stk.pop();
            if (stk.empty())
                left[i] = 0;
            else
                left[i] = stk.top() + 1;
            stk.push(i);
        }
    }
    while (!stk.empty())
        stk.pop();
    for (int i = n - 1; i >= 0; i--)
    {
        if (stk.empty())
            right[i] = n - 1, stk.push(i);
        else
        {
            while (!stk.empty() and v[stk.top()] >= v[i])
                stk.pop();
            if (stk.empty())
                right[i] = n - 1;
            else
                right[i] = stk.top() - 1;
            stk.push(i);
        }
    }
    int max_area = -1;
    for (int i = 0; i < n; i++)
        max_area = max(max_area, (v[i] * (right[i] - left[i] + 1)));
    return max_area;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout << max_rectangle_area(v) << endl;
}

int32_t main()
{
    fastio;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        cout << "Case " << i << ": ", solve();
    return 0;
}