#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<climits>
#include<string.h>
#include<queue>
using namespace std;



int N, X;
int map[20][20];

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{

		scanf("%d %d", &N, &X);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				scanf("%d", &map[i][j]);
			}
		}

		int result = 0;
		//가로부터
		for (int i = 0; i < N; i++)
		{
			bool flag = false;
			bool check[20] = { 0, };
			for (int j = 0; j < N - 1; j++)
			{
				// 너무 낮거나 너무 높거나
				if (map[i][j] +1 < map[i][j+1] || map[i][j] -1 > map[i][j+1])
				{
					flag = true;
					break;
				}
				//높은경우
				if (map[i][j] + 1 == map[i][j + 1])
				{
					int base = map[i][j];
					check[j] = true;
					for (int k = j-1; k >= j + 1 - X; k--)
					{
						if (k < 0 || check[k] || base != map[i][k])
						{
							flag = true;
							break;
						}
						else
							check[k] = true;
					}
				}

				//낮은경우
				if (map[i][j] -1 == map[i][j + 1])
				{
					int base = map[i][j+1]; //3
					check[j + 1] = true;
					for (int k = j+2; k <= j+X; k++)
					{
						if (k > N - 1|| check[k] || base != map[i][k])
						{
							flag = true;
							break;
						}
						else
							check[k] = true;
					}
				}
				if (flag)
					break;
			}

			if (!flag)
				result++;
		}


		//세로
		for (int i = 0; i < N; i++)
		{
			bool flag = false;
			bool check[20] = { 0, };

			for (int j = 0; j < N - 1; j++)
			{
				// 너무 낮거나 너무 높거나
				if (map[j][i] + 1 < map[j+1][i] || map[j][i] - 1 > map[j+1][i])
				{
					flag = true;
					break;
				}
				//높은경우
				if (map[j][i] + 1 == map[j+1][i])
				{
					int base = map[j][i];
					check[j] = true;
					for (int k = j - 1; k >= j + 1 - X; k--)
					{
						if (k < 0 || check[k]|| base != map[k][i])
						{
							flag = true;
							break;
						}
						else
							check[k] = true;
					}
				}

				//낮은경우
				if (map[j][i] - 1 == map[j+1][i])
				{
					int base = map[j+1][i]; //3
					check[j + 1] = true;
					for (int k = j + 2; k <= j + X; k++)
					{
						if (k > N - 1 || check[k] || base != map[k][i])
						{
							flag = true;
							break;
						}
						else
							check[k] = true;
					}
				}
				if (flag)
					break;
			}
			if (!flag)
				result++;
		}

		printf("#%d %d\n", test_case, result);
		
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}