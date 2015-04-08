#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<vector>
using namespace std;

typedef long long LL;
LL gao(LL n)
{
    LL a[100];
    LL  ans = 0;
    while(n){
        a[ans++] = n%2;
        n /= 2;
    }
    LL gg = 0;
    for(LL i = 0;i<ans;i++)
        gg = gg*2 + a[i];
    return gg;
}

int  main()
{
    LL T;LL n;
    while(cin>>T){
        while(T--){
            cin>>n;
            cout<<gao(n)<<endl;
        }
    }
    return 0;
}
