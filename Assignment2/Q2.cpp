#include <iostream>
#include <fstream>
using namespace std;

void update(int **arr,int row,int &size) {
    size = size+1;
    int *ptr = new int[size*2];
    for (int i=0;i<size-1;i++) {
        *(ptr+i) = arr[row][i];
    }
    delete [] arr[row];
    arr[row] = nullptr;
    arr[row] = ptr;
}

void extend(int**& dp, int& rows) {
	int** dpNew = new int* [rows + 1];
	for (int i = 0; i < rows; i++)
		dpNew[i] = dp[i];
	delete[] dp;
	dp = nullptr;
	dp = dpNew; 
	rows++;
}

int** get2D(char* filename) {
    int size=1;
    int** arr = new int*[size];
    int i=0;
    fstream fin(filename,ios::in);
    if (fin.is_open()) {
        int temp;
        while (!fin.eof()) {
            fin >> temp;
            update(arr,size-1,i);
            if (temp !=-1) {
                arr[size-1][i-1]= temp;
            }
            else {
                arr[size-1][i-1]= temp;
                i=0;
                extend(arr,size);
            }
        }

    }
    return arr;
}

int main() {
    char* filename = new char[100];
    cout << "Enter the filname : ";
    cin >> filename;
    int** arr = get2D(filename);
    int i=0;
    int n=0;
    while (arr[i][n] !=-1 && arr[i][n+1] !=-1) {
        n=0;
        while (arr[i][n] !=-1) {
            cout << arr[i][n] << "\t";
            n++;
        }
        cout << arr[i][n];
        cout << endl;
        if (!(arr[i][n] !=-1 && arr[i][n+1] !=-1)) {
            i++;
        }
        else {
            break;
        }
    }
    return 0;
}


/* 
Write a function int ** get2D(char * filename);
This function creates a 2D array with size 1, starts taking input from file. Whenever input encounters a -1, it means a
row is completed. Whenever input encounters two-consecutive -1, it means input is terminated. The last row of 2D
array will point to nullptr.
Note: Null (0) in int* array indicates end of integer arrays (delimiter in first dimension) while -1 indicates end of data
in integer arrays (delimiter in second dimension).
So, you do not need to remember/store the value of rows and cols in this question.
Hint: Assignment # 1, Q # 3
File 2D array
1 1 1 2 -1 1 2 2 -1 1 2 2 4 4
-1 1 2 3 -1 -1

0

1 1 1 2 -1
1 2 2 -1
1 2 2 4 4 -1
1 2 3 -1

Write a function void RemoveAllRepititions(int**& arr) that takes a 2-D array “arr” as input and removes data
repetitions in two passes. In first pass, it removes duplicate elements from each integer array. For example, integer
array {1, 2, 2, 4, 4, -1} becomes {1, 2, 4, -1} after removing repetitions. In second pass, it removes repetitions if two
consecutive arrays are identical. Sample run is shown below:

0
1 1 1 2 -1
1 2 2 -1
1 2 2 4 4 -1
1 2 3 -1

0
1 2 -1
1 2 -1
1 2 4 -1
1 2 3 -1 0

1 2 -1
1 2 4 -1
1 2 3 -1

Input Array Array after Pass 1 Array after Pass 2

Identical consecutive
elements have been
removed from all rows

Identical consecutive rows removed.
(First two integer arrays were identical
in Pass 1)
Good Good
Myth Myth
Why Why
Good Psych
Psych astonished
astonished

Null (0) in int* array indicates end of integer arrays (delimiter in first dimension) while -1 indicates end of data in
integer arrays (delimiter in second dimension). Make sure that your program does not consume extra memory and it
should not leak any memory.

Note: You are only allowed to use pointer (arithmetic) notation.

 */