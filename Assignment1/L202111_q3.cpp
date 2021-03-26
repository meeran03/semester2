#include <iostream>
#include <fstream>
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

int Input(int* &ptr,int &size) {
    fstream myFile("data.txt",ios::in);
    int temp;
    int i=0;
    while (temp !=-1 &&  !myFile.eof()) {
        myFile >> temp;
        if (temp == -1) {
            break;
        }
        if (i<size) {
            *(ptr+i) = temp;
            i++;
        }
        else if (i == size) {
            update(ptr,size);
            *(ptr+i) = temp;
            i++;
        }

    } 
    return i;
}

void reverse(int* ptr, int size) {
    int i=0;
    while (i < size)
    {
        int temp = *(ptr+i); 
        *(ptr+i) = *(ptr+size);
        ptr[size] = temp;
        i++;
        size--;
    } 
}  

void output(int* ptr,int size,int size2) {
    for (int j=size-size2+1;j<=size;j++) {
        cout << *(ptr+j) << endl;
    }
}

int main() {
    int size =5;
    int* arr = new int[size];
    int size2 = Input(arr,size);
    reverse(arr,size);
    output(arr,size,size2);
    delete []arr;
    return 0;
}

/* 
Write a program that keeps taking integer input from the file until -1 encounters and displays the data in reverse
order.
Your program should save the input in a dynamically allocated array. Initially create a dynamic array of five integers.
Each time the array gets filled your program should double the size of array and continue taking the input. After
receiving -1 (i.e. end of data input) your program should print the numbers in the reverse order as entered by the
user.
Sample Run:

Input Output

Data
4

Data in Reverse Order:
56

9
5
33
85
73
91
27
56
-1

27
91
73
85
33
5
9
4

 */