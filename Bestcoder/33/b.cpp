#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

long long mult_mod(long long a,long long b,long long c)
{
    a %= c;
    b %= c;
    long long ret = 0;
    long long tmp = a;
    while(b)
    {
        if(b & 1)
        {
            ret += tmp;
            if(ret > c)ret -= c;//直接取模慢很多
        }
        tmp <<= 1;
        if(tmp > c)tmp -= c;
        b >>= 1;
    }
    return ret;
}
long long pow_mod(long long a,long long n,long long mod)
{
     long long ret = 1;
     long long temp = a%mod;
     while(n)
     {
         if(n & 1)ret = mult_mod(ret,temp,mod);
         temp = mult_mod(temp,temp,mod);
         n >>= 1;
     }
     return ret;
}

int main()
{
    long long n,p;
    while(scanf("%I64d%I64d",&n,&p) == 2){
        //if(n == 1)printf("%I64d\n",1%p);
        //else {
            long long ans = pow_mod(2,n-1,p)-2;
            ans = (ans%p+p)%p;
            ans = 2*ans%p;
            ans = (ans+2)%p;
            printf("%I64d\n",ans);
        //}
    }
    return 0;
}
