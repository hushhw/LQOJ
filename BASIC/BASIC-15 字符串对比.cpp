/*
��������
���������������ɴ�д��ĸ��Сд��ĸ��ɵ��ַ���(���Ƚ���1��10֮��)������֮��Ĺ�ϵ������4�����֮һ��
  ����1�������ַ������Ȳ��ȡ����� Beijing �� Hebei
	��2�������ַ�������������ȣ�������Ӧλ���ϵ��ַ���ȫһ��(���ִ�Сд)������ Beijing �� Beijing
	  3�������ַ���������ȣ���Ӧλ���ϵ��ַ����ڲ����ִ�Сд��ǰ���²��ܴﵽ��ȫһ�£�Ҳ����˵���������������2�������� beijing �� BEIjing
	  4�������ַ���������ȣ����Ǽ�ʹ�ǲ����ִ�СдҲ����ʹ�������ַ���һ�¡����� Beijing �� Nanjing
	����ж�����������ַ���֮��Ĺ�ϵ�����������е���һ�࣬������������ı�š�
�����ʽ
	�������У�ÿ�ж���һ���ַ���
�����ʽ
	����һ�����֣������������ַ����Ĺ�ϵ���
��������
	BEIjing
	beiJing 
�������
	3
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
	string a, b;
	cin >> a >> b;
	int lena = a.length();
	int lenb = b.length();
	if (lena != lenb) {
		cout << 1;
		return 0;
	}
	int flag = 1;
	for (int i = 0; i < lena; i++) {
		if (a[i] != b[i]) {
			flag = 0;
			break;
		}
	}
	if (flag == 1) {
		cout << 2;
		return 0;
	}
	int flag2 = 1;
	for (int i = 0; i < lena; i++) {
		a[i] = tolower(a[i]);
		b[i] = tolower(b[i]);
		if (a[i] != b[i]) {
			flag2 = 0;
			break;
		}
	}
	if (flag2 == 1) {
		cout << 3;
	} else {
		cout << 4;
	}
	return 0;
}