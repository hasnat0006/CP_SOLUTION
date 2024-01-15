#include <bits/stdc++.h>
#define int long long
#define float double
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
using namespace std;
void solve()
{
    int n;
    cin >> n;
    int card = n;
    int al_blk = 0, al_wh = 0, bob_blk = 0, bob_wh = 0;
    int ac = 0, bc = 0, i;
    bool fb = true, fa = true;
    for (i = 1; i <= n; i++)
    {
        if (al_blk + al_wh + bob_blk + bob_wh >= n)
            break;
        else if (i == 1)
        {
            al_blk++;
            card--;
        }
        else if (bc < 2)
        {
            if (card < i)
            {
                i = card;
                if (i % 2 == 0)
                {
                    bob_blk += i / 2;
                    bob_wh += i / 2;
                }
                else
                {
                    bob_blk += (i / 2) + 1;
                    bob_wh += i / 2;
                }
            }
            else if (i % 2 == 0)
            {
                bob_blk += i / 2;
                bob_wh += i / 2;
            }
            else
            {
                bob_blk += (i / 2) + 1;
                bob_wh += i / 2;
            }
            card -= i;
            bc++;
            if (bc == 2)
                ac = 0;
        }
        else if (ac < 2)
        {
            if (card < i)
            {
                i = card;
                if (i % 2 == 0)
                {
                    al_blk += i / 2;
                    al_wh += i / 2;
                }
                else
                {
                    al_wh += (i / 2) + 1;
                    al_blk += i / 2;
                }
            }
            else if (i % 2 == 0)
            {
                al_blk += i / 2;
                al_wh += i / 2;
            }
            else
            {
                al_wh += (i / 2) + 1;
                al_blk += i / 2;
            }
            card -= i;
            ac++;
            if (ac == 2)
                bc = 0;
        }
        // cout << " i " << i << endl;
        // cout << alice << " " << bob << endl;
        // cout << al_blk + al_wh << " " << bob_blk + bob_wh << endl;
    }
    // cout << al_blk + al_wh << " " << bob_blk + bob_wh << endl;
    cout << al_wh + 1 << " " << al_blk - 1 << " " << bob_wh << " " << bob_blk << endl;
    // cout << "*\n";
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}