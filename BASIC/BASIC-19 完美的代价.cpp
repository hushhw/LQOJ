/*

问题描述
回文串，是一种特殊的字符串，它从左往右读和从右往左读是一样的。小龙龙认为回文串才是完美的。
现在给你一个串，它不一定是回文的，请你计算最少的交换次数使得该串变成一个完美的回文串。
交换的定义是：交换两个相邻的字符
例如mamad
第一次交换 ad : mamda
第二次交换 md : madma
第三次交换 ma : madam (回文！完美！)
输入格式
第一行是一个整数N，表示接下来的字符串的长度(N <= 8000)
第二行是一个字符串，长度为N.只包含小写字母
输出格式
如果可能，输出最少的交换次数。
否则输出Impossible
样例输入
5
mamad
样例输出
3

*/

/*
贪心思想，从左向右遍历，对于当前字符，从最右边向左遍历，找到与当前字符相同的，把它移动到正确位置，累加步数。

如果字符串长度为偶数，只要有一个无法配对的字符，就不能变成回文串，若为奇数，只要出现两个无法配对的字符，也不能。
*/

#include <iostream>
#include <string>
using namespace std;

int main(){
	int n, ok=1, c=-1, sum=0;
	string ch;
	cin>>n>>ch;
	int j = ch.length()-1;
	for(int i=0; i<=j-1; i++){
		for(int k=j; k>=i; k--){
			if(k==i){
				if(n%2==0 || c!=-1){//为偶数只要有单个的就一定Impossible，另外一种有两个单着的也是一定impossible
					ok=0;
					break;
				}
				c=1;
				sum+=n/2-i;	//将这个单着的移到中间
				break;
			}
			if(ch[k]==ch[i]){
				for(int t=k; t<=j-1; t++)
					swap(ch[t], ch[t+1]);
				sum += j-k;
				j--;
				break;
			}
		}
		if(!ok) break;
	}
	if(!ok) printf("Impossible\n");
	else
		printf("%d\n", sum);
	return 0;
}