#include <iostream>
#include "2nd/56. 合并区间.h"

int main() {


    Solution solution;
    vector<int> vec2{1000000000,1000000000,1000000000,1000000000,-1000000000,-1000000000,-1000000000,-1000000000};
    vector<string> vecStr{"leet","code"};
    string num1("123");
    string num2("456");
    vector<vector<int>> vec3{{0,0},{1,2},{5,5},{2,4},{3,3},{5,6},{5,6},{4,6},{0,0},{1,2},{0,2},{4,5}};
    auto result = solution.merge(vec3);
//    cout<<result<<endl;

//    for (int i = 0; i < result.size(); ++i){
//        cout<<result[i]<<endl;
//    }

    for (int i = 0; i < result.size(); ++i){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}
