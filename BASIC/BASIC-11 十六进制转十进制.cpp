/*
���ű� BASIC-11 ������ϰ ʮ������תʮ����
��������
�����Ӽ�������һ��������8λ������ʮ���������ַ���������ת��Ϊ����ʮ�������������
  ����ע��ʮ���������е�10~15�ֱ��ô�д��Ӣ����ĸA��B��C��D��E��F��ʾ��
��������
	FFFF
�������
	65535
*/

#include <iostream>
#include <string>
using namespace std;

int main(){
	string str;
	cin>>str;
	int len = str.length();
	long long sum=0;
	for(int i=0; i<len; i++){
		if(str[i]>='A'&&str[i]<='F'){
			sum = sum*16 + str[i]-'A'+10;
		} else{
			sum = sum*16 + str[i]-'0';
		}
	
	}
	cout<<sum<<endl;
	system("pause");
	return 0;
}