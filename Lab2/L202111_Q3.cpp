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

int Input(int* &ptr,int &size) {
    int temp;
    int i=0;
    while (temp !=-1) {
        cout << "Enter the number : " ;
        cin >> temp;
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