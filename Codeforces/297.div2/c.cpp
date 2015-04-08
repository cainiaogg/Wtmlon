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
typedef long long LL;
LL cmp(const LL &a,const LL &b)
{
	return a>b;
}
const int maxn = 1e5+10;
int a[maxn];
int q[maxn];
int main()
{
	int n;
	cin>>n;
	for(LL i = 1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1,cmp);
	LL ans = 0 ;
	LL len = 0;
	LL l,r;
	for(LL i = 1;i<n;i++){
		q[len++] = a[i];
		if(a[i]==a[i+1]||a[i] == a[i+1] + 1){
			q[len++] = a[i+1];i++; continue;
		}
		len--;
	}
	for(LL i = 0;i<len-3;i+=4){
		if(q[i]==q[i+1]) l = q[i];
		else l = q[i+1];
		if(q[i+2]==q[i+3]) r = q[i+2];
		else r = q[i+3];
		ans+=l*r;
	}
	cout<<ans<<endl;
	return 0;
}