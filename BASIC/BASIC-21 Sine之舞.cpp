/*
��������
	���FJΪ������ţ�ǿ�������ѧ�����Σ�FJ֪����Ҫѧ�����ſΣ�������һ���õ����Ǻ�����������
	������׼������ţ����һ����Sine֮�衱����Ϸ��Ԣ�����֣������ţ�ǵļ���������
	������An=sin(1�Csin(2+sin(3�Csin(4+...sin(n))...)
	  ����Sn=(...(A1+n)A2+n-1)A3+...+2)An+1
	FJ������ţ�Ǽ���Sn��ֵ���������FJ��ӡ��Sn���������ʽ���Է�����ţ�����⡣
�����ʽ
	����һ������N<201��
�����ʽ
	�������Ӧ�ı��ʽSn����һ�����з�����������в��ú��ж���Ŀո���С��س�����
��������
	3
�������
	((sin(1)+3)sin(1�Csin(2))+2)sin(1�Csin(2+sin(3)))+1

	A1 = sin(3)
	A2 = sin(2+sin(3))
	A3 = sin(1-sin(2+sin(3)))

	Sn=(...(A1+n)A2+n-1)A3+...+2)An+1
	S1=(null)A1+1
	S2=(A1+2)A2+1
	S3=((A1+3)A2+2)A3+1
	S4=(((A1+4)A2+3)A3+2)A4+1
*/

#include <iostream>
#include <string>
using namespace std;

void A(int n){
	for(int i=1; i<=n; i++){
		cout<<"sin("<<i;
		if(i%2==0 && i!=n)
			cout<<"+";
		else if(i%2!=0 && i!=n)
			cout<<"-";
	}
	for(int i=1; i<=n; i++)
		cout<<")";
}

int main(){
	int n;
	cin>>n;
	for(int i=1; i<n; i++)
		cout<<"(";
	for(int i=1; i<=n; i++){
		A(i);
		cout<<"+"<<n-i+1;
		if(i!=n)
			cout<<")";
	}
	cout<<endl;
	system("pause");
	return 0;
}
