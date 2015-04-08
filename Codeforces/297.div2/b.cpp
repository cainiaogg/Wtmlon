#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
using namespace std; 
#define INF 1000000000

#define  lson l,mid,rt<<1
#define  rson mid+1,r,rt<<1|1
const int maxn = 2*100000 + 10;
char str[maxn];
int color[maxn<<2];
void build(int l,int r,int rt)
{
	color[rt] = 0;
	if(l==r) return ;
	int mid=(l+r)>>1;
	build(lson); build(rson);
}

void down(int rt)
{
	if(color[rt]){
		color[rt<<1]^=1; color[rt<<1|1]^=1;
		color[rt] = 0;
	}
}
void update(int L,int R,int l,int r,int rt)
{
	if(L<=l&&r<=R){
		color[rt]^=1; return ;
	}
	down(rt);
	int mid=(l+r)>>1;
	if(L<=mid) update(L,R,lson);
	if(R>mid) update(L,R,rson);
}
int ask(int key,int l,int r,int rt)
{
	if(l==r) return color[rt] ;
	down(rt);
	int mid=(l+r)>>1;
	if(key<=mid) return ask(key,lson);
	else return ask(key,rson);
}
int main()
{
	int m,a;
	scanf("%s",str+1);
	int len = strlen(str+1);
	cin>>m;
	build(1,len,1);
	for(int i = 0;i<m;i++){
		scanf("%d",&a);
		update(a,len - a+1,1,len,1);
	}
	for(int i = 1;i<=len/2;i++){
		int t = ask(i,1,len,1);
		if(t) swap(str[i],str[len-i+1]);
	}
	for(int i =  1;i<=len;i++)
		printf("%c",str[i]);
	cout<<endl;
	return 0;
}