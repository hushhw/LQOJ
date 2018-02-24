/*
问题描述
　　一个旅行家想驾驶汽车以最少的费用从一个城市到另一个城市（假设出发时油箱是空的）。
  给定两个城市之间的距离D1、
  汽车油箱的容量C（以升为单位）、每升汽油能行驶的距离D2、
  出发点每升汽油价格P和沿途油站数N（N可以为零），油站i离出发点的距离Di、每升汽油价格Pi（i=1，2，……N）。
  计算结果四舍五入至小数点后两位。如果无法到达目的地，则输出“No Solution”。
输入格式
  　　第一行为4个实数D1、C、D2、P与一个非负整数N；
	　　接下来N行，每行两个实数Di、Pi。
输出格式
	 如果可以到达目的地，输出一个实数（四舍五入至小数点后两位），表示最小费用；否则输出“No Solution”（不含引号）。
样例输入
		275.6 11.9 27.4 2.8 2
		102.0 2.9
		220.0 2.2
样例输出
		26.95
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

int main(){
	double D1, C, D2, P, N;
	cin>>D1>>C>>D2>>P>>N;//输入总长度、存油量、单位油量行驶距离、起始点油单价、加油点
	vector<double> d(N+2);
	vector<double> p(N+2);

	for(int i=1; i<=N; i++){
		cin>>d[i]>>p[i];
	}
	d[0] = 0; d[N+1] = D1;
	p[0] = P; p[N+1] = 0;

	for(int i = 1; i <= N+1; i++) {//判断能不能到达 
		if( C*D2 < d[i] - d[i-1] ) {
			printf("No Solution\n");
			return 0;
		}
	}

	int i=0;
	double count = 0; //总油价
	double yu = 0; //余量
	while(i<N+1){
		int j = i+1;
		if(p[j] > p[i]){
			while(p[j] > p[i] && d[j]-d[i] <= C*D2)
				j++;
			if(d[j]-d[i] > C*D2){
				count += (C-yu)*p[i];
				yu = C - (d[j-1]-d[j])/D2;
				i = j-1;
			} else {
				count += ((d[j]-d[i])/D2-yu)*p[i];
				yu = 0;
				i = j;
			}
		} else {
			count += ((d[j]-d[i])/D2-yu)*p[i];
			yu = 0;
			i = j;
		}
	}
	printf("%.2lf\n", count); 
	system("pause");
	return 0;
}