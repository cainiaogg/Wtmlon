#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <stack>
#include <string>
#include <iostream>
#include <cmath>
#include <climits>

using namespace std;
typedef long long LL;
const int maxn  = 1e6+10;

int erfen(int l,int r,LL a[],LL key)
{
    while(l<=r){
        int mid=(l+r)>>1;
        if(a[mid]==key) return mid;
        if(a[mid]>key) r = mid-1;
        if(a[mid]<key) l = mid+1;
    }
    return -1;
}

int a[maxn];
LL sum[maxn];
LL ans[maxn];
int main()
{
    int T,n,k;
    cin>>T;
    int Icase = 0 ;
    while(T--){
        int len = 0;
        printf("Case #%d: ",++Icase);
        scanf("%d%d",&n,&k);
        int flag = 0;
        for(int i = 0;i<n;i++){
            scanf("%d",&a[i]);
            if(i==0) sum[i] = a[i];
            else {
                if(i&1) sum[i] = sum[i-1] -a[i];
                else sum[i] = sum[i-1] + a[i];
            }
            if(a[i]==k||sum[i]==k){
                flag = 1;break;
            }
        }
        if(flag){
            printf("Yes.\n");continue;
        }
        for(int i=0;i<n;i++){
            int t =erfen(0,len-1,ans,sum[i]-k);
            if(t!=-1){flag = 1;break;}
            if(i&1) ans[len++] = sum[i];
        }
        if(flag){printf("Yes.\n");continue;};
        len = 0;
        for(int i = 0;i<n;i++) sum[i] = -sum[i];
        for(int i = 0;i<n;i++){
            int t=erfen(0,len-1,ans,sum[i]-k);
            if(t!=-1){flag = 1;break;};
            if(i&1==0) ans[len++]  = sum[i];
        }
        if(flag) printf("Yes\n");
        else printf("No\n");

    }
    return 0;
}
