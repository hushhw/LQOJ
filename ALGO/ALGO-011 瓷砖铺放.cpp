/*
��������
������һ����ΪN(1<=��<=10)�ĵذ壬�������ֲ�ͬ��ש��һ�ֳ���Ϊ1����һ�ֳ���Ϊ2����Ŀ���ޡ�Ҫ���������ΪN�ĵذ�������һ���ж����ֲ�ͬ���̷���
  �����磬����Ϊ4�ĵ���һ��������5���̷���
	4=1+1+1+1
	4=2+1+1
	4=1+2+1
	4=1+1+2
	4=2+2
	����õݹ�ķ�������������⡣

�����ʽ
	ֻ��һ����N������ذ�ĳ���
�����ʽ
	���һ�������������в�ͬ�Ĵ�ש�̷ŷ���������

��������
	4
�������
	5
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

int sum;

void digui(int t, int n){
	if(t==n){
		sum++;
		return ;
	}

	if(t>n)
		return ;

	digui(t+1,n);
	digui(t+2,n);
}

int main(){
	int n;
	while(~scanf("%d",&n)){
		sum=0;
		digui(0,n);
		cout<<sum<<endl;
	}
	return 0;
}