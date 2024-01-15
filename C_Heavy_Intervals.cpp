#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> v;
        set<char> alpha;
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            v.push_back({x, y});
        }
        for (int i = 0; i < v.size(); i++) {
            if (v[i].first == 0 and v[i].second == 0)
                continue;
            if (v[i].first < 0)
                alpha.insert('L');
            if (v[i].first > 0)
                alpha.insert('R');
            if (v[i].second < 0)
                alpha.insert('D');
            if (v[i].second > 0)
                alpha.insert('U');
            else if (i != 0 and v[i].first == 0 and v[i - 1].first < 0)
                alpha.insert('R');
            else if (i != 0 and v[i].first == 0 and v[i - 1].first > 0)
                alpha.insert('L');
            else if (i != 0 and v[i].second == 0 and v[i - 1].second < 0)
                alpha.insert('U');
            else if (i != 0 and v[i].second == 0 and v[i - 1].second > 0)
                alpha.insert('D');
        }
        if (alpha.size() <= 3)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}