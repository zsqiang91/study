#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;

//
// 字符串匹配算法
//

// hancart
bool hancart(string pstr, string tstr){
    int equal, diff;

    if(pstr[0] == pstr[1]){
        equal = 1;
        diff = 2;
    }
    else {
        equal = 2;
        diff = 1;
    }

    int i=0;
    while(i <= tstr.size() - pstr.size()){
        if(tstr[i+1] != pstr[1]){
             i += diff;
        }
        else{
            int j=1;
            while(j<pstr.size() && pstr[j] == tstr[i+j]) j++;
            if(j == pstr.size() && tstr[i] == pstr[0]) return true;
             i += equal;
        }
    }
    return false;
}

// KMP

void find_next(string pstr, vector<int> &next){
    next[0] = -1;
    int i=0, j=-1;
    while(i < pstr.size()-1){
        if(j == -1 || pstr[i] == pstr[j]){
            next[++i] = ++j;
        }
        else j = next[j];
    }
}

bool kmp(string pstr, string tstr){
    vector<int> next(pstr.size());
    int i=0, j=0;
    find_next(pstr, next);
    while(i<tstr.size() && j<(int)pstr.size()){
        if(j==-1 || tstr[i] == pstr[j]){
            i++;
            j++;
        }
        else j = next[j];
    }
    if(j == pstr.size()) return true;
    return false;
}

bool checkReverseEqual(string s1, string s2) {
    // write code here
    if(s1.size() != s2.size()) return false;
    if(s1.size() == 1) return s1 == s2;

    string str = s1 + s1;
    return hancart(s2, str);
}