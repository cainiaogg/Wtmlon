
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
//typedef __int64 LL;
typedef long long LL;
int up;
LL s;
LL k,len1,len2;
LL chart[100];
map<int,LL> m[30];
LL val;
int a[100];
LL jie(int x)
{
	LL ans = 1;
	for(int i = 1;i<=x;i++) ans*=i;
		return ans;
}

int gao(LL x)
{
	for(int i = 1;i<=100;i++){
		if(jie(i)>x){
			return i-1;
		}
	}
}

void init()
{
	for(int i = 1;i<=up;i++){
		chart[i] = jie(i);
	}
}

void dfs(int x,int ans,LL sum)
{
	if(x==len1+1){
		//printf("%d %d\n",k-ans,sum);
		m[k-ans][sum]++; return ;
	}
	dfs(x+1,ans,sum);
	if(sum+a[x]<=s) dfs(x+1,ans,sum+a[x]);
	if(a[x]<=up&&chart[a[x]]+sum<=s&&ans){
		dfs(x+1,ans-1,sum+chart[a[x]]);
	} 
}

void DFS(int x,int ans,LL sum)
{
	if(x==len2+1){
		//printf("%d %d\n",k-ans,sum);
		for(int i = 0;i<=ans;i++) if(m[i].count(s-sum)) val+=m[i][s-sum];
		return ;
	}
	DFS(x+1,ans,sum);
	if(sum+a[x+len1]<=s) DFS(x+1,ans,sum+a[x+len1]);
	if(a[x+len1]<=up&&chart[a[x+len1]]+sum<=s&&ans){
		DFS(x+1,ans-1,sum+chart[a[x+len1]]);
	}
}


int main()
{
	int n;
	val = 0;
	cin>>n>>k>>s;
	for(int i = 1;i<=n;i++) scanf("%d",&a[i]);
	up = gao(s);init();
	len1 = n/2; len2 = n - len1 ;
	dfs(1,k,0); DFS(1,k,0);
	cout<<val<<endl;
	return 0;
}