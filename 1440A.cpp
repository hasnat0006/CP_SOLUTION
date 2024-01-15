#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n, c0, c1, h, c = 0;
    string s;
    int ans = 0;
    cin >> n >> c0 >> c1 >> h;
    getchar();
    getline(cin,s);
    int arr[3];
    int rai1=0, rai0=0;
    for (int i = 0; s[i]; i++)
    {
        if (s[i] == '0')
            rai0++;
        else
            rai1++;
    }
    arr[0] = rai0*c0+(rai1*c1);
    arr[1] = (n * c1) + (rai0 * h);
    arr[2] = (n * c0) + (rai1 * h);
    sort(arr, arr + 3);
    cout << arr[0] << endl;
}
int32_t main()
{
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}