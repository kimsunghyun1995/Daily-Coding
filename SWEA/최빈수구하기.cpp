#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<climits>
using namespace std;




int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int dump = 0;
		int arr[101] = {0,};
		scanf("%d", &dump);
		for (int i = 0; i < 1000; i++)
		{
			int score = 0;
			scanf("%d", &score);
			arr[score]++;
		}

		int maxValue = 0;
		int maxIdx = 0;

		for (int i = 0; i < 101; i++)
		{
			if (arr[i] >= maxValue)
			{
				maxValue = arr[i];
				maxIdx = i;
			}
		}

		printf("#%d %d\n", test_case, maxIdx);

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}