/*
ALGO-21	VIP���� װ������

�������� ����һ����������ΪV����������0����V����20000����ͬʱ��n����Ʒ��0��n����30����ÿ����Ʒ��һ�����������������
����Ҫ��n����Ʒ�У���ȡ���ɸ�װ�����ڣ�ʹ���ӵ�ʣ��ռ�Ϊ��С��

�����ʽ ����һ��Ϊһ����������ʾ����������
  �����ڶ���Ϊһ����������ʾ��n����Ʒ��

	��������n�У�ÿ��һ��������ʾ��n����Ʒ�ĸ�������� 
�����ʽ ����
	  һ����������ʾ����ʣ��ռ䡣 

�������� 24
	 6
	 8
	 3
	 12
	 7
	 9
	 7 

������� 
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