#include <fstream>
#include <iostream>
using namespace std;


int** AllocateMemory(int& rows, int& cols) {
	if (rows > 0)
	{
		int** dp = new int* [rows];
        int** endptr = dp+rows;
		for (int** i=dp; i < endptr; i++) { 
			*i = new int[cols];
        }
		return dp;
	}

	return nullptr;
}

void InputMatrix(int **& matrix, int rows, int cols) {
    int** endptr = matrix + rows;
	for (int **i=matrix;i<endptr ;i++) {
        int* endCol = *i+cols;
        for (int* j=*i;j<endCol;j++) {
            cout << "Enter the Matrix[" << i << "][" << j << "] : ";
            cin >> (*j);
        }
    }
}

void DisplayMatrix(int** matrix,int rows, int cols) {
    int** endptr = matrix + rows;
	for (int **i=matrix;i<endptr ;i++) {
        int* endCol = *i+cols;
        for (int* j=*i;j<endCol;j++) {
            cout <<  *j << "\t";
        }
        cout << endl;
    }
}

int findLargest(int* max,int col,int ** matrix,int rows) {
    int temp = *(*(matrix+0)+col);
    for (int i=0;i<rows;i++) {
        if (temp < *(*(matrix+i)+col) ) {
            temp = *(*(matrix+i)+col);
        }
    }

    return temp;
}

int* maxCol(int ** matrix,int rows,int cols) {
    int* max = new int[cols];
    for (int i=0;i<cols;i++) {
        *(max+i) = findLargest(max,i,matrix,rows);
    }
    return max;
}

void deallocate(int**& matrix, int rows)
{
    int** endptr = matrix+rows;
	for (int** i = matrix; i < endptr; i++)
	{
		delete[] i;
	}
	delete[] matrix;
	matrix = nullptr;
}

int main() {
    int rows, cols;
    cout << "Enter the number of columns : ";
    cin >> cols;
    cout << "Enter the number of rows : ";
    cin >> rows;

    int ** matrix = AllocateMemory(rows,cols);
    InputMatrix(matrix, rows, cols);
    DisplayMatrix(matrix, rows, cols);

    int * maxColValues = maxCol(matrix,rows, cols);
    for(int i=0; i< cols; i++){
        cout <<  *(maxColValues + i) << ",";
    }
    cout << endl;
    return 0;
    //deallocate matrix
    deallocate(matrix,rows);
    //delete maxColValues
    delete []maxColValues;
    return 0;
}




