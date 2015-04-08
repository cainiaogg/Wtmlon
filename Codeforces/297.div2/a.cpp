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
const int maxn = 1e5 + 10;
char str[maxn*2];
int cnt[maxn*2];
int main()
{
	int n;
	int ans = 0;
	memset(cnt, 0, sizeof(cnt));
	cin >> n;
	cin >> str + 1;
	for (int i = 1; i <= 2*n - 2; i++){
		if (i & 1){
			int t = str[i] - 'a';
			cnt[t]++;
		}
		else{
			int t = str[i] - 'A';
			if (cnt[t] == 0){
				ans++; continue;
			}
			cnt[t]--;
		}
	}
	cout << ans << endl;
	return 0;
}