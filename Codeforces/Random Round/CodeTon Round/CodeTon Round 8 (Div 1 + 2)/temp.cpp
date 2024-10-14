#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug.h"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

int mod = 1000000007;
int inf = 1e18;

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;

        vector<int> bessie_vertices(x);
        for (int i = 0; i < x; ++i) {
            cin >> bessie_vertices[i];
        }

        sort(bessie_vertices.begin(), bessie_vertices.end());

        int bessie_triangles = 0;
        // Calculate the number of triangles formed by the diagonals between
        // Bessie's chosen vertices
        for (int i = 1; i < x; ++i) {
            bessie_triangles +=
                max(0ll, bessie_vertices[i] - bessie_vertices[i - 1] - 2);
        }
        // Add the interval between the last and the first vertex
        bessie_triangles +=
            max(0ll, n - bessie_vertices.back() + bessie_vertices[0] - 1);

        int additional_triangles = max(0ll, y - x + 1);

        int total_triangles = bessie_triangles + additional_triangles;

        cout << total_triangles << endl;
    }

    return 0;
}
