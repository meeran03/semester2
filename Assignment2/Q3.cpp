#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;

char** alloc(int& rows)
{
	if (rows > 0)
	{
		char** dp = new char* [rows];
		for (int i = 0; i < rows; i++)
			dp[i] = nullptr;

		return dp;
	}
	return nullptr;
}


void extend(char**& dp, int& rows)
{
	char** dpNew = new char* [rows + 1];
	for (int i = 0; i < rows; i++)
		dpNew[i] = dp[i];
	delete[] dp;
	dp = nullptr;
	dp = dpNew;
	rows++;
}


void output(char** dp, int rows)
{

    cout << rows << endl;
	char** endptr = dp + rows;
	for (char** startRow = dp; startRow < endptr; startRow++)
	{
		cout << *startRow << endl;

	}
}


void input(char**& dp, int& rows)
{
	ifstream fin("data.txt");
	if (fin.is_open())
	{
		while (fin.eof() == false)
		{

			char buffer[100];
			fin >> buffer;
			int length = strlen(buffer) + 1;
			dp[rows-1] = new char[length];
			int i = 0;
			bool check = false;
			while (i<length-1) {               
				if ((buffer[i] >= 'a' && buffer[i] <= 'z') || (buffer[i] >= 'A' && buffer[i] <= 'Z'))
				{
					i++;
				}
				else
				{
					check = true;
                    break;
				}
			}
			if (check == false)
			{
				if (length-1 >= 3)
				{
					strncpy(dp[rows-1],  buffer,length);
					extend(dp, rows);
				}
			}
			
		}
		fin.close();
	}
	rows--;
}



void deallocate(char**& mymem, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] mymem[i];
	}
	delete[] mymem;
	mymem = nullptr;
}



int main()
{
	int rows = 1;
	char** mymem = alloc(rows);
	input(mymem, rows);
	output(mymem, rows);
	deallocate(mymem, rows);
    return 0;

}