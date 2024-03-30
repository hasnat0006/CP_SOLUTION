//!................  CG o nai CP o nai :)  ................!//

#include <bits/stdc++.h>
#define int long long
#define float long double
#define pb push_back
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;

using namespace std;
// calculate the sum of digits of a number
int sumdigit(int number) {
    int sum = 0;
    while (number > 0) {
        int digit = number % 10;
        sum += digit;
        number /= 10;
    }
    return sum;
}

void solve() {
    int n, q;
    cin >> n >> q;
    set<int> st;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        st.insert(i);
    }
    while (q--) {
        int temp;
        cin >> temp;
        if (temp == 1) {
            int l, r;
            cin >> l >> r;
            if (st.empty())
                continue;
            auto it = st.lower_bound(l - 1);
            vector<int> bad;
            while (it != st.end() && *it < r) {
                v[*it] = sumdigit(v[*it]);
                if (v[*it] <= 9)
                    bad.pb(*it);
                it++;
            }
            if (!bad.empty())
                for (auto i : bad)
                    st.erase(st.find(i));
        }
        else {
            int ans;
            cin >> ans;
            cout << v[ans - 1] << endl;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}