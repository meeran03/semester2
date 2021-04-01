#include <iostream>
using namespace std;

char** AllocateMemory(int &rows, int &cols) {
    cout << "Enter the number of rows : ";
    cin >> rows;

    cout << "Enter the number of columns : " ;
    cin >> cols;

    char ** arr = new char*[rows];
    for (int i=0;i<rows;i++) {
        arr[i] = new char[cols];
    }
    return arr;
}

void InputMatrix(char** matrix, const int rows, const int cols) {
    for (int i=0;i<rows;i++) {
        for (int j=0;j<cols;j++) {
            cout << "Enter the element Matrix[" << i << "][" << j << "] : ";
            cin >> matrix[i][j];
        }
    }
}

void DisplayMatrix(char** matrix, const int& rows, const int& cols) {
    for (int i=0;i<rows;i++) {
        for (int j=0;j<cols;j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

void update(char *&ptr,int &size) {
    size++;
    char* longPtr = new char[size];
    for (int i=0;i<size;i++) {
        *(longPtr+i) = ptr[i];
    }
    delete [] ptr;
    ptr = longPtr;
}

char** seperateFunc(char ** matrix,int rows,int cols,int &aSize,int &sSize,int &nSize,
char * &aArr,char * &sArr,char * &nArr) {
    for (int i=0;i<rows;i++) {
        for (int j=0;j<cols;j++) {
            char temp = matrix[i][j];
            if ((temp >= 'a' && temp <='z') || (temp >= 'A' && temp <='Z')) {
                update(aArr,aSize);
                aArr[aSize-1] = temp;
            }
            else if ((temp >= '0' && temp <='9')) {
                update(nArr,nSize);
                nArr[nSize-1] = temp;
            }
            else {
                update(sArr,sSize);
                sArr[sSize-1] = temp;
            }
        }
    }
}

int selectionSort(char *&arr) { 
    int size=0;
    while (*(arr+size)) {
        size++;
    } 
    int i, j, minIndex;  
      for (i = 0; i < size-1; i++)  {  
        minIndex = i;  
        for (j = i+1; j < size; j++)  
        if (arr[j] < arr[minIndex])  
            minIndex = j;  
  
        char temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }  
    return size;
}

void sortArr(char *&aArr,char *&sArr,char*&nArr) {
    int aSize = selectionSort(aArr);
    int sSize = selectionSort(sArr);
    int nSize = selectionSort(nArr);
    cout << "Alphabets : ";
    int i=0;
    while (i<=aSize) {
        cout << aArr[i] << "\t";
        i++;
    }
    cout << endl;

    i=0;
    cout << "Numbers : ";
    while (i<=nSize) {
        cout << nArr[i] << "\t";
        i++;
    }
    cout <<endl;

    i=0;
    cout << "Special Characters : ";
    while (i<=sSize) {
        cout << sArr[i] << "\t";
        i++;
    }
    cout <<endl;
}

void DeallocateMemory(char **arr,char*aArr,char *sArr,char*nArr,int rows) {
    delete [] sArr;
    delete [] aArr;
    delete [] nArr;
    for (int i=0;i<rows;i++) {
        delete [] arr[i];
        arr[i] = nullptr;
    }
    delete [] arr;
    arr = nullptr;
}

int main() {
    int rows=0,cols=0;
    char ** arr = AllocateMemory(rows,cols);
    InputMatrix(arr,rows,cols);
    DisplayMatrix(arr,rows,cols);

    int aSize=0,sSize=0,nSize=0;
    char* aArr = new char[aSize];
    char* sArr = new char[sSize];
    char* nArr = new char[nSize];
    seperateFunc(arr,rows,cols,aSize,sSize,nSize,aArr,sArr,nArr);

    sortArr(aArr,sArr,nArr);


    return 0;
}

/* 
TASK 1:
a) Write a function char** AllocateMemory(int&amp; rows, int&amp; cols) that takes size of
matrix (rows and columns) from user, allocates memory for the matrix and return its
pointer.
b) Write a function void InputMatrix(char** matrix, const int rows, const int cols)
which takes input the values in matrix from user(console).
c) Write a function void DisplayMatrix(char** matrix, const int&amp; rows, const int&amp;
cols) that displays the matrix in proper format.
d) Write a function that does the following:
 Creates three dynamic char arrays namely alphabets, numbers, and
specialchar. (Define the sizes yourself).
 Iterate the 2D array and separate alphabet elements and save them in the
alphabets array, separate number elements and save them in numbers array
and separate special character elements and save them in the specialchar
array.
 The function returns the three arrays alphabets, numbers, and specialchar.
 Note: The three arrays should not consume any extra space. Resize the
arrays accordingly.
For example, if the Sample Matrix is
A 1 v @
+ 9 s 6
P # ^ 4

Your function will return the following arrays:
alphabets = A v s P
numbers = 1 9 6 4
specialchar = @ + # ^

e) Create a function sortArray that takes in input three arrays alphabets, numbers,
and specialchar and their sizes and sort each of these arrays according to their
ASCII values (ascending order) and print these sorted arrays on the console.
For the above example the sorted arrays are:
alphabets = A P s v
numbers = 1 4 6 9
specialchar = # + @ ^

f) Write a function void DeallocateMemorythat deallocates all the memory.

void main()
{
int rows, cols;
//take input from user for rows and cols
char** matrix = AllocateMemory (rows, cols);
DisplayMatrix(matrix, rows, cols);
InputMatrix(matrix, rows, cols);
// additional function calls
//deallocate memory
}
 */