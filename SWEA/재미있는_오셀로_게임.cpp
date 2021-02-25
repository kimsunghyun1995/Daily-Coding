#define _CRT_SECURE_NO_WARNINGS 
#define WHITE 2
#define BLACK 1

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;



int N, M;
int map[8][8];
int dir[8][2] = { {-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1} };
//1�浹 2�鵹

void printmap() {
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%d",map[i][j]);
		}
		cout << "\n";
	}
	cout << "\n";
}


void init() {
	for (int i = 0; i < N; i++)
	{
		for (int j= 0; j < N; j++)
		{
			map[i][j] = 0;
		}
	}
	int center = N / 2 - 1;
	map[center][center] = WHITE;
	map[center][center+1] = BLACK;
	map[center+1][center] = BLACK;
	map[center+1][center+1] = WHITE;
}

void changeRock(int sy,int sx,int y, int x, int color, int direction) {
	int nColor = 0;
	int nDirection = 0;

	if (direction > 3)
		nDirection = direction- 4;
	else
		nDirection = direction+ 4;

	//printf("�������� = %d �ٲ���� = %d", direction,nDirection);

	for (int i = 1; i < N; i++)
	{
		int ny = y + dir[nDirection][0] * i;
		int nx = x + dir[nDirection][1] * i;
		//printf("������ ���� = %d %d\n", ny, nx);

		if (ny == sy && nx == sx)
		{
			return;
		}
		map[ny][nx] = color;
	}

}


void checkColor(int y, int x, int color) {
	for (int i = 0; i < 8; i++)
	{
		int sy = y + dir[i][0];
		int sx = x + dir[i][1];

		if (sy < N && sx < N && sy > -1 && sx > -1)
		{
			if (map[sy][sx] != color && map[sy][sx] != 0) //color �� �ٸ����̸� Ž������
			{
				int ny = sy;
				int nx = sx;
				//printf("Ž�� ���� %d %d\n", ny, nx);

				while (true)
				{
					ny += dir[i][0];
					nx += dir[i][1];
					//printf("Ž�� ������ %d %d\n", ny, nx);

					if (ny < N && nx < N && ny > -1 && nx > -1)
					{
						if (map[ny][nx] == color && map[sy][sx] != 0)
						{
							changeRock(y, x, ny, nx, color, i);
							break;
						}
						else if (map[ny][nx] == 0)
							break;
					}
					else
						break;
				}
			}
		}


	}
}

// ���� �� ���� �� 4���� Ž�� 0,0 ����
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%d %d", &N, &M);
		init();
		int Wcnt = 0;
		int Bcnt = 0;
		for (int i = 0; i < M; i++)
		{
			int yValue = 0,xValue=0,color=0;
			scanf("%d %d %d", &xValue,&yValue,&color);
			map[yValue-1][xValue-1] = color;
			checkColor(yValue - 1, xValue - 1, color);//8���� üũ �� ��ȯ
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (map[i][j] == BLACK)
					Bcnt++;
				else if(map[i][j] == WHITE)
					Wcnt++;
			}
		}
		//printmap();
		printf("#%d %d %d\n", test_case, Bcnt, Wcnt);

	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}