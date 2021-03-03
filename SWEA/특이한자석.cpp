#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<climits>
#include<string.h>
#include<queue>
using namespace std;

int K;


int roll[4][8];

bool check[4];

void rotate(int num,int dir)
{
	if (dir == 1)
	{
		int temp = roll[num][7];
		for (int i = 7; i > 0; i--)
			roll[num][i] = roll[num][i - 1];
		roll[num][0] = temp;
	}
	else
	{
		int temp = roll[num][0];
		for (int i = 0; i <7; i++)
			roll[num][i] = roll[num][i + 1];
		roll[num][7] = temp;
	}
}


void rotateRoll(int num, int dir) {
	//4가지 경우
	check[num] =true;

	if (num == 0)
	{
		if (!check[num + 1] && roll[num][2] != roll[num + 1][6])
		{
			rotateRoll(num + 1, dir*-1);
		}
	}
	else if (num == 1)
	{
		if (!check[num-1] && roll[num][6] != roll[num-1][2])
			rotateRoll(num-1, dir*-1);
		if (!check[num+1] && roll[num][2] != roll[num+1][6])
			rotateRoll(num+1, dir*-1);
	}
	else if (num == 2)
	{
		if (!check[num - 1] && roll[num][6] != roll[num - 1][2])
			rotateRoll(num-1, dir*-1);
		if (!check[num + 1] && roll[num][2] != roll[num + 1][6])
			rotateRoll(num+1, dir*-1);
	}
	else if (num == 3)
	{
		if (!check[num-1] && roll[num][6] != roll[num-1][2])
			rotateRoll(num-1, dir*-1);
	}
	rotate(num, dir);
}

int calScore() {
	int result = 0;
	int score = 1;
	for (int i = 0; i < 4; i++)
	{
		if (roll[i][0] == 1)
			result += score;
		score *= 2;
	}
	return result;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%d", &K);
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				scanf("%d",&roll[i][j]);
			}
		}

		for (int i = 0; i < K; i++)
		{
			int num = 0, dir = 0;
			scanf("%d %d", &num, &dir);
			rotateRoll(num - 1, dir);
			memset(check, 0, sizeof(check));

			/*for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					printf("%d ", roll[i][j]);
				}
				printf("\n");
			}*/
		}

		printf("#%d %d\n", test_case, calScore());
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}