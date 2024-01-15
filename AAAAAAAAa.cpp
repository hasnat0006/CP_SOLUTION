#include <bits/stdc++.h>
using namespace std;
int t, n;

bool check(int x, int y)
{
    return pow(x, y) * y + pow(y, x) * x == n;
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        int flag = 0;
        for (int i = 1; i <= sqrt(n); i++)
        {
            if (n % i == 0)
            {
                int j = n / i;
                if (check(i, j) || check(j, i))
                {
                    cout << i << " " << j << endl;
                    flag = 1;
                    break;
                }
            }
        }
        if (!flag)
            cout << -1 << endl;
    }
    return 0;
}
