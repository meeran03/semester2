#include <fstream>
#include <cstring>
#include <iostream>

using namespace std;




char** alloc(int& rows)
{
	//cin >> rows;
	rows = 1;
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


	char** endptr = dp + rows;
	for (char** startRow = dp; startRow < endptr; startRow++)
	{
		cout << *startRow << endl;

	}
}
void input(char**& dp, int& rows)
{
	//subscript
	//cin.ignore();
	ifstream fin("data.txt");
	int i = 0;
	if(fin.is_open())
	{ 
		while (fin.eof()==false)
		{
		
			char buffer[100];			
			fin >> buffer;
			int length = strlen(buffer) + 1;
			dp[i] = new char[length];
			strncpy(dp[i], buffer, length);
			extend(dp, rows);
			i++;
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

void sortArray(char **&mymem,int rows) {
    for (int i=0;i<rows;i++) {
        for (int j=0;j<rows;j++) {
            if (strcmp(mymem[i] , mymem[j]) < 0) {
                char *temp = mymem[j];
                mymem[j] = mymem[i];
                mymem[i] = temp;
            }
        }
    }
}


int main()
{

	/*char* p;
	char x = 'a';
	p = &x;
	cout << x << " " << *p << endl;
	*p = 'd';


	char** dp = &p;

	cout << x << " " << *p << endl;
	cout << &x << " " << p << endl;

	cout << &p << " " << dp << endl;

	**dp = 'A'; //**dp

	cout << x << " " << *p << " "<< **dp << endl;*/



	/*char x= 'a';
	char * p = &x;

	char arr[10];
	char *q = arr;

	char * n = new char[10];*/



	//char* ptrs[3];



	//char x[10];
	//ptrs[0] = x;

	//char arr[10];
	//ptrs[1] = arr;

	//ptrs[2] = new char[10];

	//ptrs[i];












	int rows = 0;
	char** mymem = alloc(rows);
	input(mymem, rows);
    sortArray(mymem,rows);
	output(mymem, rows);
	deallocate(mymem, rows);
	//mymem = nullptr;

	
	/*int*** tp = new int** [2];
	for (int i = 0; i < 2; i++)
	{
		tp[i] = new int* [3];
		for (int j = 0; j < 3; j++)
		{
			tp[i][j] = new int[5];
			for (int k = 0; k < 5; k++)
			{
				cin >> *(*(*(tp + i) + j) + k);
				cin >> tp[i][j][k];
			}
		}
	}*/






}