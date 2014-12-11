#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>

using namespace std;

typedef long long LL;

int gg ;
int t,a,b;
int gao(int x,int y)
{
    int ans = 0;
    int a0 = y%x;
    int x1 = x - a0 ;int y1 = y - a0;
    int flag = 0;
    if(a0==0&&y%x==0) ans+=1;
    if(x1<0||y1<0||x1%t||y1%a) flag = 1;
    if(x1%t==0&&y1%a==0){
        int x2 = x1 / t;int y2 = y1 / a;
        if(x2==x&&y2==y){
            ans++;gg=1;flag=1;
        }
    }
    if(!flag) ans+=gao(x1/t,y1/a);
    return ans;
}

int main()
{
    cin>>t>>a>>b;
    gg = 0;
    int ans = gao(a,b);
    if(gg){
        printf("inf\n");
    }
    else printf("%d\n",ans);
    return 0;
}
