#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<climits>
using namespace std;

int N, M;
int map[50][100];


int calCode(string code) {

	int a_sum = 0, b_sum = 0;
	int result = 0;
	for (int i = 1; i < 8; i++)
	{
		if (i % 2 == 0) // 짝수면
		{
			a_sum += code[i - 1] - '0';
		}
		else // 홀수면 짝수임
		{
			b_sum += code[i - 1] - '0';
		}
		result += code[i - 1] - '0';
	}

	result += code[7] - '0';

	int sum = b_sum * 3 + a_sum + code[7] - '0';
	if (sum % 10 == 0)
		return result;
	else
		return 0;
}

string findCode()
{
	string code = "";
	for (int i = 0; i < N; i++)
	{
		for (int j = M - 1; j > -1; j--)
		{
			if (map[i][j] == 1)
			{
				for (int k = j-55; k <= j; k++)
				{
					code += to_string(map[i][k]);
				}
				i = N - 1;
				break;
			}
		}
	}

	return code;

}

string binaryToCode(string binaryCode) {
	string code="";
	for (int i = 0; i < binaryCode.size(); i+=7)
	{
		if (binaryCode.substr(i, 7) == "0001101")
			code += "0";
		else if (binaryCode.substr(i, 7) == "0011001")
			code += "1";
		else if (binaryCode.substr(i, 7) == "0010011")
			code += "2";
		else if (binaryCode.substr(i, 7) == "0111101")
			code += "3";
		else if (binaryCode.substr(i, 7) == "0100011")
			code += "4";
		else if (binaryCode.substr(i, 7) == "0110001")
			code += "5";
		else if (binaryCode.substr(i, 7) == "0101111")
			code += "6";
		else if (binaryCode.substr(i, 7) == "0111011")
			code += "7";
		else if (binaryCode.substr(i, 7) == "0110111")
			code += "8";
		else if (binaryCode.substr(i, 7) == "0001011")
			code += "9";
	}
	return code;
}

int solution() {

	string binaryCode = findCode();
	string code = binaryToCode(binaryCode);
	return calCode(code);
}



int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%d %d", &N, &M);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				scanf("%1d", &map[i][j]);
			}
		}
		printf("#%d %d\n", test_case, solution());
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}