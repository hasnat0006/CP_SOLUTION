//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 06|04|2024 11:15:59            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

#define mod 1000000007;
#define inf 1000000000000000000;
double pi = 3.14159265358979323846;

struct Point {
    int x, y;
};

double distance(Point& p1, Point& p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

vector<double> sides(4);
vector<double> angles(4);

bool isSquare() {
    int rightAngles = 0;
    for (int i = 0; i < 4; ++i) {
        if (abs(angles[i] - 90.0) < 1e-9) {
            rightAngles++;
        }
    }
    for (int i = 0; i < 4; ++i) {
        if (abs(sides[i] - sides[(i + 1) % 4]) > 1e-9) {
            return false;
        }
    }
    return rightAngles >= 1;
}

bool isRectangle() {
    int rightAngles = 0;
    for (int i = 0; i < 4; ++i) {
        if (abs(angles[i] - 90.0) < 1e-9) {
            rightAngles++;
        }
    }
    return rightAngles >= 3;
}


bool isRhombus() {
    int equalSides = 0;
    for (int i = 0; i < 4; i++) {
        if ((sides[i] - sides[(i + 1) % 4]) < 1e-9) {
            equalSides++;
        }
    }
    return equalSides == 4;
}

bool isParallelogram() {
    int parallelSides = 0;
    for (int i = 0; i < 4; ++i) {
        if (abs(angles[i] - angles[(i + 2) % 4]) < 1e-9) {
            parallelSides++;
        }
    }
    return parallelSides >= 2;
}

bool isTrapezium() {
    int parallelSides = 0;
    for (int i = 0; i < 4; ++i) {
        if (abs(angles[i] - angles[(i + 2) % 4]) < 1e-9) {
            parallelSides++;
        }
    }
    return parallelSides == 1;
}

bool isKite() {
    int diagonals = 0;
    for (double angle : angles) {
        if (abs(angle - 180.0) < 1e-9) {
            diagonals++;
        }
    }
    return diagonals >= 1;
}

/*
some test cases:
reactangle but not square:
0 0
0 1
1 1
1 0
rhombus:
0 0
0 1
1 2
1 1
parallelogram:
0 0
0 1
1 2
1 1
trapezium:
0 0
0 1
1 1
2 0
kite:
0 0
0 1
1 1
0 2
*/

void solve() {
    vector<Point> points(4);
    for (int i = 0; i < 4; ++i) {
        cin >> points[i].x >> points[i].y;
    }

    for (int i = 0; i < 4; ++i) {
        sides[i] = distance(points[i], points[(i + 1) % 4]);
    }

    for (int i = 0; i < 4; ++i) {
        int dx1 = points[(i + 1) % 4].x - points[i].x;
        int dy1 = points[(i + 1) % 4].y - points[i].y;
        int dx2 = points[(i + 2) % 4].x - points[(i + 1) % 4].x;
        int dy2 = points[(i + 2) % 4].y - points[(i + 1) % 4].y;
        angles[i] = atan2(dy1, dx1) - atan2(dy2, dx2);
        if (angles[i] < 0)
            angles[i] += 2 * pi;
        angles[i] = angles[i] * 180.0 / pi;
    }
    // for (auto i : sides)
    //     cout << i << " ";
    // cout << endl;
    // for (auto i : angles)
    //     cout << i << " ";
    // cout << endl;
    if (isSquare())
        cout << "square" << endl;
    else if (isRectangle())
        cout << "rectangle" << endl;
    else if (isRhombus())
        cout << "rhombus" << endl;
    else if (isParallelogram())
        cout << "parallelogram" << endl;
    else if (isTrapezium())
        cout << "trapezium" << endl;
    else if (isKite())
        cout << "kite" << endl;
    else
        cout << "none" << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}