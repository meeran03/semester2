#include <iostream>
using namespace std;


void selectionSort(float arr[], int size) {  
    int i, j, minIndex;  
      for (i = 0; i < size-1; i++)  {  
        minIndex = i;  
        for (j = i+1; j < size; j++)  
        if (arr[j] < arr[minIndex])  
            minIndex = j;  
  
        float temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }  
}

int main() {
    int size;
    cout << "Enter the size of input : ";
    cin >> size;
    float *ptr = new float[size];
    for (int i=0;i<size;i++) {
        cout << "Enter the element " << (ptr+i) << " : ";
        cin >> *(ptr+i);
    }
    selectionSort(ptr,size);
    cout << "The second largest number is : " << *(ptr+size-2) << endl;
    return 0;
}