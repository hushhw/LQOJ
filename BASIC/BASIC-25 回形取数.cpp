/*
��������
��������ȡ�������ؾ���ı�ȡ��������ǰ������������ȡ���Ѿ�ȡ��������ת90�ȡ�һ��ʼλ�ھ������Ͻǣ��������¡�
�����ʽ
  ���������һ��������������200��������m, n����ʾ������к��С�������m��ÿ��n����������ʾ�������
�����ʽ
	�������ֻ��һ�У���mn������Ϊ����������ȡ���õ��Ľ������֮����һ���ո�ָ�����ĩ��Ҫ�ж���Ŀո�
��������
	  3 3
	  1 2 3
	  4 5 6
	  7 8 9
�������
	  1 4 7 8 9 6 3 2 5
��������
	  3 2
	  1 2
	  3 4
	  5 6
�������
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