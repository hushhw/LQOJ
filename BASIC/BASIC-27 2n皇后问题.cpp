/*
问题描述
给定一个n*n的棋盘，棋盘中有一些位置不能放皇后。
现在要向棋盘中放入n个黑皇后和n个白皇后，使任意的两个黑皇后都不在同一行、同一列或同一条对角线上，任意的两个白皇后都不在同一行、同一列或同一条对角线上。问总共有多少种放法？n小于等于8。
输入格式
输入的第一行为一个整数n，表示棋盘的大小。
接下来n行，每行n个0或1的整数，如果一个整数为1，表示对应的位置可以放皇后，如果一个整数为0，表示对应的位置不可以放皇后。
输出格式
输出一个整数，表示总共有多少种放法。
样例输入
4
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
样例输出
2
样例输入
4
1 0 1 1
1 1 1 1
1 1 1 1
1 1 1 1
样例输出
0
*/

/*
八皇后的题竟然还是做的这么艰难。
以行为界限，因为不同元素肯定在不同的行上面，这样就用一个一维数组q[i]来表示第i个元素所在的列为q[i],也就是说第i个元素的坐标为(i, q[i])。
之所以写成这种形式，是为了判断方便，因为这类问题普遍要求不在同一行，不在同一列，不在统一对角线，
这就意味着，每次找到一个位置，需要与之前所有的元素的坐标进行计算比较，如果是一个满足条件的位置，就记下这个位置，并继续搜索下一个位置，
这里关键问题是怎样判断一个位置是否合法：
1.因为我们本来就是让不同的元素在不同的行，所以不存在同行这种情况。

2.如果当前所枚举的是第r个元素，需要判断（r，i）这个位置是否合法，那么需要遍历j从0到r-1，每一个元素的坐标为（j，q[j]），
如果两个元素在同一列，那么i==q[j]，如果两个元素在对角线上，那么abs(r-j)==abs(i-q[j])，只要这两个条件不满足，就说明这个位置是合法的。

以上是完成一次n皇后的搜索，题目实际上是要求完成两次，并且两次搜索所得到的皇后位置不能重合，所以还要一个visit数组来记录访问情况。
*/

#include <iostream>
#include <string>
using namespace std;

int q[10][10];
bool visit[10][10];
int b[10],w[10];
int sum;

bool panduan(int *q, int r, int c){
	int i;
	int t_r, t_c;
	for(int i=0; i<r; i++){
		t_r = i;	//之前已经被标记的皇后坐标(i,q[i])。
		t_c = q[i];
		if(abs(r-t_r)==abs(c-t_c) || (c-t_c==0))//如果在同一列，或在对角线上
			return 0;
	}
	return 1;
}

void w_queen(int t, int n){
	if(t==n){
		sum++;
		return ;
	}
	for(int i=0; i<n; i++){
		if(q[t][i]==1 && visit[t][i]==0 && panduan(w, t, i)){
			w[t]=i;
			w_queen(t+1, n);
		}
	}
}

void b_queen(int t, int n){ //t代表行号
	if(t==n){
		w_queen(0, n);
		return ;
	}
	for(int i=0; i<n; i++){
		if(q[t][i]==1 && visit[t][i]==0 && panduan(b, t, i)){
			b[t]=i;
			visit[t][i]=1; //已经被标记
			b_queen(t+1, n);
			visit[t][i]=0;
		}
	}
}

int main(){
	int n;
	sum=0;
	cin>>n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>q[i][j];
		}
	}
	memset(visit, 0, sizeof(visit));
	b_queen(0,n);
	cout<<sum<<endl;
	system("pause");
	return 0;
}

/*
#include <iostream>
#include <string>
using namespace std;

int Map[10][10];
int visit[10][10];
int q_w[10],q_b[10]; //第i个元素所在的列，行肯定是不同的
int n, sum;

int place(int *q, int r, int c){ //判断位置是否合法
	int i;
	int t_r, t_c; //每一行元素的坐标(t_r,t_c)
	for(i=0; i<r; i++){
		t_r=i;
		t_c=q[i];
		if(abs(r-t_r)==abs(c-t_c) || (c-t_c==0))//不在对角线上不在同一列
			return 0;
	}
	return 1;
}

void dfs_w(int r){
	if(r==n){
		sum++;
		return ;
	}
	for(int i=0; i<n; i++){
		if(visit[r][i]==0 && Map[r][i]==1 && place(q_w,r,i)){
			q_w[r]=i;
			dfs_w(r+1);
		}
	}
}

void dfs_b(int r){ //搜索黑皇后
	if(r==n){	//找到一个黑皇后满足条件
		dfs_w(0);
		return ;
	}
	for(int i=0; i<n; i++){
		if(Map[r][i]==1 && place(q_b,r,i)){
			q_b[r]=i;
			visit[r][i]=1; //已经被标记
			dfs_b(r+1);
			visit[r][i]=0;
		}
	}
}

int main(){
	memset(visit, 0, sizeof(visit));
	memset(q_w, 0, sizeof(q_w));
	memset(q_b, 0, sizeof(q_b));
	sum=0;

	cin>>n;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin>>Map[i][j];

	dfs_b(0);

	cout<<sum<<endl;
	system("pause");
	return 0;
}
*/