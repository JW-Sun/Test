// �ʺ��㷨.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "math.h"
#include <malloc.h>
#include "iostream"
using namespace std;

int *po;          //�������������õ�λ�ã�p=po[i]:��i�еĻʺ��ڵ�p��
int queens;//�ʺ����Ŀ
int count = 0;//�ڼ��ֿ�����


//�жϵ�n���Ƿ�Żʺ�
bool signpoint(int n)
{
	for (int i = 0; i < n; i++)
	{
		if (po[i] == po[n])//�����Ѿ��Ź��ʺ�
			return false;
		if (abs(po[i] - po[n]) == n - i)//�Խ����Ѿ�������
			return false;
	}
	return true;
}

void setqueen(int n = 0)//�ӵ�n�п�ʼ���ûʺ�
{

	if (queens == n)//�����ͬ����ʾ���е������һ�У���������
	{
		cout << "No."<< endl;
		for (int i = 0; i < queens; i++)
		{
			for (int j = 0; j < queens; j++)
			{
				if (j == po[i])
				{
					cout << j;//����������ڵ���po�д洢�������ͽ����������
				}
				else
				{
					cout << "*";//�������*��ʾ���Żʺ�
				}
			}
			cout << endl;
		}
		for (int t = 0; t < queens; t++)//���po��ֵ	
		{
			cout << "po[" << t << "]=" << po[t] << endl;
		}
		cout << endl;
		return;
	}
	else
	{
		for (int i = 0; i < queens; i++)//׼�����ʺ���ڵ�i��
		{
			po[n] = i;
			if (signpoint(n))//�����������ȷ��
			{
				setqueen(n + 1);
			}
		}
	}

}

int _tmain(int argc, _TCHAR* argv[])
{
	int count = 0;
	cout << "������ʺ��������" << endl;
	cin >> queens;
	po = new int[queens];
	setqueen();
	cout << "�ڷ����" << endl;
	return 0;
	system("pause");
}

