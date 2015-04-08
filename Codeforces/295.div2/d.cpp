#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<queue>

using namespace std;
int gao(int a,int b)
{
    int b1[100] = {0};
    int a1[100] = {0};
    int c1[100] = {0};
    int k = 25;
    int len = 0 ;
    while(b){
        b1[len++] = b%10;
        b/=10;

    }
    len = 0;
    while(a){
        a1[len++] = a%10;
        a/=10;
    }
    for(int i = 0 ;i<k;i++){
        if(b1[i] == 0) c1[i] = a1[i];
        else c1[i] = a1[i]^1;
    }
    while(!c1[k]) k--;
    int ans = 0;
    for(int i = k;i>=0;i--)
        ans = ans*2 + c1[i];
    return ans;
}

int main()
{
    int a,b;
    while(cin>>a>>b){
        cout<<gao(a,b)<<endl;
    }
    return 0;
}
