/*
问题描述
　　设有N*N的方格图(N<=10),我们将其中的某些方格中填入正整数,而其他的方格中则放入数字0。
  　　某人从图的左上角的A 点(1,1)出发，可以向下行走，也可以向右走，直到到达右下角的B点(N,N)。
	在走过的路上，他可以取走方格中的数（取走后的方格中将变为数字0）。
	　　此人从A点到B 点共走两次，试找出2条这样的路径，使得取得的数之和为最大。
输入格式
	 输入的第一行为一个整数N（表示N*N的方格图），接下来的每行有三个整数，前两个表示位置，第三个数为该位置上所放的数。一行单独的0表示输入结束。
输出格式
	 只需输出一个整数，表示2条路径上取得的最大的和。
样例输入
	8
	2 3 13
	2 6 6
	3 5 7
	4 4 14
	5 2 21
	5 6 4
	6 3 15
	7 2 14
	0 0 0
样例输出
	67
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

int n;
int map[15][15];
int dp[15][15][15][15];

int main(){
	cin>>n;
	if(n==0)
		return 0;

	int x,y,val;
	memset(map, 0, sizeof(map));
	while(1){
		cin>>x>>y>>val;
		if(x==0 && y==0 && val==0)
			break;
		map[x][y]=val;
	}

	memset(dp,0,sizeof(dp));
	for(int i1=1; i1<=n; i1++){
		for(int j1=1; j1<=n; j1++){
			for(int i2=1; i2<=n; i2++){
				for(int j2=1; j2<=n; j2++){
					dp[i1][j1][i2][j2] = max(max(dp[i1-1][j1][i2-1][j2], dp[i1-1][j1][i2][j2-1]), max(dp[i1][j1-1][i2-1][j2], dp[i1][j1-1][i2][j2-1]));
					dp[i1][j1][i2][j2] += map[i1][j1];
					if(i1!=i2 || j1!=j2)
						dp[i1][j1][i2][j2] += map[i2][j2];
				}
			}
		}
	}
	cout<<dp[n][n][n][n]<<endl;  
	system("pause");
	return 0;
}