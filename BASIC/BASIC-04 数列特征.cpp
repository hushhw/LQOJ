/*
BASIC-4 ������ϰ ��������

��������
����n�������ҳ���n���������ֵ����Сֵ���͡�

�����ʽ
��һ��Ϊ����n����ʾ���ĸ�����

�ڶ�����n������Ϊ������n������ÿ�����ľ���ֵ��С��10000��

�����ʽ
������У�ÿ��һ����������һ�б�ʾ��Щ���е����ֵ���ڶ��б�ʾ��Щ���е���Сֵ�������б�ʾ��Щ���ĺ͡�
��������
5
1 3 -2 4 5
�������
5
-2
11
���ݹ�ģ��Լ��
1 <= n <= 10000��*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	int n, sum=0;
	cin>>n;
	vector<int> a(n);
	for(int i=0; i<n; i++) cin>>a[i], sum+=a[i];
	sort(a.begin(), a.end());
	cout<<a[n-1]<<endl<<a[0]<<endl<<sum<<endl;
	system("pause");
	return 0;
}