#include <bits/stdc++.h>
#define int long long
#define float double
using namespace std;
void solve()
{
    int n;
    cin >> n;
    int arr[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    int c = -1;
    int f = 0;
    int it = 1;
    while (f == 0)
    {
        for (int i = 1; i < n; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                f = 0;
                break;
            }
            else
                f = 1;
        }
        if (it == 1)
        {
            it = 0;
            for (int i = 1; i < n; i += 2)
            {
                if (arr[i] > arr[i + 1])
                {
                    // cout << "*" << arr[i] << " " << arr[i + 1] << endl;
                    swap(arr[i], arr[i + 1]);
                    // c++;
                    // f = 0;
                }
            }
        }
        else
        {
            it = 1;
            for (int i = 2; i < n; i += 2)
            {
                if (arr[i] > arr[i + 1])
                {
                    // cout << "*" << arr[i] << " " << arr[i + 1] << endl;
                    swap(arr[i], arr[i + 1]);
                    // c++;
                    // f = 0;
                }
            }
        }
        c++;
    }
    // cout << "*";
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    cout << c << endl;
}
int32_t main()
{
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}