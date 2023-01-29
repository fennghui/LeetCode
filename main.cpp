#include <iostream>
#include "2nd/1124. 表现良好的最长时间段.h"

int main() {


    Solution solution;
    vector<int> vec2{6,9,9};
    vector<string> vecStr{"leet","code"};
    string num1("123");
    string num2("456");
    vector<vector<int>> vec3{{1,2,3},{4,5,6},{7,8,9}};
    auto result = solution.longestWPI(vec2);
    cout<<result<<endl;

//    for (int i = 0; i < result.size(); ++i){
//        cout<<result[i]<<endl;
//    }

//    for (int i = 0; i < result.size(); ++i){
//        for(int j=0;j<result[i].size();j++){
//            cout<<result[i][j]<<" ";
//        }
//        cout<<endl;
//    }


    return 0;
}
