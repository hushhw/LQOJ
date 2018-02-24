/*
��������
����һ�����м����ʻ���������ٵķ��ô�һ�����е���һ�����У��������ʱ�����ǿյģ���
  ������������֮��ľ���D1��
  �������������C������Ϊ��λ����ÿ����������ʻ�ľ���D2��
  ������ÿ�����ͼ۸�P����;��վ��N��N����Ϊ�㣩����վi�������ľ���Di��ÿ�����ͼ۸�Pi��i=1��2������N����
  ����������������С�������λ������޷�����Ŀ�ĵأ��������No Solution����
�����ʽ
  ������һ��Ϊ4��ʵ��D1��C��D2��P��һ���Ǹ�����N��
	����������N�У�ÿ������ʵ��Di��Pi��
�����ʽ
	 ������Ե���Ŀ�ĵأ����һ��ʵ��������������С�������λ������ʾ��С���ã����������No Solution�����������ţ���
��������
		275.6 11.9 27.4 2.8 2
		102.0 2.9
		220.0 2.2
�������
		26.95
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

int main(){
	double D1, C, D2, P, N;
	cin>>D1>>C>>D2>>P>>N;//�����ܳ��ȡ�����������λ������ʻ���롢��ʼ���͵��ۡ����͵�
	vector<double> d(N+2);
	vector<double> p(N+2);

	for(int i=1; i<=N; i++){
		cin>>d[i]>>p[i];
	}
	d[0] = 0; d[N+1] = D1;
	p[0] = P; p[N+1] = 0;

	for(int i = 1; i <= N+1; i++) {//�ж��ܲ��ܵ��� 
		if( C*D2 < d[i] - d[i-1] ) {
			printf("No Solution\n");
			return 0;
		}
	}

	int i=0;
	double count = 0; //���ͼ�
	double yu = 0; //����
	while(i<N+1){
		int j = i+1;
		if(p[j] > p[i]){
			while(p[j] > p[i] && d[j]-d[i] <= C*D2)
				j++;
			if(d[j]-d[i] > C*D2){
				count += (C-yu)*p[i];
				yu = C - (d[j-1]-d[j])/D2;
				i = j-1;
			} else {
				count += ((d[j]-d[i])/D2-yu)*p[i];
				yu = 0;
				i = j;
			}
		} else {
			count += ((d[j]-d[i])/D2-yu)*p[i];
			yu = 0;
			i = j;
		}
	}
	printf("%.2lf\n", count); 
	system("pause");
	return 0;
}