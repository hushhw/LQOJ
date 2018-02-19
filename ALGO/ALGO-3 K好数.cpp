/*
问题描述
如果一个自然数N的K进制表示中任意的相邻的两位都不是相邻的数字，那么我们就说这个数是K好数。
求L位K进制数中K好数的数目。例如K = 4，L = 2的时候，所有K好数为11、13、20、22、30、31、33 共7个。由于这个数目很大，请你输出它对1000000007取模后的值。

输入格式
输入包含两个正整数，K和L。

输出格式
输出一个整数，表示答案对1000000007取模后的值。
样例输入
4 2
样例输出
7
数据规模与约定
对于30%的数据，KL <= 106；

对于50%的数据，K <= 16， L <= 10；

对于100%的数据，1 <= K,L <= 100。
*/

#include <iostream>
#include <string>
using namespace std;
#define MOD 1000000007

int dp[105][105];//dp[i][j]，i表示的是从右向左数第i位，j代表的是该位的可能取值
int main() {
	int k,l;
	cin>>k>>l;

	for(int i=0;i<k;i++) {
		dp[1][i]=1;     //当位数为1时，取值为1
	}

	for(int i=2;i<=l;i++){					//从第2位开始遍历
		for(int j=0;j<k;j++){				//进制从0——k-1取值
			for(int m=0;m<k;m++) {
				if(j!=m+1&&j!=m-1) {		//如果j和m不相邻，就符合要求
					dp[i][j]+=dp[i-1][m];	//第i位
					cout<<"dp["<<i<<"]["<<j<<"]:"<<dp[i][j]<<"  dp["<<i-1<<"]["<<m<<"]:"<<dp[i-1][m]<<endl;
					dp[i][j]%=MOD;
				}       
			}
		}
	}
	int sum=0;
	for(int i=1;i<k;i++) {		//首位不能取0，所以从1开始
		sum+=dp[l][i];
		sum%=MOD;
	}
	cout<<sum<<endl;
	system("pause");
	return 0;
} 