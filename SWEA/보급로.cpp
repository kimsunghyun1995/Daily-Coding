#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<climits>
#include<string.h>
#include<queue>
using namespace std;



//생각나는 방법
//BFS PQ 와 DP




int board[100][100];
int N;
int dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
int check[100][100];

void init()
{
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			check[i][j] = 100000;
		}
	}
}

struct compare
{
	bool operator()(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
	{
		return a.second > b.second;
	}
};


void BFS()
{
	priority_queue<pair<pair<int, int>,int>,vector<pair<pair<int, int>, int>>, compare> pq;
	pq.push(make_pair(make_pair(0, 0), 0));

	while (!pq.empty())
	{
		int y = pq.top().first.first;
		int x = pq.top().first.second;
		int value = pq.top().second;
		if (y == N - 1 && x == N - 1)
			break;
		pq.pop();

		//printf("y= %d x = %d value = %d\n",y,x ,value);

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dir[i][1];
			int ny = y + dir[i][0];

			if (ny < N && nx < N && ny > -1 && nx >-1)
			{
				int nValue = value + board[ny][nx];
				//printf("nValue = %d\n", nValue);

				if (check[ny][nx] > nValue)
				{
					check[ny][nx] = nValue;
					pq.push(make_pair(make_pair(ny, nx), nValue));
				}
			}
		}

	}


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
		{
			for (int j = 0; j < N; j++)
			{
				scanf("%1d", &board[i][j]);
			}
		}

		BFS();
		/*for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				printf("%d ", check[i][j]);
			}
			printf("\n");
		}*/


		printf("#%d %d\n", test_case, check[N - 1][N - 1]);

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}