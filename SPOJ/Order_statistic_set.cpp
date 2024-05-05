//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long
#define float long double
#define pb push_back
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)
#define ordered_set                              \
    tree<int, null_type, less<int>, rb_tree_tag, \
         tree_order_statistics_node_update>

int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
int inf = 1e18;

void print(ordered_set st) {
    cout << "print : ";
    for (auto it : st)
        cout << it << " ";
    cout << endl;
}

void solve() {
    int n, x;
    cin >> n;
    ordered_set st;
    while (n--) {
        string s;
        cin >> s >> x;
        if (s == "I")
            st.insert(x);
        else if (s == "K") {
            if (st.size() >= x)
                cout << *st.find_by_order(x - 1) << endl;
            else
                cout << "invalid\n";
        }
        else if (s == "C")
            cout << st.order_of_key(x) << endl;
        else if (s == "D") {
            if (st.find(x) != st.end())
                st.erase(x);
            // print(st);
        }
    }
}
int32_t main() {
    // YUSUF REZA HASNAT;
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}