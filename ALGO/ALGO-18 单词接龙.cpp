/*
问题描述 
　　单词接龙是一个与我们经常玩的成语接龙相类似的游戏，现在我们已知一组单词，且给定一个开头的字母，
  要求出以这个字母开头的最长的“龙”（每个单词都最多在“龙”中出现两次）
  ，在两个单词相连时，其重合部分合为一部分，例如 beast和astonish，如果接成一条龙则变为beastonish，
  另外相邻的两部分不能存在包含关系，例如at 和 atide 间不能相连。

输入格式
  　　输入的第一行为一个单独的整数n (n<=20)表示单词数，以下n 行每行有一个单词，
	输入的最后一行为一个单个字符，表示“龙”开头的字母。你可以假定以此字母开头的“龙”一定存在.

输出格式
	　　只需输出以此字母开头的最长的“龙”的长度
样例输入
	  5
	  at
	  touch
	  cheat
	  choose
	  tact
	  a
样例输出
	  23
样例说明
	  连成的“龙”为atoucheatactactouchoose
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
int use[maxn];    //通常这个，好多DFS题目都会用到的，用来标志使用情况,这里作用是标志使用<2次的情况
void input();     //输入数据
int check(int lh, int rh);   //这个几乎也是都会用到的，用来检查DFS进行的条件,以及相关操作
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
	//k: 这是"下一个字符串"的索引 
	for(int k=1; k<min(l_l, r_l); k++){
		flag = true;
		// i: 这是"前一个字符串"
		// i = l_l - k,代表后面的字符已经匹配，
		//正在尝试向前匹配寻找更长的匹配长度 
		// j--下一个字符串匹配索引
		for(int i=l_l-k, j=0; i<l_l&&j<k; i++, j++){
			if (dick[lh][i] != dick[rh][j]) {
				flag = false;
				break;
			}
		}
		//k为前一个字符串尾部向前和下一个字符串头部向后匹配的长度 
		if (flag) {
			return k;//返回重叠的数
		}
	}
	//没有在里面退出,说明是包含关系 or 不重复 
	return 0;     
}

//last--下一个字符串索引, len -- 当前已经计算了的字符串长度 
void dfs(int last, int len, bool first){
	if(first){		//第一次的时候 从这里开始(需要找 ch 开头的字符串) 
		for(int i=0; i<n; i++){
			if(dick[i][0] == ch){
				if(use[i]<2){	//使用没有超过两次
					use[i]++;
					//从开头字符是ch的字符串开始递归搜索
					//将first标记为false
					dfs(i, dick[i].size(), false);
					use[i]--;
				}
			}
		}
	}else{
		//从搜索的组合中，不断更新得到最大长度
		ans = max(ans,len);
		for(int i=0; i<n; i++){
			//上一个字符串尾部和下一个字符串开头，
			//匹配的长度
			int x=check(last, i);
			//有匹配，且字符串使用不超过2次
			if(x && use[i]<2){
				use[i]++;
				//已经计算的长度+当前字符串的长度-重复的长度==>得到当前总长度
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
