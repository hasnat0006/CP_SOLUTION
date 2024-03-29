#include <bits/stdc++.h>
using namespace std;
void find()
{
    long long n, k;
    cin >> n >> k;
    long long int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i]=i+1;
    }
    long long x=n;
    int c=0;
    int cnt=0;
    for (int i = 0; i < n; i++)
    {
        if(cnt==n)
            break;
        if (c%2==0)
        {
            cout<<arr[x-1]<<" ";
            c++;
            x--;
            cnt++;
            i--;
        }
        else 
        {
            cout<<arr[i]<<" ";
            c++;
            cnt++;
            //i++;
        }
        
    }
    
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        find();
    return 0;
}