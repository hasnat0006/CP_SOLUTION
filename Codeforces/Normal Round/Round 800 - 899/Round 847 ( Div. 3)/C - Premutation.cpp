#include <bits/stdc++.h>
#define int long long
#define float double
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
using namespace std;
int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) {
        {
            int n;
            cin >> n;
            int permutation[n][n - 1];
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n - 1; ++j) {
                    cin >> permutation[i][j];
                }
            }
            // for (int i = 0; i < n; ++i)
            // {
            //     for (int j = 0; j < n - 1; ++j)
            //     {
            //         cout<< permutation[i][j]<<" ";
            //     }
            //     cout<<endl;
            // }
            for (int i = 0; i < n - 1; ++i) {
                int index1 = -1, index2 = -1;
                for (int j = 0; j < n - 1; ++j) {
                    if (permutation[j][i] != permutation[j + 1][i]) {
                        index1 = permutation[j][i],
                        index2 = permutation[j + 1][i];
                    }
                }
                int x;
                if (i == 0) {
                    int c_index1 = 0, c_index2 = 0;
                    for (int j = 0; j < n; ++j) {
                        if (permutation[j][i] == index1)
                            c_index1++;
                        else
                            c_index2++;
                    }
                    if (c_index1 > c_index2) {
                        cout << index1 << " " << index2 << " ";
                        x = index2;
                    }
                    else {
                        cout << index2 << " " << index1 << " ";
                        x = index1;
                    }
                }
                if (i > 0) {
                    if (index1 == x) {
                        cout << index2 << " ";
                        x = index2;
                    }
                    else {
                        cout << index1 << " ";
                        x = index1;
                    }
                }
            }
            cout << endl;
        }
    }
    return 0;
}