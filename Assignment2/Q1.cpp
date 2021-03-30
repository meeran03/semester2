#include <iostream>
#include <fstream>
using namespace std;


void updateWord(char **&dic,int &words,int size,char temp[]) {
    char* longPtr = new char[size+1];
    for (int i=0;i<size;i++) {
        *(longPtr+i) = temp[i];
    }
    *(dic+words-1) = longPtr;
}

void updateDic(char **&ptr,int &words) {
    words++;
    char** longPtr = new char*[words];
    for (int i=0;i<words-1;i++) {
        *(longPtr+i) = ptr[i];
    }
    delete [] ptr;
    ptr = longPtr;
}

bool checkWord(char word[], int &size) {
    int i=0;
    bool isElig = true;
    while (word[i] !='\0') {
        if (word[i] < 65 || (word[i] <97 && word[i] > 90) || word[i] > 122) {
            isElig = false;
            break;
        }
        i++;
    }
    size = i;
    if (size < 3) {
        isElig = false;
    }
    return isElig;

}

char** createDic(char* filename) {
    int words=1;
    int size=0;
    char** dic = new char*[words];
    fstream fin(filename,ios::in);
    if (fin.is_open()) {
        while (!fin.eof()) {
            char temp[100];
            fin >> temp;
            if (checkWord(temp,size)) {
                updateWord(dic,words,size,temp);
                updateDic(dic,words);
            }
        }
        return dic;

    }
}

bool checkPresent(char ** arr,int arrSize,char ** dic,int word) {
    bool found = false;
    int i=0;
    while (i<arrSize-1) {
        if (*(dic+word) == *(arr+i)) {
            found = true;
            break;
        }
        i++;
    }
    return found;
}

void removeRepititions(char **& dic) {
    int size=1;
    int i=0;
    char** replica= new char*[size];
    while (*(dic+i)) {
        if (!checkPresent(replica,size,dic,i)) {
            replica[size-1] = dic[i];
            updateDic(replica,size);
        }
        i++;
    }
    delete [] dic;
    dic = replica;
}


int main() {
    char* filename = new char[100];
    cout << "Enter the filname : ";
    cin >> filename;
    char** dic = createDic(filename);
    for (int i=0;*(dic+i);i++) {
        cout << *(dic + i) << endl;
    }
    cout << "\nAfter Removing : \n\n";
    removeRepititions(dic);
    for (int i=0;*(dic+i);i++) {
        cout << *(dic + i) << endl;
    }
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