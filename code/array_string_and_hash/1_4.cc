#include <string>
#include <vector>
using namespace std;

//
// 方法一
//
string replaceSpace(string iniString, int length) {
    // write code here
    stringstream strout;
        
    // 遍历
    for(int i=0; i<length; i++){
        if(iniString[i] == ' ') strout << "%20";
        else strout << iniString[i];
    }
    
    return strout.str();
}

//
// 方法二
//
void replaceSpace(char *str,int length) {
    if(str == nullptr || length <= 0) return;
    
    int original_length = 0;
    int number_black = 0;
    while(str[original_length] != '\0'){
        if(str[original_length] == ' '){
            number_black++;
        }
        original_length++;
    }
    
    int index_new = original_length + number_black*2 - 1;
    int index_original = original_length - 1;
    str[index_new+1] = '\0';    // 字符串是以0结尾
    while(index_original >= 0 && index_original < index_new){
        if(str[index_original] == ' '){
            str[index_new--] = '0';
            str[index_new--] = '2';
            str[index_new--] = '%';
        }
        else str[index_new--] = str[index_original];
        index_original --;
    }
    return;
}