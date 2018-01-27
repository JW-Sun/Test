// 皇后算法.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "math.h"
#include <malloc.h>
#include "iostream"
using namespace std;

int *po;          //用来存放数组放置的位置，p=po[i]:第i行的皇后在第p列
int queens;//皇后的数目
int count = 0;//第几种可能性


//判断第n行是否放皇后
bool signpoint(int n)
{
	for (int i = 0; i < n; i++)
	{
		if (po[i] == po[n])//这列已经放过皇后
			return false;
		if (abs(po[i] - po[n]) == n - i)//对角线已经放置了
			return false;
	}
	return true;
}

void setqueen(int n = 0)//从第n列开始放置皇后
{

	if (queens == n)//如果相同，表示排列到了最后一列，将结果输出
	{
		cout << "No."<< endl;
		for (int i = 0; i < queens; i++)
		{
			for (int j = 0; j < queens; j++)
			{
				if (j == po[i])
				{
					cout << j;//如果列数等于等于po中存储的列数就将该列数输出
				}
				else
				{
					cout << "*";//否则输出*表示不放皇后
				}
			}
			cout << endl;
		}
		for (int t = 0; t < queens; t++)//输出po的值	
		{
			cout << "po[" << t << "]=" << po[t] << endl;
		}
		cout << endl;
		return;
	}
	else
	{
		for (int i = 0; i < queens; i++)//准备将皇后放在第i行
		{
			po[n] = i;
			if (signpoint(n))//如果放置是正确的
			{
				setqueen(n + 1);
			}
		}
	}

}

int _tmain(int argc, _TCHAR* argv[])
{
	int count = 0;
	cout << "请输入皇后的数量：" << endl;
	cin >> queens;
	po = new int[queens];
	setqueen();
	cout << "摆放完毕" << endl;
	return 0;
	system("pause");
}

