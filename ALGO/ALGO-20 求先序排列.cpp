/*
��������
��������һ�ö�������������������С���������������С���Լ��������ò�ͬ�Ĵ�д��ĸ��ʾ������<=8����
�����ʽ
  �������У�ÿ��һ���ַ������ֱ��ʾ����ͺ�������
�����ʽ
	����һ���ַ�������ʾ������������
��������
	  BADC
	  BDCA
�������
	  ABCD
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

void tree(string a, string b){
	int l=a.length();
	char c=b[l-1];
	cout<<c;
	int k=a.find(c);
	if(k!=0) tree(a.substr(0,k), b.substr(0,k));
	if(k!=l-1) tree(a.substr(k+1,l-k-1), b.substr(k,l-k-1));
}

int main(){
	string z,h;
	cin>>z>>h;
	tree(z,h);
	system("pause");
	return 0;
}