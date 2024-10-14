#include <bits/stdc++.h>
#define int long long
#define float double
#define pb push_back
#define endl "\n"
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
using namespace std;
void solve()
{
    int n, temp;
    cin >> n;
    vector<int> v_even, v_odd;
    vector<int> freq(1000001);
    for (int i = 0; i < n; ++i)
    {
        cin >> temp;
        if (temp % 2 == 0)
            v_even.push_back(temp);
        else if (temp % 2 == 1)
            v_odd.push_back(temp);
        freq[temp]++;
    }
    sort(v_even.rbegin(), v_even.rend());
    sort(v_odd.rbegin(), v_odd.rend());
    for (auto it : v_even)
        cout << it << " ";
    cout << endl;
    if (n == 2)
    {
        if (v_even[0] > v_odd[0])
            cout << v_even[0] << " " << v_odd[0] << endl;
        else
            cout << v_odd[0] << " " << v_even[0] << endl;
        return;
    }
    vector<pair<int, int>> ans;
    int pair = n / 2, c = 0;
    cout << v_even.size() << " " << v_odd.size() << endl;
    for (int i = 0; i < v_even.size() - 1; ++i)
    {
        for (int j = i + 1; j < v_even.size(); j++)
        {
            int MOD = v_even[i] % v_even[j];
            // cout << "% " << MOD << endl;
            if (MOD == 0 or freq[MOD] == 0)
            {
                ans.push_back({v_even[i], v_even[j]});
                c++;
            }
            if (c == pair)
                break;
        }
        if (c == pair)
            break;
    }
    if (c != pair)
    {
        for (int i = 0; i < v_odd.size() - 1; ++i)
        {
            for (int j = i + 1; j < v_odd.size(); j++)
            {
                int MOD = v_odd[i] % v_odd[j];
                // cout << "% " << MOD << endl;
                if (MOD == 0 or freq[MOD] == 0)
                {
                    ans.push_back({v_odd[i], v_odd[j]});
                    c++;
                }
                if (c == pair)
                    break;
            }
            if (c == pair)
                break;
        }
    }
    for (auto it : ans)
        cout << it.first << " " << it.second << endl;
    // cout << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}