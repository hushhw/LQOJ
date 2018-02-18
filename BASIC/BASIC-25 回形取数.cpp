/*
问题描述
　　回形取数就是沿矩阵的边取数，若当前方向上无数可取或已经取过，则左转90度。一开始位于矩阵左上角，方向向下。
输入格式
  　　输入第一行是两个不超过200的正整数m, n，表示矩阵的行和列。接下来m行每行n个整数，表示这个矩阵。
输出格式
	　　输出只有一行，共mn个数，为输入矩阵回形取数得到的结果。数之间用一个空格分隔，行末不要有多余的空格。
样例输入
	  3 3
	  1 2 3
	  4 5 6
	  7 8 9
样例输出
	  1 4 7 8 9 6 3 2 5
样例输入
	  3 2
	  1 2
	  3 4
	  5 6
样例输出
	  1 3 5 6 4 2
*/

#include <iostream>
#include <string>
using namespace std;

int main(){
	int m,n;
	cin>>m>>n;
	int a[201][201];
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			cin>>a[i][j];
		}
	}
	int k=0, total=0;
	while(total<m*n){
		for(int i=k; i<m-k&&total<=m*n; i++){
			if(i==0 && k==0)
				cout<<a[i][k];
			else
				cout<<" "<<a[i][k];
			total++;
		}
		for(int i=k+1; i<n-k&&total<=m*n; i++){
			cout<<" "<<a[m-k-1][i];
			total++;
		}
		for(int i=m-k-2; i>=k&&total<=m*n; i--){
			cout<<" "<<a[i][n-k-1];
			total++;
		}
		for(int i=n-k-2; i>=k+1&&total<=m*n; i--){
			cout<<" "<<a[k][i];
			total++;
		}
		k++;
	}
	cout<<endl;
	system("pause");
	return 0;
}