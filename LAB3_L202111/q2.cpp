#include <iostream>
#include <fstream>
using namespace std;




void expandMatrix(int**&matrix,int rows,int cols) {
    int** temp = new int*[rows+1];
    for (int i=0;i<rows;i++) {
        for (int j=0;j<cols;j++) {
            *((*temp+i)+j) = *((*temp+i)+j);
        }
    }
    matrix = temp;
    rows++;
}

void expandWithCols(int**&matrix,int row,int col) {
    int* temp = new int[col+2];
    for (int i=0;i<col;i++) {
        *(temp+i) = *((*matrix+row)+col);
    }
    *(matrix+row) = temp;
    col+= 2;
}

void loadMatrix(int **&matrix,int &rows, int &cols) {
    matrix = new int*[rows+1];
    fstream fin2("data.txt",ios::in);
    if (fin2.is_open()) {
        int i=0;//cols
        int currentRow=0;
        int currentCol=0;
        while (!fin2.eof()) {
            if (i>6) {
                expandMatrix(matrix,rows,cols);
            }

            int temp=0;
            fin2 >> temp;
            if (temp!=0) {
                expandWithCols(matrix,rows,currentCol);
                matrix[rows][0]++;
                matrix[rows][currentCol] = i;
                matrix[rows][currentCol+1] = temp;
                cout << "Number : " << matrix[rows][currentCol+1] << endl;
                cout << "Position : " << matrix[rows][currentCol] << endl;
            }

            i++;
            if (i>6) {
                i=0;
                currentCol=0;
            }
        }
    } 
}

void print(int ** matrix,int rows) {
    for (int i=0;i<rows;i++) {
        for (int j=0;j<rows;j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

void deallocate(int**& matrix, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] *(matrix+i);
	}
	delete[] matrix;
	matrix = nullptr;
}


int main() {
    int rows=0,cols=0;
    int** matrix = nullptr;
    loadMatrix(matrix,rows,cols);
    for (int i=0;i<rows+1;i++) {
        for (int j=0;j<cols;j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    print(matrix,rows);
    deallocate(matrix,rows);

    return 0;
}
