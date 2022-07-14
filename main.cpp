#include <iostream>
#include "Solutions/剑指 Offer 56 - I.h"

int main() {
//    vector<vector<int>> board{vector<int>{1,0}};
    Solution solution;
    vector<vector<char>> vec1 {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    vector<int> vec2{1,2,5,2};

    vector<string> vecstr{"4","2","5","1","3","null","null"};
//    vector<int> res = solution.singleNumbers(vec2);

    string data = "1,2,3,null,null,4,5,null,null,null,null";
    vector<string> strList;
    string delimiter = ",";
    int pos;
    while ((pos = data.find(delimiter)) != string::npos) {
        strList.push_back(data.substr(0, pos));
        data.erase(0, pos + delimiter.length());
    }

    for(int i =0; i < strList.size(); ++i){
        cout<< strList[i]<<endl;
    }

    return 0;
}
