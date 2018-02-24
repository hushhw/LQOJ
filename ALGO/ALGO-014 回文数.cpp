/*
算法训练 回文数 
时间限制：1.0s 内存限制：256.0MB 
提交此题 锦囊1 锦囊2 
问题描述 
　　若一个数（首位不为零）从左向右读与从右向左读都一样，我们就将其称之为回文数。 
  　例如：给定一个10进制数56，将56加65（即把56从右向左读），得到121是一个回文数。

	又如：对于10进制数87： 
	STEP1：87+78 = 165 STEP2：165+561 = 726 
	STEP3：726+627 = 1353 STEP4：1353+3531 = 4884

	在这里的一步是指进行了一次N进制的加法，上例最少用了4步得到回文数4884。

	写一个程序，给定一个N（2<=N<=10或N=16）进制数M（其中16进制数字为0-9与A-F），求最少经过几步可以得到回文数。 
	如果在30步以内（包含30步）不可能得到回文数，则输出“Impossible!” 
输入格式 
	两行，N与M 
输出格式 
	如果能在30步以内得到回文数，输出“STEP=xx”（不含引号），其中xx是步数；否则输出一行”Impossible!”（不含引号） 
样例输入 
	9 
	87 
样例输出 
	STEP=6
*/

#include <iostream>  
#include <string>
#include <cstring>  
using namespace std;  
int a[10000],b[10000],s[10001];  

bool huiwen(int s[], int l)  
{  
	int i,k;  
	k = (l - 1)/2;  
	for(i = 0; i <= k; i++)  
	{  
		if(s[i] != s[l - i -1])  
			break;  
	}  
	if(i == k+1)  
		return 1;  
	else  
		return 0;  
}  

void inverse(int s[], int l)  
{  
	int i;  
	memset(a, 0, sizeof(a));  
	memset(b, 0, sizeof(b));  
	for(i = 0; i < l; i++)  
	{  
		a[i] = s[i];  
		b[l - i -1] = a[i];  
	}  
}  

int main()  
{  
	int n,l,i,count = 0;  
	string m;  
	cin>>n>>m;  
	l = m.size();  
	for(i = 0; i < l; i++)  
	{  
		//输入的字符串（因为要输入A,B……）转为数字存入a数组
		if(m[i] >= 'A' && m[i] <= 'Z')  
			a[i] = m[i] - 'A' + 10;  
		else  
			a[i] = m[i] - '0';  
		s[i] = a[i];  //初始化s数组为a数组
		b[l - i -1] = a[i];  //b数组倒序存储a数组的元素
	}  

	while(!huiwen(s, l) && count <= 30)  //判断s数组是否为回文或操作是否小于30
	{  
		count++;  //每次操作都增加一次
		memset(s, 0, sizeof(s));  
		for(i = 0; i < l; i++)  //把a,b数组各项相加的数据存在s数组中，模拟题目操作，在进行相应判断
		{  
			s[i] += a[i] + b[i];  
			s[i+1] += s[i]/n;  //进位
			s[i] = s[i]%n;  
		}  
		if(s[l] != 0)  //若最高为有进位，则增加一位
			l = l + 1;  
		inverse(s, l); //更新a,b数组 
	}  
	if(count <= 30)  
		cout<<"STEP="<<count<<endl;  
	else  
		cout<<"Impossible!"<<endl;  

	return 0;  
}  