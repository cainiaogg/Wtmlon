#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<queue>

using namespace std;

void gao(vector<int> q)
{
    q[0] = 100;
}

int main()
{
    vector<int> q;
    q.push_back(1);
    gao(q);
    printf("%d\n",q[0]);
    return 0;
}
