#include <bits/stdc++.h>
using namespace std;
void find()
{
    int x, count = 0, f = 0, z = 0;
    cin >> x;
    int arr[4] = {0};
    int ans[3];
    ans[2] = x;
    for (int i = 1; i < 4; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i < 4; i++)
    {
        x = arr[x];
        if (x == 0)
            count++;
    }
    if (count == 1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        find();
    return 0;
}