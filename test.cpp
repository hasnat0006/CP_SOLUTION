#include <bits/stdc++.h>

using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
const double pai = acos(-1);
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
// tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

int main() {
    fastio();
    int n;
    cin >> n;
    int tc = n;
    map<string, int> m;
    vector<pair<int, pair<int, string>>> stu;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        int x;
        cin >> x;
        vector<int> v(6);
        for (int i = 0; i < 6; i++)
            cin >> v[i];
        sort(v.begin(), v.end());
        ll sum = 0;
        for (int i = 1; i < 5; i++)
            sum += v[i];
        sum += x * 10;
        // debug(sum);
        stu.push_back({sum, {-i, s}});
    }
    sort(stu.rbegin(), stu.rend());
    // debug(stu);
    int r = 1;
    ll curr = stu[0].first;
    ll cnt = 0;

    for (int i = 0; i < n; i++) {
        cnt++;
        // debug(cnt);
        if (cnt > 999)
            break;
        if (stu[i].first < curr) {
            r++;
            curr = stu[i].first;
            if (r > 2)
                break;
        }
        cout << stu[i].second.second << " " << stu[i].first << endl;
    }
}