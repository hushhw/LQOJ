/*
�㷨ѵ�� ��������
ʱ�����ƣ�1.0s   �ڴ����ƣ�512.0MB
��������
��������������������A��B��������ǵĽ����������Լ�B��A�е��༯��
  �����ʽ
      ��һ��Ϊһ������n����ʾ����A�е�Ԫ�ظ�����
	  �ڶ�����n��������ͬ���ÿո��������������ʾ����A�е�Ԫ�ء�
	  ������Ϊһ������m����ʾ����B�е�Ԫ�ظ�����
	  ��������m��������ͬ���ÿո��������������ʾ����B�е�Ԫ�ء�
	  �����е�����Ԫ�ؾ�Ϊint��Χ�ڵ�������n��m<=1000��
  �����ʽ
	  ��һ�а���С�����˳�����A��B�����е�����Ԫ�ء�
	  �ڶ��а���С�����˳�����A��B�����е�����Ԫ�ء�
	  �����а���С�����˳�����B��A�е��༯�е�����Ԫ�ء�
  ��������
		5
		1 2 3 4 5
		5
		2 4 6 8 10
  �������
		2 4
		1 2 3 4 5 6 8 10
		1 3 5
  ��������
		4
		1 2 3 4
		3
		5 6 7
  �������
		1 2 3 4 5 6 7
		1 2 3 4
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main(){
	int A,B;
	set<int> ab;
	int AB[2010]={0};
	cin>>A;
	vector<int> a(A);
	for(int i=0; i<A; i++) cin>>a[i], ab.insert(a[i]), AB[a[i]]=1;
	sort(a.begin(), a.end());
	cin>>B;
	vector<int> b(B);
	for(int i=0; i<B; i++) cin>>b[i], ab.insert(b[i]);
	sort(b.begin(), b.end());
	int ok=0, shuchu=0;
	for(int i=0; i<B; i++){
		if(ok)
			cout<<" ";
		if(AB[b[i]]){
			ok=1;
			cout<<b[i];
			AB[b[i]]=2;
			shuchu=1;
		}
	}
	if(shuchu)
		cout<<endl;

	set<int>::iterator s;
	for(s=ab.begin(); s!=ab.end(); s++){
		if(s!=ab.begin())
			cout<<" ";
		cout<<*s;
	}
	cout<<endl;

	ok=0;
	for(int i=0; i<A; i++){
		if(ok && AB[a[i]]==1)
			cout<<" ";
		if(AB[a[i]]==1){
			ok=1;
			cout<<a[i];
		}
	}
	cout<<endl;
	system("pause");
	return 0;
}