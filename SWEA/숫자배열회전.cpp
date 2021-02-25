#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<climits>
using namespace std;

int N;
int map[7][7];
int mapTemp[7][7];
string result[7];



void writeResult() {
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			result[i] += to_string(mapTemp[i][j]);
		}
		result[i] += " ";
	}
}

void copyArr() {
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			mapTemp[i][j] = map[i][j];
		}
	}
}

void rotation90()
{
	int temp[7][7];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			temp[i][j] = mapTemp[N - 1 - j][i];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			mapTemp[i][j] = temp[i][j];
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
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
		{
			result[i] = "";
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				int value = 0;
				scanf("%d", &value);
				map[i][j] = value;
			}
		}

		copyArr();
		rotation90();
		writeResult();
		copyArr();
		for (int i = 0; i < 2; i++)
			rotation90();
		writeResult();
		copyArr();
		for (int i = 0; i < 3; i++)
			rotation90();
		writeResult();

		printf("#%d\n", test_case);
		for (int i = 0; i < N; i++)
		{
			cout << result[i] << "\n";
		}
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}





