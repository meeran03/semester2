#include <iostream>

using namespace std;

void CompressString(char* str) {
    int i=0;
    for ( char *temp = str, *temp2 = str; *temp2 != '\0';i++ ) {
        temp2++;
        if ( * temp2 != *temp ) {
            temp++;
            *temp = *temp2;
        }
    }

}


int main() {
    char str1[100] = "bbabbbbbcccddddddddddeffffg";
    CompressString(str1);
    cout << str1 << endl;
    return 0;
}

/* 

Write a function that takes a string and if it finds more than one consecutive occurrences of a character in the string,
it removes the extra occurrences. For example:
String: “a”
String after compression: “a”
String: “aaaaaaa”
String after compression: “a”
String: “bbabbbbbcccddddddddddeffffg”
String after Compression: “babcdefg”
Note: Do not use any extra string inside the function.


 */