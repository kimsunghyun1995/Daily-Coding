#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<climits>
#include<string.h>
using namespace std;



int N;
int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int board[10][10];


void init() {
	memset(board, 0,sizeof(board));
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		init();
		scanf("%d", &N);
		int y = 0;
		int x = 0;
		int direc = 0;
		int num = 1;
		while (num <= N*N)
		{
			board[y][x] = num++;
			int ny = y+ dir[direc][0];
			int nx = x+ dir[direc][1];

			if (ny < 0 || nx < 0 || ny >N - 1 || nx>N - 1 || board[ny][nx] != 0)
			{
				if (direc == 3)
					direc = 0;
				else
					direc++;
				y += dir[direc][0];
				x += dir[direc][1];
			}
			else
			{
				x = nx;
				y = ny;
			}
		}
		printf("#%d\n", test_case);

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				printf("%d ", board[i][j]);
			}
			printf("\n");
		}

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}