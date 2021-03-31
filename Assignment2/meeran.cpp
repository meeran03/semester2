#include<iostream>
#include<fstream>

using namespace std;

void extendrw(int**& dp, int& row)
{
	int** dpnew = new int* [row + 1];
	for (int i = 0;i < row;i++)
	{
		dpnew[i] = dp[i];
	}
	delete[] dp;
	dp = dpnew;
	row += 1;
}
void extendcol(int**& dp, int row, int& col)
{

	int** dplatest = new int* [row];

	dplatest[row-1] = new int[col + 1];

	for (int i = 0;i < col;i++)
	{
		dplatest[row-1][i] = dp[row-1][i];
	}
	dp[row-1] = dplatest[row-1];
	col += 1;
}
void copyinteger(int**& dp, int* row, int col, int number)
{
	for (int i = 0;i < col;i++)
	{
		row[i] = number;
	}
}
int main()
{
	fstream read;
	int next = 0;
	int row = 1;
	int** dp = new int* [row];
	int col1 = 0;
	bool breakloop = false;
	read.open("data2.txt", ios::in);
	if (read.is_open())
	{
		cout << "The file has been opened successfully" << endl;
		while (breakloop == false)
		{
			read >> next;
			if (next != -1)
			{
				extendcol(dp, row, col1);
				dp[row-1][col1-1] = next;
			}
			else
			{
				extendcol(dp, row, col1);
				dp[row-1][col1-1] = next;
				col1 = 0;
				extendrw(dp, row);
				read >> next;
				if (next == -1) {
					break;
				}
				else {
					extendcol(dp, row, col1);
					dp[row-1][col1-1] = next;
				}
			}
		}
	}read.close();
	
	// Checking output here modify it according to the ques
	for (int i=0;i<4;i++) {
		int j=0;
		for (;dp[i][j] !=-1;j++) {
			cout << dp[i][j] << "\t";
		}
		cout << dp[i][j] << "\n";
	}
}