#include <iostream>
#include <fstream>
using namespace std;

void update(int **arr,int row,int &size) {
    size = size+1;
    int *ptr = new int[size];
    int * endptr = arr[row] +size;
    for (int i=0,*p=ptr;i<size-1;i++,p++) {
        *p = arr[row][i];
    }
    delete [] arr[row];
    arr[row] = nullptr;
    arr[row] = ptr;
}

void extend(int**& dp, int& rows) {
	int** dpNew = new int* [rows + 1];
    int** endptr = dpNew + rows;
	for (int i = 0, **p =dpNew; p < endptr; i++,p++)
		*p = dp[i];
	delete[] dp;
	dp = nullptr;
	dp = dpNew; 
	rows++;
}

int** get2D(char* filename) {
    int size=1;
    int** arr = new int*[size];
    int **tempArr = arr;
    int i=0;
    fstream fin(filename,ios::in);
    if (fin.is_open()) {
        int temp;
        while (1) {
            fin >> temp;
            update(arr,size-1,i);
            if (temp !=-1) {
                arr[size-1][i-1]= temp;
            }
            else {
                arr[size-1][i-1]= temp;
                i=0;
                
                extend(arr,size);  
                fin >> temp;
                if (temp !=-1) {
                    update(arr,size-1,i);
                    arr[size-1][i-1]= temp;
                }
                else {
                    extend(arr,size);
                    arr[size-1] = nullptr;
                    break;
                }
            }
        }

    }
    return arr;
}

void reduceCol(int ** arr,int j,int row) {
    int size=1;
    int **p = arr+row;
    for (int j=0; *(*(p)+j) !=-1; j++) {
        size++;
    }
    int *ptr = new int[size-1];
    // Now that size decreased, copy the contents excluding jth term
    int m=0;
    int l=0;
    while (m<size) {
        if (m != j) {
            ptr[l] = arr[row][m];
            l++;
        }
        m++;
    }
    delete [] arr[row];
    arr[row] = nullptr;
    arr[row] = ptr;
}

bool checkArr(int firstArr, int secondArr, int** arr) {

    bool good = true;
    int size1=1,size2=1;
    while (arr[firstArr][size1]!=-1) {
        size1++;
    } 
    while (arr[secondArr][size2]!=-1) {
        size2++;
    } 
    if (size1 != size2) {
        good = false;
    }
    else {
        for (int i=0;i<size1;i++) {
            if (arr[firstArr][i] != arr[secondArr][i]) {
                good = false;
                break;
            }
        }
    }
    return good;
}

void reduceRow(int ** &arr,int row) {
    int size=0;
    for (int j=0; *(arr+j); j++) {
        size++;
    }
    int **ptr = new int*[size];
    // Now that size decreased, copy the contents excluding rowth term
    int m=0;
    int l=0;
    while (m<size+1) {
        if (m != row) {
            ptr[l] = arr[m];
            l++;
        }
        m++;
    }
    delete [] arr;
    arr = nullptr;
    arr = ptr;

}

void RemoveAllRepititions(int**& arr) {
    // This is the Pass 1
    int i=0;
    while (*(arr+i)) {
        for (int j=0; *(*(arr+i) +j) ;) {
            if (*(*(arr+i) +j) == *(*(arr+i)+j+1)) {
                reduceCol(arr,j+1,i);
            }
            else {
                j++;
            }
        }
        i++;
    }
    // This is the pass 2
    int m=0;
    while (*(arr+m+1)) {
        if (checkArr(m,m+1,arr)) {
            reduceRow(arr,m);
        }
        else {
        }
        m++;
    }
}

int main() {
    char* filename = new char[100];
    cout << "Enter the filname : ";
    cin >> filename;
    int** arr = get2D(filename);
    int n=0,i=0;
    RemoveAllRepititions(arr);
    while (1) {
        n=0;
        while (*(*arr +n) != -1) {
            cout << *(*arr + n) << "\t";
            n++;
        }
        cout  << *(*arr + n) << endl;
        if (*(arr+1) == 0) {
            break;
        }
        else {
            arr++;
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