/* ***********************************************
 	Author        : wtmlon
 	Mail		  : 879447570@qq.com
 	Created Time  : 2015-03-21 14:16:14
	Problem       : A. Playing with Paper
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
typedef long long  LL; 


int main() {
#ifndef ONLINE_JUDGE
	freopen("C:\\Program Files\\Sublime Text 3\\in.txt", "r", stdin); 
#endif // ONLINE_JUDGE
	LL a,b;
	cin>>a>>b;
	LL ans = 0;
	while(a!=b&&a&&b){
		if(a<b) swap(a,b);
		ans+=a/b; LL t = b; b = a%b; a = t ;
	}
	cout<<ans<<endl;
	return 0; 
}