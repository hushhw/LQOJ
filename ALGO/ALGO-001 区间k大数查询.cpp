/*
��������
����һ�����У�ÿ��ѯ�������е�l��������r�����е�K��������ĸ���

�����ʽ
��һ�а���һ����n����ʾ���г��ȡ�

�ڶ��а���n������������ʾ���������С�

����������һ��������m����ʾѯ�ʸ�����

������m�У�ÿ��������l,r,K����ʾѯ�����д������ҵ�l��������r�����У��Ӵ���С��K��������ĸ�������Ԫ�ش�1��ʼ��š�

�����ʽ
�ܹ����m�У�ÿ��һ��������ʾѯ�ʵĴ𰸡�
��������
5
1 2 3 4 5
2
1 5 2
2 3 2
�������
4
2
���ݹ�ģ��Լ��
����30%�����ݣ�n,m<=100��

����100%�����ݣ�n,m<=1000��

��֤k<=(r-l+1)�������е���<=106��
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int cmp(int a, int b){return a > b;}

int main() {
	int n, m;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> m;
	vector<int> result(m);
	for (int i = 0; i < m; i++) {
		int l, r, k;
		cin >> l >> r >> k;
		int *temp = new int [n];
		for(int j = 0; j < n; j++) {
			temp[j] = a[j];
		}
		sort(temp + l - 1, temp + r, cmp);
		result[i] = temp[l - 1 + k - 1];
		delete [] temp;
	}
	for (int i = 0; i < m; i++) {
		cout << result[i] << endl;
	}
	return 0;
}
