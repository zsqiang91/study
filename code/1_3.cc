#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//
//  方法一
//  统计两个字符串的每个字符的个数，如果个数不同就一定不是
//
bool checkSam(string stringA, string stringB) {
    // write code here
    char char_set[256] = {0};
    
    for(int i=0; i<stringA.size(); i++){
        char_set[stringA[i]]++;
    }

    for(int i=0; i<stringB.size(); i++){
        if(char_set[stringB[i]] == 0) return false;
        else char_set[stringB[i]] --;
    }

    return true;
}

//
// 方法二
// 对字符串进行排序，然后在进行比较
//
bool checkSam(string stringA, string stringB) {
    // write code here
    sort(stringA.begin(), stringA.end());
    sort(stringB.begin(), stringB.end());
    
    return stringA == stringB;
}
