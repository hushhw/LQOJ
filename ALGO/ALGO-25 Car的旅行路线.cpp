/*
ALGO-25	VIP试题 Car的旅行路线	最短路

描述
又到暑假了，住在城市A的Car想和朋友一起去城市B旅游。
她知道每个城市都有四个飞机场，分别位于一个矩形的四个顶点上，同一个城市中两个机场之间有一条笔直的高速铁路，
第I个城市中高速铁路了的单位里程价格为Ti，任意两个不同城市的机场之间均有航线，所有航线单位里程的价格均为t。
                                                                                                       
那么Car应如何安排到城市B的路线才能尽可能的节省花费呢?
她发现这并不是一个简单的问题，于是她来向你请教。找出一条从城市A到B的旅游路线，出发和到达城市中的机场可以任意选取，要求总的花费最少。

格式
输入格式
第一行有四个正整数s，t，A，B。
S(0<S<=100)表示城市的个数，t表示飞机单位里程的价格，A，B分别为城市A，B的序号，(1<=A，B<=S)。

接下来有S行，其中第I行均有7个正整数xi1，yi1，xi2，yi2，xi3，yi3，Ti，
这当中的(xi1，yi1)，(xi2，yi2)，(xi3，yi3)分别是第I个城市中任意三个机场的坐标，T I为第I个城市高速铁路单位里程的价格。

输出格式
输出最小费用(结果保留两位小数)

样例1
样例输入1
3 10 1 3
1 1 1 3 3 1 30
2 5 7 4 5 2 1
8 6 8 8 11 6 3
样例输出1
47.55

*/

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

const int MAXN = 1111;
const int MAXS = 111;
const int INF = 0x3f3f3f3f;

struct city
{
	int x[4], y[4];
	int t;
} C[MAXS];

int s, t, A, B;
double cost[MAXN][MAXN];
double lowcost[MAXN][MAXN];

double getCost(int x1, int y1, int x2, int y2, int t)
{
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)) * t;
}

void Floyd(int n)
{
	memcpy(lowcost, cost, sizeof(cost));
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (lowcost[i][j] > lowcost[i][k] + lowcost[k][j])
				{
					lowcost[i][j] = lowcost[i][k] + lowcost[k][j];
				}
			}
		}
	}
}

void get_fourth_node(int x1, int y1, int x2, int y2, int x3, int y3, int &x4, int &y4)
{
	if ((x1 - x2) * (x3 - x2) + (y1 - y2) * (y3 - y2) == 0)
	{
		swap(x1, x2);
		swap(y1, y2);
	}
	else if ((x1 - x3) * (x2 - x3) + (y1 - y3) * (y2 - y3) == 0)
	{
		swap(x1, x3);
		swap(y1, y2);
	}
	x4 = x2 + x3 - x1;
	y4 = y2 + y3 - y1;
}

int main(int argc, const char * argv[])
{
	memset(cost, 0x3f, sizeof(cost));

	cin >> s >> t >> A >> B;
	if (A == B)
	{
		printf("0.0\n");
		return 0;
	}
	for (int i = 0; i < s; i++)
	{
		cin >> C[i].x[0] >> C[i].y[0];
		cin >> C[i].x[1] >> C[i].y[1];
		cin >> C[i].x[2] >> C[i].y[2];
		cin >> C[i].t;
		get_fourth_node(C[i].x[0], C[i].y[0], C[i].x[1], C[i].y[1], C[i].x[2], C[i].y[2], C[i].x[3], C[i].y[3]);

		for (int j = 0; j < 4; j++)
		{
			for (int k = j + 1; k < 4; k++)
			{
				cost[i * 4 + j][i * 4 + k] = cost[i * 4 + k][i * 4 + j] =
					getCost(C[i].x[j], C[i].y[j], C[i].x[k], C[i].y[k], C[i].t);
			}
		}
	}

	for (int i = 0; i < s; i++)
	{
		for (int j = i + 1; j < s; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				for (int l = 0; l < 4; l++)
				{
					cost[i * 4 + k][j * 4 + l] = cost[j * 4 + l][i * 4 + k] =
						getCost(C[i].x[k], C[i].y[k], C[j].x[l], C[j].y[l], t);
				}
			}
		}
	}

	Floyd(4 * s);

	double res = INF;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			res = min(res, lowcost[A * 4 - 4 + i][B * 4 - 4 + j]);
		}
	}

	printf("%.1f\n", res);

	return 0;
}