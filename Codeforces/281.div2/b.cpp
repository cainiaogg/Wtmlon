#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<queue>

using namespace std;
typedef long long LL;
int cmp(vector<int> &a, vector<int> &b)
{
    int Min = min(a.size(),b.size());
    int flag = 0;
    for(int i = 0;i<Min;i++){
        if(a[i]>b[i]) return 1;
        if(b[i]>a[i]) return 0;
    }
    if(a.size()>b.size()) return 1;
    if(a.size()==b.size()) return 2;
    return 0;

}
int a[222222];

int main()
{
    int n;
    vector<int> q,q1;
    LL sum = 0;
    LL sum1 = 0;
    int t;
    cin>>n;
    for(int i = 0;i<n;i++){
        scanf("%d",&t);
        a[i] = t;
        if(t>0) q.push_back(t),sum+=t;
        else q1.push_back(-t),sum1+=-t;
    }
    if(sum>sum1){
        printf("first\n");return 0;
    }
    if(sum1>sum){
        printf("second\n");return 0;
    }
    int gg = cmp(q,q1);
    if(gg==1) printf("first\n");
    if(gg==0) printf("second\n");
    if(gg==2){
        if(a[n-1]<0) printf("second\n");
        else printf("first\n");
    }
    return 0;
}
