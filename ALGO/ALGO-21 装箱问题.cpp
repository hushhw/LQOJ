/*
ALGO-21	VIP试题 装箱问题

问题描述 ：有一个箱子容量为V（正整数，0＜＝V＜＝20000），同时有n个物品（0＜n＜＝30），每个物品有一个体积（正整数）。
　　要求n个物品中，任取若干个装入箱内，使箱子的剩余空间为最小。

输入格式 ：第一行为一个整数，表示箱子容量；
  　　第二行为一个整数，表示有n个物品；

	　接下来n行，每行一个整数表示这n个物品的各自体积。 
输出格式 　　
	  一个整数，表示箱子剩余空间。 

样例输入 24
	 6
	 8
	 3
	 12
	 7
	 9
	 7 

样例输出 
	0
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

int V,n;  
int val[33],dp[20020];  

void solve()  
{  
	memset(dp,0,sizeof(dp));  
	for(int i=1;i<=n;i++)  
	{  
		for(int j=V;j>=val[i];j--)  
		{  
			dp[j]=max(dp[j],dp[j-val[i]]+val[i]);  
		}  
	}  
	printf("%d\n",V-dp[V]);  
}  

int main()  
{  
	int i;  
	while(scanf("%d%d",&V,&n)!=EOF)  
	{  
		for(i=1;i<=n;i++)  
		{  
			scanf("%d",&val[i]);  
		}  
		solve();  
	}  
	return 0;  
}  

/*
int dp[40];
int m,n, min1=99999999;

void dfs(int t){
	if(t==n){
		if(m<min1){
			min1=m;
		}
		return ;
	}
	m -= dp[t];
	dfs(t+1);
	m += dp[t];
}

int main(){
	cin>>m>>n;
	memset(dp, 0, sizeof(dp));
	for(int i=0; i<n; i++)
		cin>>dp[i];
	dfs(0);
	if(min1<0)
		min1=0;
	cout<<min1<<endl;

	system("pause");
	return 0;
}
*/