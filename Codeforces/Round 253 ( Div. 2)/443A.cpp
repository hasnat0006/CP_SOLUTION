#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    char str[2000];
    gets(str);
    int count=0,c=0;
    int freq[30]={0};
    for (int i = 0; str[i] ; i++)
    {
        if(str[i]>='a' && str[i]<='z')
            freq[str[i]-96]++;
    }
    for (int i = 0; i < 30; i++)
    {
        if(freq[i]!=0)
            count++;
    }
    cout<<count<<endl;
    
    return 0;
}