#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin >> n;
    long long arr[n];
    for (long long i = 0; i < n; i++)
        cin >> arr[i];
    long long c = 0;
    for (long long i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            c += arr[i - 1] - arr[i];
            arr[i] += arr[i - 1] - arr[i];
        }
        // cout << c << endl;
    }
    cout << c << endl;
    return 0;
}