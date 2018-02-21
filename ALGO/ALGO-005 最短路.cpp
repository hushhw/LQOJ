/*
��������
����һ��n�����㣬m���ߵ�����ͼ������ĳЩ��Ȩ����Ϊ��������֤û�и���������������1�ŵ㵽����������·�������1��n��ţ���

�����ʽ
��һ����������n, m��

��������m�У�ÿ������������u, v, l����ʾu��v��һ������Ϊl�ıߡ�

�����ʽ
��n-1�У���i�б�ʾ1�ŵ㵽i+1�ŵ�����·��
��������
3 3
1 2 -1
2 3 -1
3 1 2
�������
-1
-2
���ݹ�ģ��Լ��
����10%�����ݣ�n = 2��m = 2��

����30%�����ݣ�n <= 5��m <= 10��

����100%�����ݣ�1 <= n <= 20000��1 <= m <= 200000��-10000 <= l <= 10000����֤�����ⶥ�㶼�ܵ����������ж��㡣
*/

/*
floyd(���д��󡣡�����
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
int dis[MAXN];		//dis������¼��ʼ�㵽�����λ��
bool vis[MAXN];		//����Ƿ񱻷���
int n,m;			//n��ʾ���������m��ʾ�ߵ�����

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
	memset(vis, 0, sizeof(vis));	//��ʼ���ж�����
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