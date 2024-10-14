#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
    int n, k, c = 0, f = 0, j = 1;
    cin >> n >> k;
    string s, srev;
    cin.ignore();
    cin >> s;
    if (n == 1 && k==1)
        cout << "0" << endl;
    else if(k==0)
        cout<<s<<endl;
    else
    {
        int arr[n];
        for (int i = 0; s[i]; i++)
        {
            arr[i] = s[i] - 48;
        }
        for (int i = 0; i < n; i++)
        {
            // cout<<arr[i]<<" ";
            if (c == k)
                break;
            else
            {
                if (arr[i] == 1 && f == 0)
                {
                    arr[i] = 1;
                    f = 1;
                }
                else if (arr[i] > 1 && f == 0)
                {
                    arr[i] = 1;
                    f = 1;
                    c++;
                }
                else if (f == 1)
                {
                    if (arr[i] != 0)
                    {
                        arr[i] = 0;
                        c++;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << arr[i];
        }
        cout << endl;
    }
    return 0;
}