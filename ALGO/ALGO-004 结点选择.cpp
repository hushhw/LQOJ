/*
问题描述
有一棵 n 个节点的树，树上每个节点都有一个正整数权值。如果一个点被选择了，那么在树上和它相邻的点都不能被选择。求选出的点的权值和最大是多少？

输入格式
第一行包含一个整数 n 。

接下来的一行包含 n 个正整数，第 i 个正整数代表点 i 的权值。

接下来一共 n-1 行，每行描述树上的一条边。

输出格式
输出一个整数，代表选出的点的权值和的最大值。
样例输入
5
1 2 3 4 5
1 2
1 3
2 4
2 5
样例输出
12
样例说明
选择3、4、5号点，权值和为 3+4+5 = 12 。
数据规模与约定
对于20%的数据， n <= 20。

对于50%的数据， n <= 1000。

对于100%的数据， n <= 100000。

权值均为不超过1000的正整数。
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int dp[100010][2];
//dp[i][0]表示不取i结点的结果～dp[i][1]表示取i结点的结果～
vector< vector<int> > v;
//v[i]数组中保存i结点的孩子节点们

void dfs(int node, int pre){
//pre保存当前结点的前一个结点～如果等于pre说明访问到了它的父亲结点
	//cout<<"node:"<<node<<" size:"<<v[node].size()<<" pre:"<<pre<<endl;
	for(int i=0; i<v[node].size(); i++){
		int temp = v[node][i];
		if(temp != pre){
			dfs(temp, node);
			dp[node][0] += max(dp[temp][0], dp[temp][1]);
			dp[node][1] += dp[temp][0];
		}
	}
}

int main(){
	int n,a,b;
	scanf("%d",&n);
	for(int i=1; i<=n; i++) scanf("%d", &dp[i][1]);
	v.resize(n+1);
	for(int i=1; i<=n-1; i++){
		scanf("%d%d", &a, &b);
		//建立邻接表
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1, 0); //从低1到上累加到顶部
	cout<<max(dp[1][0], dp[1][1])<<endl;
	system("pause");
	return 0;
}