#include <bits/stdc++.h>
using namespace std;
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int w, d, h, a, b, f, g;
        cin >> w >> d >> h >> a >> b >> f >> g;
        int projection[4];
        projection[0] = h + abs(a - f) + b + g;
        projection[1] = abs(w - f) + h + (abs(w - a) + abs(b - g));
        projection[2] = a + h + f + abs(b - g);
        projection[3] = abs(d - b) + h + abs(d - g) + abs(f - a);
        sort(projection, projection + 4);
        int ans = projection[0];
        cout << ans << endl;
    }
    return 0;
}