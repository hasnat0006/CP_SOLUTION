#include <bits/stdc++.h>
#define int long long
#define float double
#define pb push_back
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
using namespace std;
int is_prime[1000001];
void seive()
{
    for (int i = 1; i <= 1000000; i++)
        is_prime[i] = 1;
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i * i <= 1000000; i++)
        if (is_prime[i])
            for (int j = i * i; j <= 1000000; j += i)
                is_prime[j] = 0;
}
void solve()
{
    int n;
    cin >> n;
    int x = sqrt(n);
    if (x * x == n)
    {
        if (is_prime[x] == 1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    else
        cout << "NO\n";
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    seive();
    while (t--)
        solve();
    return 0;
}