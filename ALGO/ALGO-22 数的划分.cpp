/*
ALGO-22	VIP试题 数的划分

问题描述
　　将整数n分成k份，且每份不能为空，任意两份不能相同(不考虑顺序)。
  　　例如：n=7，k=3，下面三种分法被认为是相同的。
	　　1，1，5; 1，5，1; 5，1，1;
	  　　问有多少种不同的分法。
输入格式
	n，k
输出格式
	一个整数，即不同的分法
样例输入
	7 3
样例输出
	4 {四种分法为：1，1，5;1，2，4;1，3，3;2，2，3;}
数据规模和约定
	　6<n<=200，2<=k<=6
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

int dp[205][10];  
int main()  
{  
	int n, k;  
	cin >> n >> k;  
	dp[1][1] = 1;  
	for (int i = 2; i <= n; i++)  
	{  
		for (int j = 1; j <= k; j++)  
		{  
			if (i >= j)  
			{  
				dp[i][j] = dp[i - j][j] + dp[i - 1][j - 1];  
			}  
		}  
	}  

	cout << dp[n][k] <<endl;  
	return 0;  
}  