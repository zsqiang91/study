#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;

//
// 方法一
// 借鉴双指针技术
//
string zipString(string iniString) {
    // write code here
    int first, second;
    stringstream sout;

    first = second = 0;
    while(first < iniString.size()){
        while(first < iniString.size() && iniString[first] == iniString[second]) first++;
        sout << iniString[second] << first - second;
        second = first;
    }

    return sout.str().size() > iniString.size() ? iniString : sout.str();
}