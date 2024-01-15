#include <bits/stdc++.h>
#define int long long
#define float double
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
using namespace std;
int32_t main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t = 1;
    cin >> t;
    for (int b = 1; b <= t; b++)
    {

        int n;
        cin >> n;
        char arr[3][n];
        int id = -1;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> arr[i][j];
                if (arr[i][j] == 'X')
                    id = i;
            }
        }
        // for (int i = 0; i < 3; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         cout << arr[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        int ans;
        int c = 0, drkr = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[1][j] == 'X')
            {
                c = 0;
            }
            else
            {
                if ((arr[0][j] == 'O' and arr[2][j] == 'X') or (arr[0][j] == 'X' and arr[2][j] == 'O') or (arr[0][j] == 'O' and arr[2][j] == 'O'))
                {
                    c++;
                    // cout << " c" << c << endl;
                    if (c == 2)
                    {
                        drkr++;
                    }
                    if (c == 3)
                    {
                        c = 0;
                    }
                }
            }
            cout << drkr << endl;
        }
        // if (c >= 2)
        //     drkr++;
        cout << drkr << endl;
        cout << "Case " << b << ": ";
        if (drkr % 2 == 0)
            cout << "Grandma\n";
        else
            cout << "Jhinuk\n";
    }

    return 0;
}