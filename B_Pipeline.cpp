//!................  CG o nai CP o nai :)  ................!//

#include <bits/stdc++.h>
#define int long long
#define float long double
#define pb push_back
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
using namespace std;

int sum(int k)
{
    int sum = ((k * (k + 1)) / 2) - 1;
}
void unsolve()
{
    int n, k;
    cin >> n >> k; //! 2 3 4 5 6
    n = n - 1;
    k = k - 1;
    int s = sum(k);
    // else
    {
        int low = 0, high = k, ans = -1, mid;
        while (low <= high)
        {
            mid = (low + high) / 2;
            int p = sum(high);
            int x = sum(mid);
            int s = p - x;
            if (n >= s)
            {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        cout << ans << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        unsolve();
    return 0;
}