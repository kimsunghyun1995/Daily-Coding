#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<vector>
#include<limits>
#include<queue>
using namespace std;

//이중포문 돌리면서 체크 안된 버튼 클릭
//BFS사용해서 최대한 넓혀줌

int dir[8][2] = { {-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1} };
int N;
char board[301][301];
int newBoard[301][301];
bool check[301][301];
int minClickCount;

void init() {
	for (int i = 0; i <= 300; i++)
		for (int j = 0; j <= 300; j++)
		{
			newBoard[i][j] = -1;
			check[i][j] = false;
		}
	minClickCount = 0;
}


void printBoard()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%d ", newBoard[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%d ", check[i][j]);
		}
		printf("\n");
	}

}


void BFS(int sy, int sx)
{
	queue<pair<int, int>> q;
	q.push(make_pair(sy, sx));
	check[sy][sx] = true;

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++)
		{
			int ny = y + dir[i][0];
			int nx = x + dir[i][1];

			if (ny < N && nx < N && ny > -1 && nx > -1 && !check[ny][nx])
			{
				check[ny][nx] = true;
				if (newBoard[ny][nx] == 0)
					q.push(make_pair(ny, nx));
			}
		}

	}
}

void createNewBoard()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int count = 0;
			if (board[i][j] != '*')
			{
				for (int k = 0; k < 8; k++)
				{
					int ny = i + dir[k][0];
					int nx = j + dir[k][1];
					if (ny < N && nx < N && ny > -1 && nx > -1)
					{
						if (board[ny][nx] == '*')
							count++;
					}
				}
				newBoard[i][j] = count;
			}
		}
	}
}

void solve() {
	createNewBoard();
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!check[i][j] && newBoard[i][j] == 0)
			{
				minClickCount++;
				BFS(i, j);
			}
		}
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (!check[i][j])
				minClickCount++;
	//printBoard();
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
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
			{
				char s;
				cin >> s;
				if (s == '*')
					check[i][j] = 1;
				board[i][j] = s;
			}
		solve();
		printf("#%d %d\n",test_case,minClickCount);

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}