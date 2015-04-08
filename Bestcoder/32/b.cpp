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
typedef long long LL;
using namespace std;

int a[500000 + 10];
int main()
{
	int n, m;
	while (cin >> n >> m){
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		sort(a, a + n);
		printf("%d",a[n-1]);
		for (int i = n - 2; i >= n - m ; i--)
			printf(" %d", a[i]);
		cout << endl;
	}
	return 0;
}
