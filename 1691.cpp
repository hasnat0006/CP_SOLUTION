#include <bits/stdc++.h>
using namespace std;
void find()
{
    int n, even = 0, odd = 0;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] % 2 == 0)
            even++;
        else
            odd++;
    }
    if (odd < even)
        cout << odd << endl;
    else
        cout << even << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        find();
    return 0;
}