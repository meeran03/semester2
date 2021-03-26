#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

char* input(int &size,fstream &fin) {
    char buffer[1000];
    fin.getline(buffer,1000);
    size = strlen(buffer);
    if (size>0) {
        char* ptr = new char[size+1];
        for (int i=0;i<size;i++) {
            *(ptr+i) = buffer[i];
        }
        return ptr;
    }
    return nullptr;
}

void update(char* &ptr,int& size,char hex) {
    char* temp = new char[4];
        switch (hex) {
            case '0' : {
                *(temp+0) = '0';                
                *(temp+1) = '0';                
                *(temp+2) = '0';                
                *(temp+3) = '0';
                break;
            }
            case '1' : {
                *(temp+0) = '0';                
                *(temp+1) = '0';                
                *(temp+2) = '0';                
                *(temp+3) = '1';
                break;
            }
            case '2' : {
                *(temp+0) = '0';                
                *(temp+1) = '0';                
                *(temp+2) = '1';                
                *(temp+3) = '0';
                break;
            }
            case '3' : {
                *(temp+0) = '0';                
                *(temp+1) = '0';                
                *(temp+2) = '1';                
                *(temp+3) = '1';
                break;
            }
            case '4' : {
                *(temp+0) = '0';                
                *(temp+1) = '1';                
                *(temp+2) = '0';                
                *(temp+3) = '0';
                break;
            }
            case '5' : {
                *(temp+0) = '0';                
                *(temp+1) = '1';                
                *(temp+2) = '0';                
                *(temp+3) = '1';
                break;
            }
            case '6' : {
                *(temp+0) = '0';                
                *(temp+1) = '1';                
                *(temp+2) = '1';                
                *(temp+3) = '0';
                break;
            }
            case '7' : {
                *(temp+0) = '0';                
                *(temp+1) = '1';                
                *(temp+2) = '1';                
                *(temp+3) = '1';
                break;
            }
            case '8' : {
                *(temp+0) = '1';                
                *(temp+1) = '0';                
                *(temp+2) = '0';                
                *(temp+3) = '0';
                break;
            }
            case '9' : {
                *(temp+0) = '1';                
                *(temp+1) = '0';                
                *(temp+2) = '0';                
                *(temp+3) = '1';
                break;
            }
            case 'A' : {
                *(temp+0) = '1';                
                *(temp+1) = '0';                
                *(temp+2) = '1';                
                *(temp+3) = '0';
                break;
            }
            case 'B' : {
                *(temp+0) = '1';                
                *(temp+1) = '0';                
                *(temp+2) = '1';                
                *(temp+3) = '1';
                break;
            }
            case 'C' : {
                *(temp+0) = '1';                
                *(temp+1) = '1';                
                *(temp+2) = '0';                
                *(temp+3) = '0';
                break;
            }
            case 'D' : {
                *(temp+0) = '1';                
                *(temp+1) = '1';                
                *(temp+2) = '0';                
                *(temp+3) = '1';
                break;
            }
            case 'E' : {
                *(temp+0) = '1';                
                *(temp+1) = '1';                
                *(temp+2) = '1';                
                *(temp+3) = '0';
                break;
            }
            case 'F' : {
                *(temp+0) = '1';                
                *(temp+1) = '1';                
                *(temp+2) = '1';                
                *(temp+3) = '1';
                break;
            }
        }

    for (int j=0;j<4;j++) {
        ptr[size+j] = *(temp+j); 
    }
    size = size+4;

}

void reverse(char* &ptr, int size) {
    int tempSize = size;
    int i=0;
    char * temp = new char[size];
    while (i < tempSize)
    {
        *(temp+i) = *(ptr+size-2); 
        size--;
        i++;
    } 
    ptr = temp;
}  

