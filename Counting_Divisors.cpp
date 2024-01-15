//!................  CG o nai CP o nai :)  ................!//

#include <bits/stdc++.h>
#define int long long
#define float long double
#define pb push_back
#define endl "\n"
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int maxValue = 1e6 + 1;
vector<int> countDivisor(maxValue, 0);
void countingDivisor()
{
    for (int i = 1; i < maxValue; i++)
        for (int j = i; j < maxValue; j += i)
            countDivisor[j]++;
}

void solve()
{
    int n;
    cin >> n;
    cout << countDivisor[n] << endl;
}

int32_t main()
{
    fastio;
    int t = 1;
    cin >> t;
    countingDivisor();
    while (t--)
        solve();
    return 0;
}