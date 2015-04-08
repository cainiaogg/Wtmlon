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
#define INF 1000000000
int n = 500, m = 500;
int vis[555][555];
int dist[555][555];

int dx[] = {1,2,1,2,-1,-2,-1,-2};
int dy[] = {2,1,-2,-1,2,1,-2,-1};

struct Node
{
	int x; int y; 
};
int gao(int x, int y)
{
	queue<Node> q;
	memset(vis, 0, sizeof(vis));
	Node t; t.x = x; t.y = y;
	vis[x][y] = 1;
	dist[x][y] = 0;
	q.push(t);
	while (!q.empty()){
		Node cur = q.front(); q.pop();
		int x1 = cur.x; int y1 = cur.y;
		if (x1 == 50 && y1 == 50) return dist[x1][y1];
		for (int i = 0; i < 8; i++){
			int xx = x1 + dx[i]; int yy = y1 + dy[i];
			if (xx >= 0 && xx < n&&yy >= 0 && yy < m&&!vis[xx][yy]){
				Node k; k.x = xx; k.y = yy;
				vis[xx][yy] = 1;
				dist[xx][yy] = dist[x1][y1] + 1;
				q.push(k);
			}
		}
	}
}

int main()
{
	int sx, sy, ex, ey;
	while (cin >> sx >> sy >> ex >> ey){
		int x = abs(sx - ex); int y = abs(sy - ey);
		int ans = 0;
	while (x+y>=50)
	{
		if (x<y) swap(x,y);
		if (x-4>=y*2) x-=4;
		else x-=4,y-=2;
		ans+=2;
	}
	x+=50,y+=50;
		int t = gao(x, y) + ans;
		cout << t << endl;
	}
	return 0;
}