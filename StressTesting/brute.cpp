#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, i, j;
    cin >> n >> m;
    vector<vector<char>> c(n, vector<char>(m));
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> ps(n, vector<int>(m));
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cin >> c[i][j];
        }
    }
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < m - 1; j++) {
            if (c[i + 1][j] == c[i][j + 1]) {
                a[i][j] = 1;
            }
        }
    }
    for (i = n - 2; i >= 0; i--) {
        for (j = m - 2; j >= 0; j--) {
            ps[i][j] =
                a[i][j] + (ps[i + 1][j] + ps[i][j + 1] - ps[i + 1][j + 1]);
        }
    }
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < m - 1; j++) {
            if ((a[i][j] == 1 && ps[i + 1][j + 1] > 0) ||
                (a[i][j] == a[i + 1][j] && a[i + 1][j] == 1 ||
                 (a[i][j] == a[i][j + 1] && a[i][j + 1] == 1))) {
                cout << "YES\n";
                return 0;
            }
        }
    }
    cout << "NO\n";
    return 0;
}