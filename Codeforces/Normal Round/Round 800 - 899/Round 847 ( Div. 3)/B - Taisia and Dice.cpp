#include <bits/stdc++.h>
#define int long long
#define float double
int mod = 1000000007;
float pi = 3.1415926535;
using namespace std;
int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) {
        int n, s, r;
        cin >> n >> s >> r;
        int dice[n];
        int difference = s - r;
        dice[0] = difference;
        if (n == 2) {
            cout << difference << " " << s - difference << endl;
        }
        else {
            int x = r / (n - 1);
            int jog_kori = dice[0];
            for (int i = 1; i < n; i++) {
                dice[i] = x;
                r = r - x;
                jog_kori += dice[i];
            }
            int baki = 0;
            while (jog_kori != s) {
                dice[n - 1 - baki]++;
                jog_kori++;
                baki++;
            }
            for (int i = 0; i < n; i++)
                cout << dice[i] << " ";
            cout << endl;
        }
    }
    return 0;
}