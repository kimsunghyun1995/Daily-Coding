#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<climits>
using namespace std;



bool result;
bool check[21][21][4][16];
int N, M;
char map[21][21];
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

void init()
{
	result = false;
	for (int i = 0; i < 21; i++)
	{
		for (int j = 0; j < 21; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				for (int c = 0; c < 16; c++)
				{
					check[i][j][k][c] = false;
				}
			}
		}
	}


	for (int i = 0; i < 21; i++)
	{
		for (int j = 0; j < 21; j++)
		{
			map[i][j] = 0;
		}
	}
}


void DFS(int y, int x, int direc, int memoryValue)
{
	if (result)
		return;
	printf("%d %d %d %d  ", y, x, direc, memoryValue);
	switch (map[y][x])
	{
	case '<':
		direc = 2;
		break;
	case '>':
		direc = 3;
		break;
	case '^':
		direc = 0;
		break;
	case 'v':
		direc = 1;
		break;
	case '_':
		if (memoryValue == 0)
			direc = 3;
		else
			direc = 2;
		break;
	case '|':
		if (memoryValue == 0)
			direc = 1;
		else
			direc = 0;
		break;
	case '?':
		for (int i = 0; i < 4; i++)
		{
			int ry = y + dir[i][0];
			int rx = x + dir[i][1];

			if (ry > N - 1)
				ry -= N;
			if (ry < 0)
				ry += N;
			if (rx > M - 1)
				rx -= M;
			if (rx < 0)
				rx += M;

			if (!check[ry][rx][i][memoryValue])
			{
				check[ry][rx][i][memoryValue] = true;
				DFS(ry, rx, i, memoryValue);
			}
		}

		break;
	case '.':
		break;
	case '@':
		result = true;
		return;
		break;
	case '+':
		if (memoryValue == 15)
			memoryValue = 0;
		else
			memoryValue++;
		break;
	case '-':
		if (memoryValue == 0)
			memoryValue = 15;
		else
			memoryValue--;
		break;
	default:
		memoryValue = map[y][x] - '0';
		break;
	}

	int ny = dir[direc][0] + y;
	int nx = dir[direc][1] + x;

	if (ny > N - 1)
		ny -=N;
	if (ny < 0)
		ny += N;
	if (nx > M - 1)
		nx -= M;
	if (nx < 0)
		nx += M;

	printf("%d %d %d %d\n", ny, nx, direc, memoryValue);

	if (!check[ny][nx][direc][memoryValue])
	{
		check[ny][nx][direc][memoryValue] = true;
		DFS(ny, nx, direc, memoryValue);
		check[ny][nx][direc][memoryValue] = false;
	}
}

//종료조건은 @만나거나 무한루프거나
//무한루프인경우 갈곳이없으면 종료
// DFS로 해결 check [y][x][dir][문자메모리]


int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		init();
		scanf("%d %d", &N, &M);
		int cnt = 0;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				cin >> map[i][j];
				if (map[i][j] == '@')
					cnt++;
			}
		}

		if (cnt != 0)
			DFS(0, 0, 3, 0);

		if (result)
			printf("#%d YES\n", test_case);
		else
			printf("#%d NO\n", test_case);

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}