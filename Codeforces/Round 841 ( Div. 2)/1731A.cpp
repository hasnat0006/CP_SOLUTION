#include <bits/stdc++.h>
using namespace std;
//Munjib bhai is the best <3..
/*normally modular arithmetic, jog, biyog ar gunn er khetre kaj kore,
kintu vagg er khetre kaj kore nah (vag er khetre hisab nikash ektu
jotil...ami thik pari na eita)...eikhane,mod er moddhe 6 diye vag
korar karonei muloto somossha hoise...
jemon dhor,
n=7 ar mod=6
tahole, amader jeita kora lagbe...
sum1= ((n*(n+1)*(2n+1))/6)%mod
sum1= ((7*8*15)/6)%6
sum1=2
tui jeita korsish...
sum1=(((((n*(n+1))%mod)*((2n+1)%mod))%mod)/6)%mod
sum1=(((((7*8)%6)*(15%6))%10)/6)%6
sum1=1
miltese nah..
jeta kora lagbe,  mod use korar agei, 6 takee vagg kore dite parish... ba, sob mod er kaj seshe 6 ke
vag korte parish...taholei hobe*/

void find()
{

    unsigned long long n, a, b, c, sum = 0;
    unsigned long long int mod = 1000000007;
    cin >> n;
    a = n;
    b = n + 1;
    c = (2 * n) + 1;
    if (a % 2 == 0)
        a = a / 2;
    else if (b % 2 == 0)
        b = b / 2;

    if (a % 3 == 0)
        a /= 3;
    else if (b % 3 == 0)
        b /= 3;
    else
        c /= 3;
    //sum1=(((((n*(n+1))%mod)*((2n+1)%mod))%mod)/6)%mod
    unsigned long long sum1 = (a * b) % mod;
    sum1 = (sum1 * c) % mod;

    a = n - 1;
    b = n - 1 + 1;
    c = n - 1 + 2;
    if (a % 3 == 0)
        a /= 3;
    else if (b % 3 == 0)
        b /= 3;
    else
        c /= 3;
    unsigned long long sum2 = (a * b) % mod;
    sum2 = (sum2 * c) % mod;

    unsigned long long x = (sum1 + sum2);
    // cout<<sum1<<endl<<sum2<<endl<<x<<endl<<endl<<endl;
    unsigned long long ans = (x * 2022) % mod;
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    unsigned long long t;
    cin >> t;
    while (t--)
        find();
    return 0;
}