void addBinary(char*ptr1,char*ptr2,char*&ptrResult,int size1,int size2,int &sizeResult) {
    if (size2>size1) {
        int carry=0;
        int m=0;
        for (int i=size2-1,j=size1-1;i>=0;i--,j--) {
            int tempPtr1=0,tempPtr2=0;
            if (ptr1[j] == '1') {
                tempPtr1 = 1;
            }   else { tempPtr1 =0; }

            if (ptr2[i] == '1') {
                tempPtr2 = 1;
            }   else { tempPtr2 =0; }

            if(tempPtr1+tempPtr2+carry==3){
                ptrResult[m]='1';
                carry=1;
            }
            if(tempPtr1+tempPtr2+carry==2){
                ptrResult[m]='0';
                carry=1;
            }
            if(tempPtr1+tempPtr2+carry==1){
                ptrResult[m]='1';
                carry=0;
            }
            if(tempPtr1+tempPtr2+carry==0){
                ptrResult[m]='0';
                carry=0;
            }
            m++;
        }
    
        ptrResult[m] = carry;
        m++;
        sizeResult = m;
    }
    else {
        int carry=0;
        int m=0;
        for (int i=size2-1,j=size1-1;j>=0;i--,j--) {
            int tempPtr1=0,tempPtr2=0;
            if (ptr1[j] == '1') {
                tempPtr1 = 1;
            }   else { tempPtr1 =0; }

            if (ptr2[i] == '1') {
                tempPtr2 = 1;
            }   else { tempPtr2 =0; }

            if(tempPtr1+tempPtr2+carry==3){
                ptrResult[m]='1';
                carry=1;
            }
            if(tempPtr1+tempPtr2+carry==2){
                ptrResult[m]='0';
                carry=1;
            }
            if(tempPtr1+tempPtr2+carry==1){
                ptrResult[m]='1';
                carry=0;
            }
            if(tempPtr1+tempPtr2+carry==0){
                ptrResult[m]='0';
                carry=0;
            }
            m++;
        }
    
        ptrResult[m] = carry;
        m++;
        sizeResult = m;
    }
}

char* substr(char* &arr, int begin, int len) {
    char* res = new char[len + 1];
    for (int i = 0; i < len; i++)
        res[i] = *(arr + begin + i);
    res[len] = 0;
    return res;
}

char generateHex(char  ptr[]) {
    int hex=0;
    if (ptr[0] == '1') {
        hex = hex+8;
    }
    if (ptr[1] == '1') {
        hex = hex+4;
    }
    if (ptr[2] == '1') {
        hex = hex+2;
    }
    if (ptr[3] == '1') {
        hex = hex+1;
    }
    switch(hex) {
        case 0 : return '0';
        case 1 : return '1';
        case 2 : return '2';
        case 3 : return '3';
        case 4 : return '4';
        case 5 : return '5';
        case 6 : return '6';
        case 7 : return '7';
        case 8 : return '8';
        case 9 : return '9';
        case 10 : return 'A';
        case 11 : return 'B';
        case 12 : return 'C';
        case 13 : return 'D';
        case 14 : return 'E';
        case 15 : return 'F';
    }
}

char* binaryToHex(char * ptr,char* &result,int size) {
    char *hexString = new char[size/4];
    int i=0;
    for (int begin =0;begin<size-2 ;) {
        char * temp = substr(ptr,begin,4);
        *(hexString+i) = generateHex(temp);
        begin = begin +4;
        i++;
        
    }
    return hexString;    
}


int main() {
    fstream myFile("data2.txt",ios::in) ;
    cout << "Hello World" << endl;
    if (myFile.is_open()) {
        int size1,size2;
        char *ptr1 = input(size1,myFile);
        char *ptr2 = input(size2,myFile);
        cout << ptr1 << endl;
        cout << ptr2 << endl;


        char* ptrBin1,*ptrBin2;
        int binSize1=0,binsize2=0;

        ptrBin1 = new char[(size1*4) +1];
        for (int i=0;i<strlen(ptr1);i++) {
            update(ptrBin1,binSize1,ptr1[i]);
        }

        cout << ptr1 << " : ";
        for (int i=0;i<binSize1;i++) {
            cout << *(ptrBin1+i) ;
        }
        cout << endl;


        ptrBin2 = new char[(size2*4) +1];
        for (int i=0;i<strlen(ptr2);i++) {
            update(ptrBin2,binsize2,ptr2[i]);
        }
        
        cout << ptr2 << " : ";
        for (int i=0;i<binsize2;i++) {
            cout << *(ptrBin2+i) ;
        }
        cout << endl;

        //Adding the binary strings
        int sizeResult=binsize2+1;
        char * ptrResult = new char[sizeResult];
        addBinary(ptrBin1,ptrBin2,ptrResult,binSize1,binsize2,sizeResult);
        //reverse(ptrResult,sizeResult);

        cout << "SUM in Binary : ";
        for (int i=0;i<=sizeResult;i++) {
            cout << *(ptrResult+i);
        }
        cout << endl;

        char* hexResult = new char[sizeResult/4];
        char* hexString = binaryToHex(ptrResult,hexResult,sizeResult);
        cout << "Sum : " << hexString << endl;
    }

    return 0;
}


/* 

Take two hex numbers input from file. Convert these hex numbers to binary numbers [which will be stored in char *
arrays]. Now add these binary numbers and show the resultant number in Hex. The resultant Hex number should be
stored in char * array as well.
For example,
Input: Hex # 1 : F
Hex # 2 : 10
Output: F = 1111
10 = 10000
Sum = 31, whose binary is 11111

Note: There is no limit on HEX number, so be careful. You neither convert HEX to decimal nor binary to decimal.

 */