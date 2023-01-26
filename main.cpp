#include <iostream>
#include "2nd/43. 字符串相乘.h"

int main() {


    Solution solution;
    vector<int> vec2{1000000000,1000000000,1000000000,1000000000,-1000000000,-1000000000,-1000000000,-1000000000};
    vector<string> vecStr{"leet","code"};
    string num1("123");
    string num2("456");
    auto result = solution.multiply(num1,num2);
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
