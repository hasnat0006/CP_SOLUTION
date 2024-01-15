#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int x = n;
    int y = (n / 2);
    if (n % 2 == 1)
        y++;
    if (n == 1)
    {
        cout << n << endl;
        return 0;
    }
    if (n <= 3)
    {
        cout << "NO SOLUTION\n";
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 1)
            cout << x-- << " ";
        else
            cout << y-- << " ";
    }
    return 0;
}