#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<queue>

using namespace std;

typedef long long LL;
const int mod = 1e9+ 7;

const int maxn = 1e5+100;
int main()
{
    int n;
    char str[maxn];
    int cnt[100];
    memset(cnt,0,sizeof(cnt));
    cin>>n;
    cin>>str;
    for(int i = 0 ;i<n;i++){
        if(str[i]=='A') cnt[1]++;
        if(str[i] =='C') cnt[2]++;
        if(str[i]=='G') cnt[3]++;
        if(str[i]=='T') cnt[4]++;
    }
    int Max  = -1;
    for(int i = 1;i<5;i++)
        Max = max(Max,cnt[i]);
    int ans = 0;
    for(int i = 1;i<5;i++)
        if(Max==cnt[i]) ans++;
    LL gg =  1;
    for(int i = 0;i<n;i++){
        gg  = gg*ans%
        mod;
    }
    cout<<gg<<endl;
    return 0;
}
