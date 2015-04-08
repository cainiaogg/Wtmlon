/* ***********************************************
 	Author        : wtmlon
 	Mail		  : 879447570@qq.com
 	Created Time  : 2015-03-21 15:03:17
	Problem       : B. Error Correct System
************************************************ */
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

int m[30][30];
int main() {
#ifndef ONLINE_JUDGE
	freopen("C:\\Program Files\\Sublime Text 3\\in.txt", "r", stdin); 
#endif // ONLINE_JUDGE
	string a,b;
	int n;
	cin>>n;
	cin>>a>>b;
	int ans = 0;
	memset(m,0,sizeof(m));
	for(int i = 0;i<n;i++){
		int ta = a[i] - 'a';
		int tb = b[i] - 'a';
		m[ta][tb] = 1;
		if(ta!=tb) ans++;
	}
	int x = -1;int y = -1;
	for(int i = 0;i<26;i++){
		for(int j =0 ;j<26;j++){
			if(i==j) continue;
			if(m[i][j]&&m[j][i]){
				x = i;y = j;
			}
		}
	}
	if(x!=-1&&y!=-1){
		printf("%d\n",ans-2);
		int x1;int y1;
		for(int i = 0;i<n;i++){
			if(a[i]-'a' == x&&b[i]-'a'==y) x1 = i;
		}
		for(int i = 0;i<n;i++){
			if(a[i]-'a'==y&&b[i]-'a'==x) y1 = i;
		}
		printf("%d %d\n",x1+1,y1+1);
		return 0;
	}
	int x1 = - 1;int y1 = -1;
	for(int i=  0;i<26;i++){
		for(int j= 0 ;j<26;j++){
			if(i==j||!m[i][j]) continue;
			for(int k = 0;k<26;k++){
				if(k==j) continue;
				if(m[j][k]){
					x = i; y = j;
				}
			}
			for(int k = 0;k<26;k++){
				if(k==i) continue;
				if(m[k][i]) x1 = i;y1 = j;
			}
		}
	}
	int x3, y3;
	if(x != -1 && y != -1){
		for(int i = 0; i < n; i++){
			if(a[i]-'a'==x&&b[i]-'a'==y) x3 = i;
		}
		for(int i = 0;i<n;i++){
			if(a[i]-'a'==y&&b[i]-'a'!=y) y3 = i;
		}
		printf("%d\n",ans-1);
		printf("%d %d\n",x3+1,y3+1);
	}
	else if(x1!=-1&&y1!=-1){
		for(int i = 0;i<n;i++){
			if(a[i]-'a'==x1&&b[i]-'a'==y1) x3 = i;
		}
		for(int i = 0;i<n;i++){
			if(a[i]-'a'==y1&&b[i]-'a'!=y1) y3 = i;
		}
		printf("%d\n",ans-1);
		printf("%d %d\n",x3+1,y3+1);
	}
	else {
		printf("%d\n",ans);
		printf("%d %d\n",-1,-1);
	}
	return 0; 
}