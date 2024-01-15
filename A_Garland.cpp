//!................  CG o nai CP o nai :)  ................!//

#include <bits/stdc++.h>
#define int long long
#define float long double
#define pb push_back
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
using namespace std;

void unsolve()
{
    string s;
    cin >> s;
    int freq[10] = {0};
    for (int i = 0; i < 4; i++)
        freq[s[i] - '0']++;
    sort(freq, freq + 10);
    // for (int i = 0; i < 5; i++)
    //     cout << freq[i] << " ";
    if (freq[9] == 4)
        cout << "-1" << endl;
    else if (freq[9] == 3)
        cout << "6" << endl;
    else
        cout << "4" << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        unsolve();
    return 0;
}