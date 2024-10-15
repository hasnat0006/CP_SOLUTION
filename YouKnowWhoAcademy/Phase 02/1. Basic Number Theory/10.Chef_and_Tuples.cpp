//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 15|10|2024 21:08:05            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

const int mod = 1e9 + 7;
const int inf = 1e18;

class Node {
   public:
    int a, b, c;
    Node() {}
    Node(int a, int b, int c) {
        vector<int> v = {a, b, c};
        sort(vf(v));
        this->a = v[0];
        this->b = v[1];
        this->c = v[2];
    }
    void setValue(int a, int b, int c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }
    void printValue() {
        cout << "[" << a << "," << b << "," << c << "]" << endl;
    }
};

bool operator<(const Node &first, const Node &sec) {
    if (first.a == sec.a and first.b == sec.b) {
        return (first.c < sec.c);
    }
    if (first.a == sec.a) {
        return (first.b < sec.b);
    }
    return (first.a < sec.a);
}

void findPair(int n, int y, int z, vector<pair<int, int>> &v) {
    vector<pair<int, int>> divisors;
    for (int div = 1; div * div <= n; div++) {
        if (n % div == 0) {
            divisors.push_back({div, n / div});
        }
    }
    for (auto &div : divisors) {
        if (min(div.first, div.second) <= y and
            max(div.first, div.second) <= z) {
            v.push_back(div);
        }
    }
}

void solve() {
    int n, v[3];
    cin >> n >> v[0] >> v[1] >> v[2];
    sort(v, v + 3);
    int x = v[0], y = v[1], z = v[2];
    vector<int> divisors;
    for (int div = 1; div * div <= n; div++) {
        if (n % div == 0) {
            divisors.push_back(div);
            if (n / div != div)
                divisors.push_back(div);
        }
    }
    map<Node, int> mp;
    for (int i = 0; i < divisors.size(); i++) {
        if (divisors[i] > x)
            break;
        int first = divisors[i];
        vector<pair<int, int>> temp;
        findPair(n / first, y, z, temp);
        for (auto i : temp) {
            mp[Node(first, i.first, i.second)]++;
        }
    }
    map<Node, int> ans;

    auto isSatisfy = [&](int a, int b, int c) {
        return (a <= x and b <= y and c <= z);
    };

    auto allPair = [&](Node temp) {
        int a = temp.a, b = temp.b, c = temp.c;
        Node A;
        if (isSatisfy(a, b, c)) {
            A.setValue(temp.a, temp.b, temp.c);
            ans[A]++;
        }
        if (isSatisfy(a, c, b)) {
            A.setValue(temp.a, temp.c, temp.b);
            ans[A]++;
        }
        if (isSatisfy(b, a, c)) {
            A.setValue(temp.b, temp.a, temp.c);
            ans[A]++;
        }
        if (isSatisfy(b, c, a)) {
            A.setValue(temp.b, temp.c, temp.a);
            ans[A]++;
        }
        if (isSatisfy(c, a, b)) {
            A.setValue(temp.c, temp.a, temp.b);
            ans[A]++;
        }
        if (isSatisfy(c, b, a)) {
            A.setValue(temp.c, temp.b, temp.a);
            ans[A]++;
        }
        return;
    };
    for (auto i : mp) {
        allPair(i.first);
    }
    cout << ans.size() << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}