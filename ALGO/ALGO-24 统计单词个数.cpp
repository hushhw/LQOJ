/*
ALGO-24	VIP���� ͳ�Ƶ��ʸ���
��������
������дһ����������һ���ַ��������Ȳ�����80����Ȼ��ͳ�Ƴ����ַ������а����ж��ٸ����ʡ�
   ���磺�ַ�����this is a book�����а�����4�����ʡ�
�����ʽ������һ���ַ����������ɸ�������ɣ�����֮����һ���ո������
�����ʽ�����һ�������������ʵĸ�����
�����������
�û���������������
	this is a book
ϵͳ����������£�
	4
*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main(){
	string str;
	getline(cin,str);
	int count=0;
	for(int i=0; i<str.length(); i++){
		if(str[i]==' ')
			count++;
	}
	cout<<count+1<<endl;
	system("pause");
	return 0;
}