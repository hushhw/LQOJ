/*
算法训练 摆动序列 
	时间限制：1.0s 内存限制：512.0MB 
	提交此题 锦囊1 锦囊2 
问题描述 
　　如果一个序列满足下面的性质，我们就将它称为摆动序列： 
  　1. 序列中的所有数都是不大于k的正整数； 
	2. 序列中至少有两个数。 
	3. 序列中的数两两不相等； 
	4. 如果第i – 1个数比第i – 2个数大，则第i个数比第i – 2个数小；如果第i – 1个数比第i – 2个数小，则第i个数比第i – 2个数大。 
	比如，当k = 3时，有下面几个这样的序列： 
	1 2 
	1 3 
	2 1 
	2 1 3 
	2 3 
	2 3 1 
	3 1 
	3 2 
	一共有8种，给定k，请求出满足上面要求的序列的个数。 

输入格式 
	输入包含了一个整数k。（k<=20） 

输出格式 
	输出一个整数，表示满足要求的序列个数。 

样例输入 
	3 

样例输出 
	8
*/

#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
 
/*
int main()  
{  
	int k;  
	scanf("%d", &k);  
	printf("%d", (int)(pow(2, k) - k - 1) * 2);  
	return 0;  
}  
*/

int main()    
{    
	int k;    
	int a[21][21];    
	long sum = 0;    
	cin>>k;    
	for(int i = 2; i <= k; i++){    
		a[i][i] = 2;    
		a[i][2] = i*(i-1);    
		for(int j = 3; j < i; j++){    
			a[i][j] = a[i-1][j]+a[i-1][j-1];    
		}    
	}    
	for(int i = 2; i <= k; i++){    
		sum += a[k][i];    
	}    
	cout<<sum<<endl;   
	system("pause");
	return 0;       
}