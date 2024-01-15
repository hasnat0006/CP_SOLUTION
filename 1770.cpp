#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[100];
int b[100];
void find()
{
    int n, m, i;
    cin >> n >> m;
    for (i = 0; i < n; i++)
        cin >> a[i];
    for (i = 0; i < m; i++)
        cin >> b[i];
    for (int i = 0; i < m; i++)
    {
        sort(a,a+n);
        a[0]=b[i];
    }
    int sum=0;
    for (int i = 0; i < n; i++)
        sum+=a[i];
    cout << sum << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        find();
    return 0;
}