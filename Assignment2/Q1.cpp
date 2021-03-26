#include <iostream>
#include <fstream>
using namespace std;


void updateWord(char **&dic,int &size,int word) {
    size++;
    char* longPtr = new char[size];
    for (int i=0;i<size;i++) {
        *(longPtr+i) = *(*(dic+word)+i);
    }
    delete [] (*(dic+word));
    *(dic+word) = longPtr;
    cout << *(dic+word) << endl;
}

void updateDic(char **&ptr,int &words) {
    words++;
    char** longPtr = new char*[words];
    for (int i=0;i<words;i++) {
        *(longPtr+i) = ptr[i];
    }
    delete [] ptr;
    ptr = longPtr;
}

// char *input(int &size) {
//     char * ptr = new char[size];
//     char temp;
//     cin.get(temp);
//     while (temp != '\n') {
//         ptr[size] = temp;
//         update(ptr,size);
//         cin.get(temp);
//     }
//     return ptr;
// }

void createDic(char* filename) {
    int words=1;
    char** dic = new char*[1];
    fstream fin(filename,ios::in);
    int i=0;
    int size=0;
    *(dic+0) = nullptr;
   // if (fin.is_open()) {
        while (!fin.eof()) {
            char temp;
            fin.get(temp);
            if (temp != '\n' && temp !=' ') {
                //updateWord(dic,size,i);
                cout << temp;
            }
            else {
                updateDic(dic,words);
                i++;
                size=0;
            }
        }
        cout << endl;
        cout << words << endl;
        cout << dic << endl;
   // }
}


int main() {
    char* filename = new char[100];
    cout << "Enter the filname : ";
    cin >> filename;
    createDic(filename);
    return 0;
}


/* 

Write C++ code for a function that takes a filename and returns a 2D-char array having all the words, which have these
properties:
 Length equal or more than 3.
 Words which do not have numeric values.
 Words do not have any special character.
Make sure that there are no memory leaks in your program, and the new 2d-array should contain exactly the amount
of space required to store the words. You cannot use built in string functions.
Following is an example:
Filename: input.txt
Content:
I am r3eding a Good Myth Why m3any myth’re Good & Psych I am astonished

Good
Myth
Why
Good
Psych
astonished

Part-II

Write C++ code for a function that takes a 2d-dynamic array of words as input and removes all repetitions of the same
words. Make sure that there are no memory leaks in your program, and the new 2d-array should contain exactly the
amount of space required to store the unique words. You cannot use built in string functions.
Following is an example:
Input array before function call

 */