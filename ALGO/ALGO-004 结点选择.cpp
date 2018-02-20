/*
��������
��һ�� n ���ڵ����������ÿ���ڵ㶼��һ��������Ȩֵ�����һ���㱻ѡ���ˣ���ô�����Ϻ������ڵĵ㶼���ܱ�ѡ����ѡ���ĵ��Ȩֵ������Ƕ��٣�

�����ʽ
��һ�а���һ������ n ��

��������һ�а��� n ������������ i ������������� i ��Ȩֵ��

������һ�� n-1 �У�ÿ���������ϵ�һ���ߡ�

�����ʽ
���һ������������ѡ���ĵ��Ȩֵ�͵����ֵ��
��������
5
1 2 3 4 5
1 2
1 3
2 4
2 5
�������
12
����˵��
ѡ��3��4��5�ŵ㣬Ȩֵ��Ϊ 3+4+5 = 12 ��
���ݹ�ģ��Լ��
����20%�����ݣ� n <= 20��

����50%�����ݣ� n <= 1000��

����100%�����ݣ� n <= 100000��

Ȩֵ��Ϊ������1000����������
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int dp[100010][2];
//dp[i][0]��ʾ��ȡi���Ľ����dp[i][1]��ʾȡi���Ľ����
vector< vector<int> > v;
//v[i]�����б���i���ĺ��ӽڵ���

void dfs(int node, int pre){
//pre���浱ǰ����ǰһ����㡫�������pre˵�����ʵ������ĸ��׽��
	//cout<<"node:"<<node<<" size:"<<v[node].size()<<" pre:"<<pre<<endl;
	for(int i=0; i<v[node].size(); i++){
		int temp = v[node][i];
		if(temp != pre){
			dfs(temp, node);
			dp[node][0] += max(dp[temp][0], dp[temp][1]);
			dp[node][1] += dp[temp][0];
		}
	}
}

int main(){
	int n,a,b;
	scanf("%d",&n);
	for(int i=1; i<=n; i++) scanf("%d", &dp[i][1]);
	v.resize(n+1);
	for(int i=1; i<=n-1; i++){
		scanf("%d%d", &a, &b);
		//�����ڽӱ�
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1, 0); //�ӵ�1�����ۼӵ�����
	cout<<max(dp[1][0], dp[1][1])<<endl;
	system("pause");
	return 0;
}