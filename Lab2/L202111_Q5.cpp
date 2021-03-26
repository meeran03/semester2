#include <iostream>
using namespace std;

void Input(int *&c1,int size) {
    for (int i=0;i<size;i++) {
        cin >> *(c1+i);
    }
}

void update(int *&ptr,int &size) {
    size++;
    int* longPtr = new int[size];
    for (int i=0;i<size;i++) {
        *(longPtr+i) = ptr[i];
    }
    delete [] ptr;
    ptr = longPtr;
}

int* Compression(int* c1,int &size) {
    int ptrSize=0;
    int * ptr = new int[size];
    for (int i=0;i<size;i++) {
        if (*(c1+i+1) != *(c1+i)) {
            update(ptr,ptrSize);
            *(ptr+ptrSize-1) =  *(c1+i);
        }
    }
    size = ptrSize;
    return ptr;
}

void Output(int *ptr, int size) {
    for (int i=0;i<size;i++) {
        cout << *(ptr+i) << "\t";
    }
    cout << endl;
}

int main() {
    int size;
    cout << "Enter the size of array : ";
    cin >> size;
    int* c1 = new int [size];
    cout << "Input elements in array : " << endl;
    Input(c1, size);
    //Compressing the array
    int * p2=Compression (c1, size);
    cout << "Array after compression will be : ";
    Output(p2, size);
    return 0;
}


/* 

Write a program that takes size of an array and its elements and removes consecutive
occurrences of same number from the list. For the example given below, your program should
have space of exactly 7 integers on heap after compression. Do not consume any extra byte on
heap.
For Example:
Input:
Please enter size: 7
Please enter elements: 91
3
40
7
8
12
642
Please enter the reduced size of array: 5
Output:
Array after reduction is: 40, 7, 8, 12, 642

Input:
Please enter size: 18
Please enter elements: 1,1,2,2,2,3,4,5,5,5,5,5,7,7,7,2,2,2

Output:
Array After Compression: 1,2,3,4,5,7,2

Use the following main() for this question:
int main()
{
int size;
coutlt;&lt;&quot;Enter the size of array&quot;&lt;&lt;endl;
cin&gt;&gt;size;
int* c1 = new int [size];
cout&lt;&lt;&quot;Input elements in array: &quot;;
Input(c1, size);
//Compressing the array
int * p2=Compression (c1, size);
cout&lt;&lt;&quot;Array after compression will be: &quot;;
Output(p2, size);
system(&quot;pause&quot;);
return 0;
}

 */