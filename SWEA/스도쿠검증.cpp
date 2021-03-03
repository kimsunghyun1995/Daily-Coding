#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;



int map[9][9];


void init() {
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			map[i][j] = 0;
		}
	}

}

bool check_arr(int startX, int startY) {

	int num[10] = { 0, };
	//printf("x = %d y= %d\n", startX, startY);

	for (int i = startX; i < startX+3; i ++)
	{
		for (int j = startY; j < startY+3; j ++)
		{
			num[map[i][j]]++;
			if (num[map[i][j]] > 1)
				return false;
		}
	}
	return true;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				scanf("%d", &map[i][j]);
			}
		}

		bool flag = true;

		for (int i = 0; i < 9; i++)
		{
			int num[10] = { 0, };
			for (int j = 0; j < 9; j++)
			{
				num[map[i][j]]++;
				num[map[j][i]]++;
				if (num[map[i][j]] > 2 || num[map[j][i]]> 2)
				{
					flag = false;
					break;
				}
			}
		/*	for (int i = 1; i < 10; i++)
			{
				printf("%d ", num[i]);
			}
			printf("\n");*/

			if (!flag)
				break;
		}

		if (flag)
		{
			for (int i = 0; i < 9; i+=3)
			{
				for (int j = 0; j < 9; j+=3)
				{
					if (!check_arr(i, j))
					{
						flag = false;
						break;
					}
				}
				if (!flag)
					break;
			}
		}

		printf("#%d %d\n", test_case,flag);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}