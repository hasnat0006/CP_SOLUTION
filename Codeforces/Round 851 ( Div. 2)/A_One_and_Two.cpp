#include <bits/stdc++.h>
#define int long long
#define float double
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
using namespace std;
void solve()
{
    int n;
    cin >> n;
    int arr[n];
    int two = 0, one = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
        if (arr[i] == 2)
            two++;
        else if (arr[i] == 1)
            one++;
    }
    bool f = false;
    int id = -1;
    int drkr = two / 2;
    int paisi = 0;
    if (one == n)
    {
        cout << "1\n";
        return;
    }
    if (two % 2 == 1)
    {
        cout << "-1\n";
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (drkr == paisi)
            break;
        else if (arr[i] == 2)
        {
            id = i;
            paisi++;
        }
    }
    cout << id + 1 << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}