#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter the size of the array : " ;
    cin >> size;
    int* arr = new int[size];
    for (int i=0;i<size;i++) {
        arr[i] = 0;
    } 

    int qSize;
    cout << "Enter the number of queries : ";
    cin >> qSize;
    int** Q = new int*[qSize];
    for (int i=0;i<qSize;i++) {
        Q[i] = new int[2];
        cout << "Enter the value of left for query " << i+1 << " : ";
        cin >> Q[i][0];
        cout << "Enter the value of right for query " << i+1 << " : ";
        cin >> Q[i][1];
        cout << "Query-" << i+1 << ": " << Q[i][0] << ", " << Q[i][1] << endl << endl;
        int start = Q[i][0];
        int end = Q[i][1];
        for (int i=start;i<=end;i++) {
            arr[i] = arr[i] +1;
        }
    }

    for (int i=0;i<size;i++) {
        cout << arr[i] << "\t";
    } 
    cout << endl;

    delete [] arr;
    for (int i=0;i<qSize;i++) {
        delete [] Q[i];
    }
    Q = nullptr;

    
    return 0;
}

/* 
TASK:
You have been given array of all zeroes. Size of array will be “N” and you will get “Q” quires. In each
query you get two numbers “left” and “right”. Increase all values from index left to right by 1. At last
print array.
Example:
Enter the size of array: 7
Print array:
0, 0, 0, 0, 0, 0, 0
Enter number of quires: 3
Enter value of left for query 1: 2
Enter value of right for query 1: 4
Query-1: 2, 4

Enter value of left for query 2: 1
Enter value of right for query 2: 4
Query-2: 1, 4

Enter value of left for query 3: 2
Enter value of right for query 3: 3
Query-3: 2, 3

Print array:
0, 1, 3, 3, 2, 0, 0

 */