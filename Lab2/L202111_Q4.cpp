#include <iostream>
using namespace std;

void update(int *&ptr,int &size) {
    int* longPtr = new int[size*2];
    for (int i=0;i<=size;i++) {
        *(longPtr+i) = ptr[i];
    }
    size = size*2;
    delete [] ptr;
    ptr = longPtr;
}

void copyArray(int* arr, int *&arr1, int size) {
    for (int i=0;i<size;i++) {
        *(arr1+i) = *(arr+i); 
    }
}

void reduceArray(int *arr, int *&arr1, int size) {
    int reduceSize = 0;
    cout << "Enter the reduced size of array : ";
    cin >> reduceSize;
    arr1 = new int[reduceSize];
    for (int i=0;i<size-reduceSize;i++) {
        arr++;
    }
    copyArray(arr,arr1,reduceSize);
    cout << "Array after reduction is : " << endl;
    for (int i=0;i<reduceSize;i++) {
        cout << *(arr1+i) << "\t";
    }
    cout << endl;
}

int main() {
    int size;
    cout << "Enter the size : ";
    cin >> size;
    int *ptr = new int[size];
    for (int i=0;i<size;i++) {
        cout << "Enter the number " << (ptr+i) << " : ";
        cin >> *(ptr+i);
    }
    int *ptr1 = nullptr;
    reduceArray(ptr,ptr1,size);
    return 0;
}




/*

Take size input from the user and create an array of that size. Now populate the array as well by
taking input from the user.
• First Implement void copyArray(int* arr, int *&amp;arr1, int size) that copies arr into arr1.
• Now implement another function int reduceArray(int *arr, int *&amp;arr1, int size) that
asks user to enter size to reduce the array. To reduce the array remove (or chop) the elements of
the arr from the start and copy remaining into arr1. Use copyArray function to copy.

  */