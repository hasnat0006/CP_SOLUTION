#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int n;
    cin >> n;
    int arr[n][n];
    int big = n * n;
    int small = 1;
    if (n % 2 == 1)
    {
        for (int i = 0; i < n; i++)
        {
            for (int col = 0; col < n; col++)
            {
                if (col % 2 == 0 && i % 2 == 0)
                {
                    arr[i][col] = big;
                    big--;
                }
                else if (col % 2 == 1 && i % 2 == 1)
                {
                    arr[i][col] = big;
                    big--;
                }
                else
                {
                    arr[i][col] = small;
                    small++;
                }
            }
        }
    }
    else
    {
        int f = 0;
        // for (int row = 0; row < n; row++)
        // {
        //     for (int col = 0; col < n; col++)
        //     {
        //         if (col % 2 == 0)
        //         {
        //             if (row % 2 == 0 && f == 0)
        //             {
        //                 arr[row][col] = small;
        //                 small++;
        //                 f = 1;
        //             }
        //             else if (row % 2 == 1 && f == 1)
        //             {
        //                 arr[row][col] = big;
        //                 big--;
        //                 f = 0;
        //             }
        //         }
        //         else
        //         {
        //             if (row % 2 == 0)
        //             {
        //                 arr[col][n - row - 1] = big;
        //                 big--;
        //             }
        //             else
        //             {
        //                 arr[col][n - row - 1] = small;
        //                 small++;
        //             }
        //         }
        //     }
        // }
        int nn=n*n;
        int temp[nn];
        int c=0;
        //cout<<nn<<endl;
        for (int i = 0; i < nn; i++)
        {
            if(c%2==0)
            {
                temp[i]=small;
                small++;
                c=1;
            }
            else
            {
                temp[i]=big;
                big--;
                c=0;
            }
        }
        // for (int i = 0; i < nn; i++)
        // {
        //     cout<<temp[i]<<" ";
        // }
        int it=0;
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(i%2==0)
                {
                    arr[j][i]=temp[it];
                    it++;
                }
                else
                {
                    arr[n-j-1][i]=temp[it];
                    it++;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int col = 0; col < n; col++)
        {
            cout << arr[i][col] << " ";
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