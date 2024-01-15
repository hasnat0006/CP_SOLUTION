#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n, f = 1;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (i > 0)
        {
            if (arr[i] == arr[i - 1])
            {
                f++;
            }
        }
    }
    sort(arr, arr + n);
    //int c = 0;
    vector<int>big;
    vector<int>small;
    int bb=0;
    for (int i = n-1; i >= 0; i-=2)
    {
        big.push_back(arr[i]);
        bb++;
    }
    for (int i =n-2; i >= 0; i-=2)
    {
        small.push_back(arr[i]);
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<small[i]<<" ";
    // }
    
    if (f == n)
        cout << "NO" << endl;
    else
    {
        int c=0,b=0,s=0;
        cout << "YES" << endl;
        //for (int i = 0; i < n; i++)
        //{
            // if(c%2==0)
            // {
            //     cout<<big[b]<<" ";
            //     b++;
            //     c++;
            // }
            // else{
            //     cout<<small[s]<<" ";
            //     s++;
            //     c++;
            // }
            // if(i<=n/2)
            // {
            //     cout<<big[i]<<" ";
            // }
            // else
            //     cout<<small[i]<<" ";
        //}
        for (auto i = big.begin(); i != big.end(); i++)
        {
            cout<<*i<<" ";
        }
        for (auto i = small.end(); i!= small.begin(); i--)
        {
            cout<<*i<<" ";
        }
        
        cout << endl;
    }
}
int32_t main()
{
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}