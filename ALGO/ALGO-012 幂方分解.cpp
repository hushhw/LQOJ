/*
问题描述
　　任何一个正整数都可以用2的幂次方表示。例如：
  　137=27+23+20 
	同时约定方次用括号来表示，即ab 可表示为a（b）。
	由此可知，137可表示为：
	2（7）+2（3）+2（0）
	进一步：7= 22+2+20 （21用2表示）
	3=2+20 
	所以最后137可表示为：
	2（2（2）+2+2（0））+2（2+2（0））+2（0）
	又如：
	1315=210 +28 +25 +2+1
	所以1315最后可表示为：
	2（2（2+2（0））+2）+2（2（2+2（0）））+2（2（2）+2（0））+2+2（0）
输入格式
	输入包含一个正整数N（N<=20000），为要求分解的整数。
输出格式
	程序输出包含一行字符串，为符合约定的n的0，2表示（在表示中不能有空格）
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;
int a[15]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384};  
int n;

void solve(int n){
	if(n==0) return ;
	if(n==1) {cout<<"2(0)"; return;}
	if(n==2) {cout<<"2";	return;}
	int i=14;
	while(a[i]>n && i>=0){
		i--;
	}
	cout<<"2";
	if(i>1){
		cout<<"(";
		solve(i);
		cout<<")";
	}
	n -= a[i];
	if(n) cout<<"+";
	solve(n);
}

int main(){
	scanf("%d", &n);
		solve(n);
	return 0;
}