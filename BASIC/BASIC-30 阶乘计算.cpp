/*
��������
��������һ��������n�����n!��ֵ��
  ��������n!=1*2*3*��*n��
	�㷨����
	��n!���ܴܺ󣬶�������ܱ�ʾ��������Χ���ޣ���Ҫʹ�ø߾��ȼ���ķ�����ʹ��һ������A����ʾһ��������a��A[0]��ʾa�ĸ�λ��A[1]��ʾa��ʮλ���������ơ�
	  ��a����һ������k��Ϊ������A��ÿһ��Ԫ�ض�����k����ע�⴦����Ӧ�Ľ�λ��
	  ���Ƚ�a��Ϊ1��Ȼ���2����3�����˵�nʱ�����õ���n!��ֵ��
�����ʽ
	�������һ��������n��n<=1000��
�����ʽ
	���n!��׼ȷֵ��
��������
	10
�������
	3628800
*/

#include <iostream>
#include <string>
#define N 1001
using namespace std;

int main(){
	int n;
	int i, j;
	int a[N];		//�����洢�����ÿһλ��Ӧһλ����
	int w=0;		//�����ж��Ƿ��н�λ
	int t;			//�洢ʮλ����

	cin>>n;
	memset(a, 0, sizeof(a));
	a[0]=1;

	for(i=1; i<=n; i++){
		for(j=0; j<=w; j++){
			if(j==0){
				t=a[j]*i;
				a[j]=t%10;		//��a[j]����ÿһ����˺�ĸ�λ��
				t=t/10;			//t������˺��ʮλ��
				if(j==w && t>0)	//w�����Ƿ��н�λ�����t>0˵����λ�ˣ���w++
					w++;
				cout<<"a[j]="<<a[j]<<endl;
				cout<<"t="<<t<<endl;
			}else{
				t=a[j]*i+t;
				a[j]=t%10;
				t=t/10;
				if(j==w && t>0)
					w++;
				cout<<"a[j]="<<a[j]<<endl;
				cout<<"t="<<t<<endl;
			}
		}
	}
	for(i=w; i>=0; i--)
		cout<<a[i];
	cout<<endl;
	system("pause");
	return 0;
}

/*
int main(){
	int n;
	cin>>n;
	int A[10000] = {1};
	for(int i=1; i<=n; i++){
		for(int j=0; j<10000; j++){
			A[j] = A[j]*i;
		}
		for(int j=0; j<10000; j++){
			if(A[j]>=9){
				A[j+1] = A[j+1] + A[j]/10;
				A[j] = A[j]%10;
			}
		}
	}
	int t=0;
	for(int i=9999; i>=0; i--){
		if(A[i]!=0){
			t=i;
			break;
		}
	}
	for(int i=t; i>=0; i--)
		cout<<A[i];
	system("pause");
	return 0;
}
*/