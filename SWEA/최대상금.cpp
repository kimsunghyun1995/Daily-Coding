#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<climits>
using namespace std;


int maxValue;
int switchCntMax;
string num;
int switchCnt;
bool check[6];


void init() {
	maxValue = 0;
	num = "";
	switchCnt = 0;
	check[6] = { 0, };
}


void dfsNum(int cnt, int currentNum) {
	switchCnt =max(switchCnt,cnt);
	if (cnt == switchCntMax)
	{
		maxValue = max(maxValue, stoi(num));
		return;
	}

	//���� ���� ū �� ã�� swap
	for (int i = currentNum; i < num.size(); i++)
	{
		for (int j = i+1; j < num.size(); j++)
		{
			if (num[i] <= num[j])
			{
				swap(num[i], num[j]);
				dfsNum(cnt + 1, i);
				swap(num[i], num[j]);
			}
		}
	}



}

// Ƚ����ŭ ��ȯ�� �ݵ�� �Ͼ�������
// �ִ� �ڸ����� 6�ڸ��̸�, �ִ� ��ȯ Ƚ���� 10���̴�.

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		init();
		int temp = 0;
		scanf("%d %d", &temp, &switchCntMax);
		num = to_string(temp);
		dfsNum(0,0); //cnt�� ���� �ִ� ����

		if (maxValue == 0)
			maxValue = temp;


		int result = switchCntMax - switchCnt;

		if (result != 0)		//���� Ƚ���� ���Ҵٸ�
		{
			if ((result % 2) != 0) // Ȧ����
			{
				string temp = "";
				temp = to_string(maxValue);
				swap(temp[temp.size() - 1], temp[temp.size() - 2]);
				maxValue = stoi(temp);
			}
		}

		printf("#%d %d\n", test_case, maxValue);
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}