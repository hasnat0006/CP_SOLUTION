#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x;
    cin >> n;
    int freq[5] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        freq[x]++;
    }
    int c = 0;
    c += freq[4];
    if (freq[2] % 2 == 1)
    {
        if (freq[1] > 0)
        {
            freq[1] -= 2;
            freq[2]++;
        }
    }
    c += freq[2] / 2;
    if (freq[2] % 2 == 1)
        c++;
    c += freq[3];
    freq[1] -= freq[3];
    if (freq[1] > 0)
    {
        if (freq[1] > 3)
            c += freq[1] / 4;
        if (freq[1] % 4 != 0)
            c++;
    }
    cout << c << endl;
}
