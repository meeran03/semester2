#include <iostream>
using namespace std;

int *input(int size) {
    int * ptr = new int[size];
    return ptr;
}

bool SearchArr(int num,int * arr2,int size2) {
    for (int i=0;i<size2;i++) {
        if (arr2[i] == num) {
            return true;
        }
    }
    return false;
}

int main() {
    cout << "Enter the size of Set A : ";
    int sizeA; cin >> sizeA;
    int *ptrA = input(sizeA);
    cout << "Enter " << sizeA << " elements : ";
    for (int i=0;i<sizeA;i++) {
        cin >> ptrA[i];
    }

    cout << "Enter the size of Set B : ";
    int sizeB; cin >> sizeB;
    int *ptrB = input(sizeB);
    cout << "Enter " << sizeB << " elements : ";
    for (int i=0;i<sizeB;i++) {
        cin >> ptrB[i];
    }

    int* ptrFinal = input(sizeA+sizeB);
    int m=0;
    for (int i=0;i<sizeA;i++) {
        if (SearchArr(ptrA[i],ptrB,sizeB)) {
            *(ptrFinal+m) = ptrA[i];
            m++;
        }
    }
    cout << "Intersection is : " << endl;
    for (int i=0;i<m;i++) {
        cout << ptrFinal[i] << endl;
    }
    return 0;
}

/* 

Intersection
Implement a function that finds intersection (common elements) of two sets (stored using arrays).
Sample Run:
//Input:
Enter Size of Set A: 6
Enter 6 elements: 1 2 3 4 5 6
Enter Size of Set B: 4
Enter 3 elements: 1 3 5 7
//Output
A = {1,2,3,4,5,6}
B = {1,3,5,7}
A Intersection B = {1, 3, 5}
Help: Note array3 should not have any duplicate elements. You have to:
 Allocate the three arrays dynamically after inputting the size of array1 and array2 from the user. Statically
allocated arrays are NOT allowed
 Initially you can allocate elements = (size of array1 + size of array2) to array3. For example you would allocate
6+4 to array 3 for the above example. After finding the common elements, the allocated size of array3 may
be more than what you need. (In the above example you require 3 whereas you have allocated 10).

 */