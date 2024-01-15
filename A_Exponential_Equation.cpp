#include <bits/stdc++.h>
#define int long long
#define float double
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
using namespace std;
int power(int a, int b, int n)
{
    int ans = 1;
    for (int i = 1; i <= b; i++)
    {
        ans *= a;
        if (ans >= n)
            return ans;
    }
    return ans;
}
void solve()
{
    int n;
    cin >> n;
    // int x = 49;
    // x++;
    // cout << x << endl;
    // for (int i = 01; i <= x; i++)
    // {
    //     if (n % i == 0)
    //     {
    // for (int j = 01; j <= x; j++)
    // int b=n/i;
    //         for (int j = i; j <= x; j++)
    //         {
    //             if (n % j == 0)
    //             {
    //                 int xxx = 1;
    //                 int temp1 = power(i, j, n);
    //                 xxx = j * temp1;
    //                 int yyy = 1;
    //                 int temp2 = power(j, i, n);
    //                 yyy = temp2 * i;
    // cout << "X " << xxx << " "<< "Y " << yyy << " " << xxx + yyy << endl;
    //                 if (xxx + yyy == n)
    //                 {
    //                     cout << i << " " << j << endl;
    //                     return;
    //                 }
    //             }
    //         }
    //     }
    // }
    if (n % 2 == 1)
        cout << "-1\n";
    else
        cout << "1 " << n / 2 << endl;
}
int32_t main()
{
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}