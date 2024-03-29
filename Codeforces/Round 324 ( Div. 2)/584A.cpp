#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, t;
    cin >> n >> t;
    if (t >= 10 * n)
        cout << "-1";
    else
    {
        if (t == 10)
        {
            for (int i = 1; i < n; i++)
                cout << "1";
            cout << 0;
        }
        else
            for (int i = 1; i <= n; i++)
                cout << t;
    }
    return 0;
}