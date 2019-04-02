#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//
// 反转字符串
//
void reserver(char *str){
    char *end = str;
    char temp;

    while(*end++ != '\0');
    end --;

    while(str < end){
        temp = *str;
        *str++ = *end;
        *end-- = temp;
    }
}

//
// swap
//
void swap(int* a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;

    //
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}