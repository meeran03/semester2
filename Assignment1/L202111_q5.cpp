#include <iostream>
#include <cstring>
using namespace std;

void update(char *&ptr,int &size) {
    size++;
    char* longPtr = new char[size];
    for (int i=0;i<size;i++) {
        *(longPtr+i) = ptr[i];
    }
    delete [] ptr;
    ptr = longPtr;
}

char *input(int &size) {
    char * ptr = new char[size];
    char temp;
    cin.get(temp);
    while (temp != '\n') {
        ptr[size] = temp;
        update(ptr,size);
        cin.get(temp);
    }
    return ptr;
}

char* substr(char* arr, int &begin, int len)
{
    char* res = new char[len + 1];
    for (int i = 0; i < len; i++)
        res[i] = *(arr + begin + i);
    res[len] = 0;
    begin++;
    return res;
}

bool palindrome(char* ptr) {
    for (int i=strlen(ptr)-1,j=0;j<strlen(ptr);i--,j++) {
        if (ptr[i] != ptr[j]) {
            return false;
        }
    }
    return true;
}

int main() {
    cout << "Enter the string : ";
    int size=0;
    char* ptr = input(size);
    int begin = 0;
    for (int len=3;len<=strlen(ptr);len++,begin=0) {
        while (begin <=strlen(ptr)-len) {
            char * tempPtr = substr(ptr,begin,len);
            if (palindrome(tempPtr)) {
                cout << tempPtr << endl;
            }
        }
    }
    return 0;
}


/* 

Take a string from user, prints all substrings having length more than 2 and those are palindrome.
For example,
String: “adbcbdad",
Output: "bcb"
"dad"
"dbcbd"
"adbcbda"
String:"hemetme",
Output: "eme"

 */