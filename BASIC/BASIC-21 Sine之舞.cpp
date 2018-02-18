/*
问题描述
	最近FJ为他的奶牛们开设了数学分析课，FJ知道若要学好这门课，必须有一个好的三角函数基本功。
	所以他准备和奶牛们做一个“Sine之舞”的游戏，寓教于乐，提高奶牛们的计算能力。
	不妨设An=sin(1–sin(2+sin(3–sin(4+...sin(n))...)
	  　　Sn=(...(A1+n)A2+n-1)A3+...+2)An+1
	FJ想让奶牛们计算Sn的值，请你帮助FJ打印出Sn的完整表达式，以方便奶牛们做题。
输入格式
	仅有一个数：N<201。
输出格式
	请输出相应的表达式Sn，以一个换行符结束。输出中不得含有多余的空格或换行、回车符。
样例输入
	3
样例输出
	((sin(1)+3)sin(1–sin(2))+2)sin(1–sin(2+sin(3)))+1

	A1 = sin(3)
	A2 = sin(2+sin(3))
	A3 = sin(1-sin(2+sin(3)))

	Sn=(...(A1+n)A2+n-1)A3+...+2)An+1
	S1=(null)A1+1
	S2=(A1+2)A2+1
	S3=((A1+3)A2+2)A3+1
	S4=(((A1+4)A2+3)A3+2)A4+1
*/

#include <iostream>
#include <string>
using namespace std;

void A(int n){
	for(int i=1; i<=n; i++){
		cout<<"sin("<<i;
		if(i%2==0 && i!=n)
			cout<<"+";
		else if(i%2!=0 && i!=n)
			cout<<"-";
	}
	for(int i=1; i<=n; i++)
		cout<<")";
}

int main(){
	int n;
	cin>>n;
	for(int i=1; i<n; i++)
		cout<<"(";
	for(int i=1; i<=n; i++){
		A(i);
		cout<<"+"<<n-i+1;
		if(i!=n)
			cout<<")";
	}
	cout<<endl;
	system("pause");
	return 0;
}
