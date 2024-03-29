#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define endl "\n"
const int INFI = 1e18;
const int MOD = 1e9 + 7;

int max_xor_subarray(vector<int> &arr)
{
    int max_xor = 0;
    int prefix_xor = 0;
    unordered_set<int> prefix_xor_set;
    prefix_xor_set.insert(0);
    for (int num : arr)
    {
        prefix_xor ^= num;
        prefix_xor_set.insert(prefix_xor);
        for (int val : prefix_xor_set)
        {
            max_xor = max(max_xor, prefix_xor ^ val);
        }
    }
    return max_xor;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    // cin.ignore();
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n), final(n);
        for (auto &i : v)
            cin >> i;
        cout << max_xor_subarray(v) << endl;
    }
    return 0;
}