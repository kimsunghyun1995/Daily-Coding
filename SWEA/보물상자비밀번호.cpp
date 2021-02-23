#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

char arr[28];
vector<string> list;
int N, K, divNum;

void init() {
	list.clear();
	divNum = N / 4;
}

bool cmp(string i, string j) {
	return i > j;
}



void roatation() {
	int temp = arr[N-1];
	for (int i = N-1; i > 0 ; i--)
		arr[i] = arr[i - 1];
	arr[0] = temp;
}

void checkNum()
{

	int idx = 0;
	while(idx < N)
	{
		int count = 0;
		string num = "";
		while (count++ < divNum)
		{
			num += arr[idx++];
		}
		list.push_back(num);
	}
}



int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%d %d", &N, &K);
		init();
		for (int i = 0; i < N; i++)
		{
			cin >> arr[i];
		}
		for (int idx = 0; idx <N/4 ; idx++)
		{
			checkNum();
			roatation();
		}

		sort(list.begin(), list.end(), cmp);
		//중복제거
		list.erase(unique(list.begin(), list.end()), list.end());
		string answer = list[K-1];
		//변환
		int sum = 0;
		int binary = 1;
		for (int i = divNum-1; i > -1; i--)
		{
			int num = 0;
			switch (answer[i])
			{
			case 'A':
				num = 10;
				break;
			case 'B':
				num = 11;
				break;
			case 'C':
				num = 12;
				break;
			case 'D':
				num = 13;
				break;
			case 'E':
				num = 14;
				break;
			case 'F':
				num = 15;
				break;
			default:
				num = answer[i] - '0';
				break;
			}
			sum += num* binary;
			binary *= 16;
		}

		printf("#%d %d\n", test_case, sum);

	}
	return 0;
}