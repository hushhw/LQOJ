/*
问题描述
给定一个n个顶点，m条边的有向图（其中某些边权可能为负，但保证没有负环）。请你计算从1号点到其他点的最短路（顶点从1到n编号）。

输入格式
第一行两个整数n, m。

接下来的m行，每行有三个整数u, v, l，表示u到v有一条长度为l的边。

输出格式
共n-1行，第i行表示1号点到i+1号点的最短路。
样例输入
3 3
1 2 -1
2 3 -1
3 1 2
样例输出
-1
-2
数据规模与约定
对于10%的数据，n = 2，m = 2。

对于30%的数据，n <= 5，m <= 10。

对于100%的数据，1 <= n <= 20000，1 <= m <= 200000，-10000 <= l <= 10000，保证从任意顶点都能到达其他所有顶点。
*/

/*
floyd(运行错误。。。）
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>

const int MAXN=20010;
const int inf=0x3f3f3f3f;
using namespace std;

int d[MAXN][MAXN];
int n,m;

void floyd(){
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
}

int main()
{
	scanf("%d%d",&n,&m);

	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			d[i][j]=inf;

	for(int i=1; i<=m; i++){
		int from, to, val;
		scanf("%d%d%d",&from,&to,&val);
		d[from][to]=val; 
	}

	floyd();

	for(int i=2;i<=n;i++){
		printf("%d\n",d[1][i]);
	}
	system("pause");
	return 0;
}
*/

/*
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <queue>
const int MAXN=200000;
const int inf=1 << 30;
using namespace std;

int head[MAXN];	
int dis[MAXN];		//dis用来记录初始点到个点的位置
bool vis[MAXN];		//标记是否被访问
int n,m;			//n表示顶点个数，m表示边的条数

struct edge{
	int to, val, from, next;
}e[MAXN << 2];

void add(int from, int to, int val, int k){
	e[k].from=from;
	e[k].to=to;
	e[k].val=val;
	e[k].next=head[from];
	head[from]=k;
}


void SPFA(int s){
	memset(vis, 0, sizeof(vis));	//初始化判断数组
	for(int i=0; i<=n; i++)
		dis[i] = inf;

	queue<int> q;
	q.push(s);
	vis[s]=1;
	dis[s]=0;

	while(!q.empty()){
		int cur=q.front();
		q.pop();
		vis[cur]=false;
		for(int i=head[cur]; i!=-1; i=e[i].next){
			int id=e[i].to;
			if(dis[id] > dis[cur]+e[i].val){
				dis[id] = dis[cur]+e[i].val;
				if(!vis[id]){
					q.push(id);
					vis[id]=1;
				}
			}
		}
	}
}

int main(){
	scanf("%d%d",&n,&m);
	memset(head, -1, sizeof(head));

	for(int i=0; i<m; i++){
		int from, to, val;
		scanf("%d%d%d",&from,&to,&val);
		add(from, to, val, i);
	}

	SPFA(1);

	for(int i = 2; i<=n; i++)  
		printf("%d\n",dis[i]); 
	system("pause");
	return 0;
}
*/