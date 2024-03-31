
#include <bits/stdc++.h>
using namespace std;

void test_case()
{
    int n;
    cin >> n;
    vector<pair<int, int>> all;
    for (int p = 2; p * p <= n; p++)
    {
        if (n % p == 0)
        {
            int count = 0;
            while (n % p == 0)
            {
                count++;
                n /= p;
            }
            all.emplace_back(p, count);
        }
    }
    if (n > 1)
    {
        all.emplace_back(n, 1);
    }
    int sum = 0;
    while (true)
    {
        int product = 1;
        for (pair<int, int> &p : all)
        {
            if (p.second > 0)
            {
                product *= p.first;
                p.second--;
            }
        }
        if (product == 1)
        {
            break;
        }
        sum += product;
    }
    cout << sum << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        test_case();
    }
}
