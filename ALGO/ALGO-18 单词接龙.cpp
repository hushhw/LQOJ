/*
�������� 
�������ʽ�����һ�������Ǿ�����ĳ�����������Ƶ���Ϸ������������֪һ�鵥�ʣ��Ҹ���һ����ͷ����ĸ��
  Ҫ����������ĸ��ͷ����ġ�������ÿ�����ʶ�����ڡ������г������Σ�
  ����������������ʱ�����غϲ��ֺ�Ϊһ���֣����� beast��astonish������ӳ�һ�������Ϊbeastonish��
  �������ڵ������ֲ��ܴ��ڰ�����ϵ������at �� atide �䲻��������

�����ʽ
  ��������ĵ�һ��Ϊһ������������n (n<=20)��ʾ������������n ��ÿ����һ�����ʣ�
	��������һ��Ϊһ�������ַ�����ʾ��������ͷ����ĸ������Լٶ��Դ���ĸ��ͷ�ġ�����һ������.

�����ʽ
	����ֻ������Դ���ĸ��ͷ����ġ������ĳ���
��������
	  5
	  at
	  touch
	  cheat
	  choose
	  tact
	  a
�������
	  23
����˵��
	  ���ɵġ�����Ϊatoucheatactactouchoose
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

const int maxn=20+10;
int n;
int ans;
char ch;
string dick[maxn];
int use[maxn];    //ͨ��������ö�DFS��Ŀ�����õ��ģ�������־ʹ�����,���������Ǳ�־ʹ��<2�ε����
void input();     //��������
int check(int lh, int rh);   //�������Ҳ�Ƕ����õ��ģ��������DFS���е�����,�Լ���ز���
void dfs(int cur, int len, bool first);
void solve();

void input(int n){
	memset(use, 0, sizeof(use));
	for(int i=0; i<n; i++){
		cin>>dick[i];
	}
	cin>>ch;
}

int check(int lh, int rh){
	int l_l = dick[lh].size(), r_l = dick[rh].size();
	bool flag;
	//k: ����"��һ���ַ���"������ 
	for(int k=1; k<min(l_l, r_l); k++){
		flag = true;
		// i: ����"ǰһ���ַ���"
		// i = l_l - k,���������ַ��Ѿ�ƥ�䣬
		//���ڳ�����ǰƥ��Ѱ�Ҹ�����ƥ�䳤�� 
		// j--��һ���ַ���ƥ������
		for(int i=l_l-k, j=0; i<l_l&&j<k; i++, j++){
			if (dick[lh][i] != dick[rh][j]) {
				flag = false;
				break;
			}
		}
		//kΪǰһ���ַ���β����ǰ����һ���ַ���ͷ�����ƥ��ĳ��� 
		if (flag) {
			return k;//�����ص�����
		}
	}
	//û���������˳�,˵���ǰ�����ϵ or ���ظ� 
	return 0;     
}

//last--��һ���ַ�������, len -- ��ǰ�Ѿ������˵��ַ������� 
void dfs(int last, int len, bool first){
	if(first){		//��һ�ε�ʱ�� �����￪ʼ(��Ҫ�� ch ��ͷ���ַ���) 
		for(int i=0; i<n; i++){
			if(dick[i][0] == ch){
				if(use[i]<2){	//ʹ��û�г�������
					use[i]++;
					//�ӿ�ͷ�ַ���ch���ַ�����ʼ�ݹ�����
					//��first���Ϊfalse
					dfs(i, dick[i].size(), false);
					use[i]--;
				}
			}
		}
	}else{
		//������������У����ϸ��µõ���󳤶�
		ans = max(ans,len);
		for(int i=0; i<n; i++){
			//��һ���ַ���β������һ���ַ�����ͷ��
			//ƥ��ĳ���
			int x=check(last, i);
			//��ƥ�䣬���ַ���ʹ�ò�����2��
			if(x && use[i]<2){
				use[i]++;
				//�Ѿ�����ĳ���+��ǰ�ַ����ĳ���-�ظ��ĳ���==>�õ���ǰ�ܳ���
				dfs(i, len+dick[i].size()-x, false);
				use[i]--;
			}
		}
	}
}

void solve(){
	scanf("%d",&n);
	input(n);
	dfs(0,1,true);
	cout<<ans<<endl;
}

int main(){
	solve();
	system("pause");
	return 0;
}
