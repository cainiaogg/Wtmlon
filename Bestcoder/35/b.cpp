#include <stdlib.h>
#include <time.h>
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
LL n;

struct Matrix
{
	LL m[55][55];
};

Matrix Mul(Matrix a, Matrix b)
{
	Matrix ans;
	for (LL i = 1; i <= n; i++)
	for (LL j = 1; j <= n; j++) ans.m[i][j] = -1;
	for (LL i = 1; i <= n; i++){
		for (LL j = 1; j <= n; j++){
			for (LL k = 1; k <= n; k++){
				if (a.m[i][k] <0|| b.m[k][j]<0) continue;
				if (ans.m[i][j] == -1) ans.m[i][j] = a.m[i][k] + b.m[k][j];
				else ans.m[i][j] = min(ans.m[i][j], a.m[i][k] + b.m[k][j]);
			}
		}
	}
	return ans;
}

Matrix quick(Matrix a, LL b)
{
	Matrix ans;
	for (LL i = 1; i <= n; i++)
	for (LL j = 1; j <= n; j++) if (i == j) ans.m[i][j] = 0;
	else ans.m[i][j] = -1;
	while (b){
		if (b & 1){
			ans = Mul(ans, a);
		}
		a = Mul(a, a);
		b >>= 1;
	}
	return ans;
}

int main()
{
	LL T, h, k;
	LL m[55][55];
	LL a, b, w;
	cin >> T;
	while (T--){
		cin >> n >> h >> k;
		memset(m, -1, sizeof(m));
		for (LL i = 0; i<h; i++){
			cin >> a >> b >> w;
			if (m[a][b] == -1) m[a][b] = m[b][a] = w;
			else m[a][b] = m[b][a] = min(m[a][b], w);
		}
		Matrix c;
		for (LL i = 1; i <= n; i++)
		for (LL j = 1; j <= n; j++) c.m[i][j] = m[i][j];
		Matrix t = quick(c, k);
		cout << t.m[1][n] << endl;
		//system("pause");
	}
	return 0;
}
