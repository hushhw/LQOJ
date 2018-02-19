/*
问题描述
　　输入一个正整数n，输出n!的值。
  　　其中n!=1*2*3*…*n。
	算法描述
	　n!可能很大，而计算机能表示的整数范围有限，需要使用高精度计算的方法。使用一个数组A来表示一个大整数a，A[0]表示a的个位，A[1]表示a的十位，依次类推。
	  将a乘以一个整数k变为将数组A的每一个元素都乘以k，请注意处理相应的进位。
	  首先将a设为1，然后乘2，乘3，当乘到n时，即得到了n!的值。
输入格式
	输入包含一个正整数n，n<=1000。
输出格式
	输出n!的准确值。
样例输入
	10
样例输出
	3628800
*/

#include <iostream>
#include <string>
#define N 1001
using namespace std;

int main(){
	int n;
	int i, j;
	int a[N];		//用来存储结果，每一位对应一位数字
	int w=0;		//用来判断是否有进位
	int t;			//存储十位数字

	cin>>n;
	memset(a, 0, sizeof(a));
	a[0]=1;

	for(i=1; i<=n; i++){
		for(j=0; j<=w; j++){
			if(j==0){
				t=a[j]*i;
				a[j]=t%10;		//用a[j]保存每一次相乘后的个位数
				t=t/10;			//t保存相乘后的十位数
				if(j==w && t>0)	//w控制是否有进位，如果t>0说明进位了，则w++
					w++;
				cout<<"a[j]="<<a[j]<<endl;
				cout<<"t="<<t<<endl;
			}else{
				t=a[j]*i+t;
				a[j]=t%10;
				t=t/10;
				if(j==w && t>0)
					w++;
				cout<<"a[j]="<<a[j]<<endl;
				cout<<"t="<<t<<endl;
			}
		}
	}
	for(i=w; i>=0; i--)
		cout<<a[i];
	cout<<endl;
	system("pause");
	return 0;
}

/*
int main(){
	int n;
	cin>>n;
	int A[10000] = {1};
	for(int i=1; i<=n; i++){
		for(int j=0; j<10000; j++){
			A[j] = A[j]*i;
		}
		for(int j=0; j<10000; j++){
			if(A[j]>=9){
				A[j+1] = A[j+1] + A[j]/10;
				A[j] = A[j]%10;
			}
		}
	}
	int t=0;
	for(int i=9999; i>=0; i--){
		if(A[i]!=0){
			t=i;
			break;
		}
	}
	for(int i=t; i>=0; i--)
		cout<<A[i];
	system("pause");
	return 0;
}
*/