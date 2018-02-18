/*
���ű� BASIC-17 ������ϰ ����˷�
��������
��������һ��N�׾���A�����A��M���ݣ�M�ǷǸ�������
  �����磺
	A =
	1 2
	3 4
	A��2����
	7 10
	15 22
�����ʽ
	��һ����һ��������N��M��1<=N<=30, 0<=M<=5������ʾ����A�Ľ�����Ҫ�������
	������N�У�ÿ��N������ֵ������10�ķǸ���������������A��ֵ
�����ʽ
	�����N�У�ÿ��N����������ʾA��M��������Ӧ�ľ������ڵ���֮����һ���ո����
��������
	2 2
	1 2
	3 4
�������
	7 10
	15 22
*/

#include <iostream>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	long long int a[40][40], t[40][40], b[40][40]={0};
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>a[i][j];
			t[i][j] = a[i][j];
		}
	}
	if(m==0){
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(i!=j)
					cout<<0<<" ";
				else
					cout<<1<<" ";
			}
			cout<<endl;
		}
		return 0;
	}
	while(--m){
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				int k=n;
				while(k){
					b[i][j] += t[i][k-1]*a[k-1][j];
					k--;
				}
			}
		}
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				t[i][j] = b[i][j];
				b[i][j] = 0;
			}
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++)
			cout<<t[i][j]<<" ";
		cout<<endl;
	}
	system("pause");
	return 0;
}