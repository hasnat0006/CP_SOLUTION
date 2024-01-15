#include <bits/stdc++.h>
#define int long long
#define float double
#define pb push_back
using namespace std;
void solve()
{
    int n;
    bool f = false;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.pb(temp);
    }
    sort(v.begin(), v.end());
    int id = 0, sobcheye_kom = 999999999999, kom_paisi = 9999999999999;
    if (n == 2)
    {
        cout << v[0] << " " << v[1] << endl;
        return;
    }
    for (int i = 0; i < (v.size() - 1); ++i)
    {
        if ((v[i + 1] - v[i] < sobcheye_kom))
        {
            kom_paisi = i;
            sobcheye_kom = v[i + 1] - v[i];
        }
    }
    vector<int> ans;
    ans.pb(v[kom_paisi]); // todo--> 0 index e kom_paisi index er value dukaitesi...
    for (int i = kom_paisi + 2; i < n; i++)
        ans.pb(v[i]);
    for (int i = 0; i < kom_paisi; i++)
        ans.pb(v[i]);
    ans.pb(v[kom_paisi + 1]); //* last index e *kom_paisi+1 index er value dukaitesi...
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
}
int32_t main()
{
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}