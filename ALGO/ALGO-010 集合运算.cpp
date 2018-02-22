/*
算法训练 集合运算
时间限制：1.0s   内存限制：512.0MB
问题描述
　　给出两个整数集合A、B，求出他们的交集、并集以及B在A中的余集。
  输入格式
      第一行为一个整数n，表示集合A中的元素个数。
	  第二行有n个互不相同的用空格隔开的整数，表示集合A中的元素。
	  第三行为一个整数m，表示集合B中的元素个数。
	  第四行有m个互不相同的用空格隔开的整数，表示集合B中的元素。
	  集合中的所有元素均为int范围内的整数，n、m<=1000。
  输出格式
	  第一行按从小到大的顺序输出A、B交集中的所有元素。
	  第二行按从小到大的顺序输出A、B并集中的所有元素。
	  第三行按从小到大的顺序输出B在A中的余集中的所有元素。
  样例输入
		5
		1 2 3 4 5
		5
		2 4 6 8 10
  样例输出
		2 4
		1 2 3 4 5 6 8 10
		1 3 5
  样例输入
		4
		1 2 3 4
		3
		5 6 7
  样例输出
		1 2 3 4 5 6 7
		1 2 3 4
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main(){
	int A,B;
	set<int> ab;
	int AB[2010]={0};
	cin>>A;
	vector<int> a(A);
	for(int i=0; i<A; i++) cin>>a[i], ab.insert(a[i]), AB[a[i]]=1;
	sort(a.begin(), a.end());
	cin>>B;
	vector<int> b(B);
	for(int i=0; i<B; i++) cin>>b[i], ab.insert(b[i]);
	sort(b.begin(), b.end());
	int ok=0, shuchu=0;
	for(int i=0; i<B; i++){
		if(ok)
			cout<<" ";
		if(AB[b[i]]){
			ok=1;
			cout<<b[i];
			AB[b[i]]=2;
			shuchu=1;
		}
	}
	if(shuchu)
		cout<<endl;

	set<int>::iterator s;
	for(s=ab.begin(); s!=ab.end(); s++){
		if(s!=ab.begin())
			cout<<" ";
		cout<<*s;
	}
	cout<<endl;

	ok=0;
	for(int i=0; i<A; i++){
		if(ok && AB[a[i]]==1)
			cout<<" ";
		if(AB[a[i]]==1){
			ok=1;
			cout<<a[i];
		}
	}
	cout<<endl;
	system("pause");
	return 0;
}