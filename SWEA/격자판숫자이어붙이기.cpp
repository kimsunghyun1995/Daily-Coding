#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<climits>
#include<string.h>
#include<queue>
#include<set>
using namespace std;

int map[4][4];
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
set<string> v;

void BFS(int startX,int startY)
{
	queue < pair<pair<int, int>, string>> q;
	q.push(make_pair(make_pair(startY, startX), to_string(map[startY][startX])));
	
	while (!q.empty())
	{
		int y = q.front().first.first;
		int x = q.front().first.second;
		string word = q.front().second;
		q.pop();

		if (word.size() == 7)
			v.insert(word);
		else
		{
			for (int i = 0; i < 4; i++)
			{
				int ny = y + dir[i][0];
				int nx = x + dir[i][1];
				if (ny < 4 && nx < 4 && ny > -1 && nx > -1)
				{
					string a = to_string(map[ny][nx]);
					q.push(make_pair(make_pair(ny, nx), word + a));
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
		v.clear();
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				scanf("%d", &map[i][j]);
			}
		}

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				BFS(i, j);
			}
		}
		//sort(v.begin(), v.end());
		//v.erase(unique(v.begin(), v.end()), v.end());
		printf("#%d %d\n", test_case,v.size());

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}