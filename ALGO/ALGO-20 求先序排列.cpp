/*
问题描述
　　给出一棵二叉树的中序与后序排列。求出它的先序排列。（约定树结点用不同的大写字母表示，长度<=8）。
输入格式
  　　两行，每行一个字符串，分别表示中序和后序排列
输出格式
	　　一个字符串，表示所求先序排列
样例输入
	  BADC
	  BDCA
样例输出
	  ABCD
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

void tree(string a, string b){
	int l=a.length();
	char c=b[l-1];
	cout<<c;
	int k=a.find(c);
	if(k!=0) tree(a.substr(0,k), b.substr(0,k));
	if(k!=l-1) tree(a.substr(k+1,l-k-1), b.substr(k,l-k-1));
}

int main(){
	string z,h;
	cin>>z>>h;
	tree(z,h);
	system("pause");
	return 0;
}