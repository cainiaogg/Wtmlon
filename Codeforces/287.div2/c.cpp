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
LL h;

LL cifang(LL x,LL y)
{
    LL ans =1;
    for(LL i = 0;i<y;i++)
        ans*=x;
    return ans;
}
LL gao(LL x,LL y)
{
    LL t = (y+1)/2;
    if(x==1) return 1;
    if(x==2){
        if(y==1){
            return 2;
        }
        else return cifang(2,h-x+1) + 1;
    }
    if(t%2==y%2){
        LL k = cifang(2,h-x+1)+gao(x-1,t);
        return k;
    }
    else return 1+gao(x-1,t);
}

int main()
{
    LL n;
    cin>>h>>n;
    h++;
    LL ans = 100;
    for(LL i = 1;i<=h;i++){
        LL t = cifang(2,i-1);
        if(t>=n){
            ans = i;break;
        }

    }
    LL Min = (1LL<<60);
   // for(LL i = ans;i<=h;i++){
     //   Min = min(Min,gao(i,n));
        //cout<<i<<" "<<Min<<endl;
    //}
    cout<<gao(h,n)-1<<endl;
    return 0;
}
