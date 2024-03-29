#include <iostream>
using namespace std;
void find()
{
    int a, b;
    cin >> a >> b;
    if (a == 0)
        cout << 1 << endl;
    else
    {
        int x = b * 2;
        int ans = a + x + 1;
        cout << ans << endl;
    }
}
int main(int argc, char **argv)
{
    int t;
    cin >> t;
    while (t--)
        find();

    return 0;
}
