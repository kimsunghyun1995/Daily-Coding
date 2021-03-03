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

	//현재 가장 큰 수 찾고 swap
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

// 횟수만큼 교환이 반드시 일어져야함
// 최대 자릿수는 6자리이며, 최대 교환 횟수는 10번이다.

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
		dfsNum(0,0); //cnt와 현재 최댓값 시점

		if (maxValue == 0)
			maxValue = temp;


		int result = switchCntMax - switchCnt;

		if (result != 0)		//아직 횟수가 남았다면
		{
			if ((result % 2) != 0) // 홀수면
			{
				string temp = "";
				temp = to_string(maxValue);
				swap(temp[temp.size() - 1], temp[temp.size() - 2]);
				maxValue = stoi(temp);
			}
		}

		printf("#%d %d\n", test_case, maxValue);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}