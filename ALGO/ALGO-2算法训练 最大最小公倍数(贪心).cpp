/*
��������
��֪һ��������N���ʴ�1~N����ѡ�������������ǵ���С������������Ϊ���١�

�����ʽ
����һ��������N��

�����ʽ
���һ����������ʾ���ҵ�����С��������
��������
9
�������
504
���ݹ�ģ��Լ��
1 <= N <= 106��
*/

#include <iostream>
#include <string>
using namespace std;

int main() {  
	long long n, ans;  
	cin >> n;  
	if(n <= 2)  
		ans = n;  
	else if(n % 2 == 1)  
		ans = n * (n-1) * (n-2);  
	else if(n % 3 == 0) 
		ans = (n - 1) * (n - 2) * (n - 3);  
	else 
		ans = n * (n - 1) * (n - 3);    
	cout << ans << endl;  
	system("pause");
	return 0;  
}