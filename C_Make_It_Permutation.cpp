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
    int n, c, d, x;
    cin >> n >> c >> d;
    vector<int> v;
    map<int, int> mp;
    int age_paisi = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (mp[x] == 0)
            v.pb(x);
        if (mp[x] == 1)
            age_paisi++;
        mp[x] = 1;
    }
    int cost = 0;
    cost = age_paisi * c;
    int temp_cost = 0;

    sort(v.begin(), v.end());
    int add = 0, remove = 0, per = 0, p = 0;
    if (v[0] != 1)
    {
        temp_cost += d;
        v.insert(v.begin(), 1);
    }
    int num = 1;
    cout << "-> " << temp_cost << endl;
    for (auto it : v)
        cout << it << " ";
    cout << endl;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] != num)
        {
            if (i != 0)
                p = v[i] - v[i - 1] - 1;
            add = p * d;
            remove = ((v.size() - (i + 1)) + 1) * c;
            cout << "add: " << add << " remove: " << remove << endl;
            temp_cost += min(add, remove);
            if (remove <= add)
            {
                break;
            }
        }
        num++;
    }
    cout << "-> " << temp_cost << endl;
    cout << (cost + temp_cost) << endl;
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