//!................  CG o nai CP o nai :)  ................!//

#include <bits/stdc++.h>
#define int long long
#define float long double
#define pb push_back
#define endl "\n"
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;

using namespace std;
int N = 10000000;
vector<bool> is_prime(N + 1, true);

void check_prime()
{
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= N; i++)
    {
        if (is_prime[i] && (long long)i * i <= N)
        {
            for (int j = i * i; j <= N; j += i)
                is_prime[j] = false;
        }
    }
}
bool printDivisors(int n)
{
    vector<int> divisor;
    int milse = 0;
    // cout << "Number: " << n << endl;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            if (n / i == i)
            {
                divisor.pb(i);
                if (is_prime[i])
                    milse++;
            }
            else
            {
                divisor.pb(i);
                if (is_prime[i])
                    milse++;
                divisor.pb(n / i);
                if (is_prime[n / i])
                    milse++;
            }
        }
    }
    // cout << "Matched: " << milse << endl;
    // cout << "Size: " << divisor.size() << endl;
    if (milse <= (divisor.size() - milse) and divisor.size() != 0)
        return true;
    else
        return false;
    // sort(divisor.begin(), divisor.end());
}
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int c = 0, mul = 1;
    for (int i = 0; i < n; i++)
    {
        mul *= v[i];
        if (printDivisors(mul))
        {
            c++;
            mul = 1;
        }
        // cout << "i " << c << endl;
    }
    cout << c << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    int t = 1;
    cin >> t;
    check_prime();
    while (t--)
    {
        solve();
    }
    return 0;
}