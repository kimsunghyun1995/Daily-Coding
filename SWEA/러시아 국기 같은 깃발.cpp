#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<climits>
using namespace std;

int N, M;
char map[50][50];

int minValue;

void init()
{
	minValue = INT_MAX;

}



int changeCount(int cnt, char color) {
	int count = 0;
	for (int i = 0; i < M; i++)
	{
		if (map[cnt][i] != color)
		{
			count++;
		}
	}
	return count;
}


void DFS(int cnt,char color, int sumCount, string colorOrder) {

	if (cnt == N - 1)
	{
		if (minValue > sumCount)
			minValue = sumCount;
		//cout << colorOrder << endl;
		return;
	}
	if (minValue < sumCount) //가지치기
		return;

	if (color == 'W')
		if(cnt < N-2)
			DFS(cnt + 1, 'W',sumCount + changeCount(cnt ,'W'), colorOrder + "W ");

	if (color == 'B')
		DFS(cnt + 1, 'R', sumCount + changeCount(cnt , 'R'), colorOrder + "R ");

	if(color == 'R')
		DFS(cnt + 1, 'R', sumCount + changeCount(cnt , 'R'), colorOrder + "R ");
	else
		DFS(cnt + 1, 'B', sumCount + changeCount(cnt , 'B'), colorOrder + "B ");



}


int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%d %d", &N, &M);
		init();
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				cin >> map[i][j];
			}
		}
		//0번째 N-1번째는 고정
		DFS(1, 'W', 0, "");
		minValue +=changeCount(0,'W');
		minValue += changeCount(N-1,'R');
		printf("#%d %d\n",test_case, minValue);

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}