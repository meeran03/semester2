#include <iostream>
using namespace std;


void Output (int * myptr, int size) {
    for (int i=0;i<size;i++) {
        cout << *(myptr+i) << "\t";
    }
    cout << endl;
}


int main() {
    int size;
    cout << "Enter the size of input : ";
    cin >> size;
    int *ptr = new int[size];
    *(ptr+0) = 1;
    *(ptr+1) = 1;
    for (int i=2;i<size;i++) {
        *(ptr + i) = *(ptr+i-1) + *(ptr+i-2);
    }
    Output(ptr,size);
    delete [] ptr;
    return 0;
}

/* 

Fibonacci sequence is a sequence in which every number after the first two is the sum of the two
preceding ones.
a) Write a C++ program that takes a number n from user and populate a dynamic array with first
n Fibonacci numbers.
For example:

b) Modify your code such that the output is now printed via a function.
void Output (int * myptr, int size)

 */