#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<vector>
using namespace std;
int judge(int b[])
{
    int flag  = 0;
    for(int i = 0;i<4;i++){
        if(b[i]<3&&b[i]) flag = 1;
    }
    return !flag;
}
int main()
{
    int T;
    int a[10],b[10];
    cin>>T;
    while(T--){
        int sum = 0;
        for(int i = 0;i<4;i++){
            scanf("%d",&a[i]);
            if(a[i]==0) sum++;
        }
        if(sum==4){
            printf("Yes\n"); continue;
        }
        int ans = 0;
        for(int i = 0;i<3;i++){
            for(int j = 0;j<3;j++){
                for(int l = 0;l<3;l++){
                for(int k = 0;k<4;k++) b[k] = a[k];
                for(int k = 0;k<3;k++) b[k] -=i;
                for(int k = 1;k<4;k++) b[k] -=j;
                for(int k = 0 ; k< 4;k++) b[k]-=l;
                ans|=judge(b);
                }
            }
        }
        if(ans) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
